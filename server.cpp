/* ************************************************************************* *
    OldSkoolGravityGame (OSGG) Lunar Lander-like game for linux.
    Copyright (C) 2008 Jimmy Christensen ( dusted at dusted dot dk )

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ************************************************************************* */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include <vector>
#include <list>
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>

#include <sys/time.h>

#include "packet.hpp"

#define VERSION "1.0SVN"



#ifndef DATADIR
    #define DATADIR "./"
#endif

using namespace std;

#define THRUSTINCRATE 0.01
#define GRAVITY 0.002
#define TURNINCRATE 0.15

enum entTypes { entLine, entShip, entBase, entWp, entEnemy };
enum gameStateEnum { GameStateEditor, GameStatePlaying, GameStatePause, GameStateQuit, GameStateNewGame, GameStateGameOver, GameStateNextLevel, GameStateStartEditor };
uint gameState = GameStateEditor;


struct pStruct {
  int x,y;
};

string levelFile;

struct glPstruct {
  float x, y;
};

struct structVert {
  float color[3];
  struct glPstruct p;
  int collision; // 0 = none, 1 = normal(damage), 2 = platform/Landing gear
};

typedef struct structVert vert;
typedef struct glPstruct gPs;
typedef struct pStruct pS;

struct structEnt {
  struct glPstruct p; //position
  float rotation; //In DEG
  gPs vel; //Velocity, only used for enemies right now
  gPs baseP; //Base (start) position, used for nme
  int type; //type
  int id;
  bool base; // If it's a base, don't translate it every time..
};
typedef struct structEnt entity;


struct structGameRules {
  int startLevel; //what level to start in
  float maxLandingRotForce;
  float maxLandingYel;
  float maxLandingXvel;
  int fuelConsumptionThrust;
  int fuelConsumptionTurn;
  int fuelMaxFuel;
  int ammoMaxAmmo;
};

struct structGameRules gameRules;

struct gameInfoStruct {
  float thrust;
  float speed; //Relative speed

  gPs velocity;
  float rotationForce;
  float distance;

  int fuel;
  int reloadTime; //After this amount of fames (60th's of 1 sec) player can shoot again
  int ammo;

  gPs radarDest; //Destination for package, points to the base where package should be delivered
  int destBase; // 0 = no package, id of base.
  int numBases; // Number of bases on map, set by loadMap
  int score;
  int numMissions; //number of finished missions
  int level;
  int lives;

  vector<vert> shipVerts;
  vector<vert> baseVerts;
  vector<vert> enemyVerts;

  vector<vert> shipStaticVerts;
  vector<vert> baseStaticVerts;
  vector<vert> enemyStaticVerts;

  vector<int> nextObjective; //Where to deliver to next.
  int currentObjective; //What right now?

};
struct gameInfoStruct gameInfo;

float abs2(float x)
{
      if (x<0) {return -x;}
      return x;
}

bool LinesCross(gPs aLineA, gPs aLineB, gPs bLineA, gPs bLineB)
{
        //First line, first point
        float x0 = aLineA.x;
        float y0 = aLineA.y;
        //First Line, second point
        float x1 = aLineB.x;
        float y1 = aLineB.y;
        //Second Line, First point
        float x2 = bLineA.x;
        float y2 = bLineA.y;
        //Second Line, Second point
        float x3 = bLineB.x;
        float y3 = bLineB.y;


	float d=(x1-x0)*(y3-y2)-(y1-y0)*(x3-x2);
	if (abs2(d)<0.001f) {return 0;}
	float AB=((y0-y2)*(x3-x2)-(x0-x2)*(y3-y2))/d;
	if (AB>0.0 && AB<1.0)
	{
		float CD=((y0-y2)*(x1-x0)-(x0-x2)*(y1-y0))/d;
		if (CD>0.0 && CD<1.0)
                {
                  return 1;
                }
        }

  return 0;
}



struct structShot {
  gPs pa,pb;
  gPs v;
  int age, life;
  bool fromShip; //if 1, wont collide with ship
};

class classBullets {
  private:
  vector<struct structShot> shots;
  public:
  void shoot(entity owner, gPs velocity);
  void render();
  bool col(vector<vert> target, bool isShip);
  void envCol(vector< vector<vert> > polys);
};

void classBullets::envCol(vector< vector<vert> > polys)
{
  for(vector< vector<vert> >::iterator PolyIt = polys.begin(); PolyIt != polys.end(); ++PolyIt)
  {
    classBullets::col(*PolyIt, 0);
  }
}

bool classBullets::col(vector<vert> target, bool isShip)
{
  gPs tLineA, tLineB;
  for(vector<struct structShot>::iterator it = shots.begin(); it != shots.end(); ++it)
  {
    if(it->fromShip != isShip)
    {
      for(int ii=0; ii < target.size(); ii++)
      {
        if(ii==0)
        {
          tLineB = target[ii].p;
        } else {
          tLineA = tLineB;
          tLineB = target[ii].p;

          if(LinesCross(tLineA, tLineB, it->pa, it->pb))
          {
            //Remove bullet.
            it = shots.erase(it);
            return(1);
          }
        }
      }
    }
  }
}

void classBullets::shoot(entity owner, gPs velocity)
{
  struct structShot ts;

  ts.pb = owner.p;
  ts.pa.x = owner.p.x + 6.0* cos( owner.rotation * 0.0174532925 );
  ts.pa.y = owner.p.y + 6.0* sin( owner.rotation * 0.0174532925 );

  ts.v.x = velocity.x + 1.0 * cos( owner.rotation * 0.0174532925 );
  ts.v.y = velocity.y + 1.0 * sin( owner.rotation * 0.0174532925 );

  ts.age = 0;
  ts.life = 40;

  if(owner.type == entShip)
  {
    ts.fromShip=1;
  } else {
    ts.fromShip=0;
  }

  shots.push_back(ts);
}

void classBullets::render()
{

  for(vector<struct structShot>::iterator it = shots.begin(); it != shots.end(); ++it)
  {
    it->pa.x += it->v.x;
    it->pa.y += it->v.y;
    it->pb.x += it->v.x;
    it->pb.y += it->v.y;

    it->age++;
    if(it->age > it->life)
    {
       it = shots.erase(it);
       if(shots.size() < 1)
        break;
    }
  }
}
class classBullets bullets;

//Move and rotate an entity according to ent.p and ent.rotation
void updateEntVerts(entity ent, vector<vert>& entverts, vector<vert> statV )
{
  entverts = statV;

  float tx, ty;

  for(vector<vert>::iterator i = entverts.begin(); i != entverts.end(); ++i)
  {
    tx = i->p.x * cos( (ent.rotation-90.0) * 0.0174532925 ) - ( i->p.y *sin( (ent.rotation-90.0) * 0.0174532925 )) ;
    ty = i->p.x * sin( (ent.rotation-90.0) * 0.0174532925 ) + ( i->p.y *cos( (ent.rotation-90.0) * 0.0174532925 ));
    i->p.x=tx;
    i->p.y=ty;
    i->p.x += ent.p.x;
    i->p.y += ent.p.y;
  }

}


#define PI 3.14159265

void loadMap(vector< vector<vert> >& polys, vector<entity>& ents)
{
  polys.clear();
  ents.clear();
  string line;
  ifstream load;
  vector<vert> tvs; //temp to store the poly as we read it
  vert tv; //temp to store the vert as we read it
  entity te; //temp to store the entity while we read it
  gameInfo.numBases=0;
  gameInfo.nextObjective.clear();
  load.open(levelFile.data());

  if(!load.is_open())
  {
    cout << "could not load '" << levelFile << "'" << endl;
    return;
  }

  int parseState=0, dataNum=0;

  while(!load.eof())
  {
    getline(load, line);
    if(line == "StartPoly")
    {
      parseState=1;
    } else if(line=="EndPoly")
    {
      parseState=0;
      polys.push_back(tvs);
      tvs.clear();
    } else if(parseState==1)
    {
      if(line == "StartVert")
      {
        parseState=2;
        dataNum=0;
      }
    } else if(parseState==2)
    {
      if(line == "EndVert")
      {
        tvs.push_back(tv);
        parseState=1;
      } else {
        dataNum++;
        switch(dataNum)
        {
          case 1:
          tv.p.x = atof(line.data());
          break;
          case 2:
          tv.p.y = atof(line.data());
          break;
          case 3:
          tv.color[0] = atof(line.data());
          break;
          case 4:
          tv.color[1] = atof(line.data());
          break;
          case 5:
          tv.color[2] = atof(line.data());
          break;
          case 6:
          tv.collision = atoi(line.data());
          break;
          default:
          cout << "??" << line << endl;
          break;
        }
      }
    } else if(line =="StartEntity")
    {
      parseState=3;
      dataNum=0;
    } else if(parseState==3)
    {
      if(line=="EndEntity")
      {
        dataNum=0;
        te.baseP = te.p;
        ents.push_back(te);
        parseState=0;
      } else {
        dataNum++;
        switch(dataNum)
        {
          case 1:
            te.p.x = atof(line.data());
            break;
          case 2:
            te.p.y = atof(line.data());
            break;
          case 3:
            te.type = atoi(line.data());
            if(te.type==entBase)
            {
              gameInfo.numBases++;
            }
            break;
          case 4:
            te.rotation = atof(line.data());
            break;
          case 5:
            te.id = atoi(line.data());
            if(te.type==entBase && te.id != gameInfo.numBases)
            {
              cout << "error: base entity have id:" << te.id << " but numBases is:" << gameInfo.numBases << endl;
            }
            break;
          default:
            cout << ">?" << line << endl;
            break;
        }
      }
    } else if(line=="StartMission")
    {
      parseState=4;
    } else if(parseState==4)
    {
      if(line=="EndMission")
      {
        parseState=0;
      } else {
        gameInfo.nextObjective.push_back( atoi(line.data()) );
      }
    }
  }


}

void readEnt(string File, vector<vert>& verts)
{
  string line;
  ifstream f;
  vert tv; //temp to store the vert as we read it

  f.open(File.data());
  if(!f.is_open())
  {
    cout << "Failed to open file" << endl;
    return;
  }

  int parseState=0, dataNum=0;

  while(!f.eof())
  {
    getline(f, line);
    if(line == "StartVert")
    {
      parseState=1;
      dataNum=0;
    } else if(parseState==1)
    {
      if(line == "EndVert")
      {
        parseState=0;
        verts.push_back(tv);
      } else {
        dataNum++;
        switch(dataNum)
        {
          case 1:
          tv.p.x = atof(line.data());
          break;
          case 2:
          tv.p.y = atof(line.data());
          case 3:
          tv.color[0] = atof(line.data());
          break;
          case 4:
          tv.color[1] = atof(line.data());
          break;
          case 5:
          tv.color[2] = atof(line.data());
          break;
          case 6:
          tv.collision = atoi(line.data());
          break;
          default:
          cout << "??" << line << endl;
          break;
        }

      }
    }
  }

}

bool boxCol(gPs posa, gPs posb, float dist)
{
  if(posa.x < posb.x+dist && posa.x > posb.x-dist)
  {
    if(posa.y < posb.y+dist && posa.y > posb.y-dist)
    {
      return(1);
    }
  }
  return(0);
}

bool PolyCol( vector<vert> PolyA, vector<vert> PolyB  )
{
  gPs paLineA, paLineB, pbLineA, pbLineB;
  bool paFirst=1, pbFirst=1;
  int prevColType=0;
  int checks=0;

  for( vector<vert>::iterator paVertIt = PolyA.begin(); paVertIt != PolyA.end(); ++paVertIt)
  {
    if(paVertIt->collision)
    {
      if(paFirst || prevColType == 2) //if the last one was a 2, this one is the start of the next line to collision detect
      {
        paFirst=0;
        paLineB=paVertIt->p;
      } else {
        paLineA=paLineB;
        paLineB=paVertIt->p;


        pbFirst=1;
        //Great now we have a line, lets check it against every line in the other poly.
        for(vector<vert>::iterator pbVertIt = PolyB.begin(); pbVertIt != PolyB.end(); ++pbVertIt)
        {
          if(pbVertIt->collision)
          {
            if(pbFirst)
            {
              pbFirst=0;
              pbLineB=pbVertIt->p;
            } else {
              pbLineA=pbLineB;
              pbLineB=pbVertIt->p;

              //Here we have two lines. paLineA, paLineB, and pbLineA, pbLineB.
              checks++;
              if(LinesCross(paLineA, paLineB, pbLineA, pbLineB))
              {
                return(1);
              }

            }
          }
        }

      }
    }
    prevColType = paVertIt->collision;
  }
  return(0);
}


bool landCol(vector<vert> baseVerts, vector<vert> shipVerts)
{

  gPs baseA, baseB;
  gPs shipA, shipB;
  int prevColType=0;

  //Find points on ship
  for(vector<vert>::iterator shipIt = shipVerts.begin(); shipIt != shipVerts.end(); ++shipIt)
  {
    if(shipIt->collision == 2)
    {
      if(prevColType == 0)
      {
        shipA = shipIt->p;
        prevColType++;
      } else {
        shipB = shipIt->p;
        prevColType++;
      }
    }
  }

  prevColType=0;
  for(vector<vert>::iterator baseIt = baseVerts.begin(); baseIt != baseVerts.end(); ++baseIt)
  {
    //Find the line to check with
    if(prevColType==2)
    {
      baseB = baseIt->p;
      if(shipA.x > baseA.x && shipA.x < baseB.x) //Is left side inside
      {
        if(shipB.x > baseA.x && shipB.x < baseB.x) // Is right side inside
        {
          if(shipA.y < baseA.y && shipB.y < baseB.y) //Is left side under the line
          {
            if(shipB.y < baseA.y && shipB.y < baseB.y) //Is right side under the line
            {
              if(shipA.y > baseA.y-1.0 && shipB.y > baseA.y-1.0) //Check that left side is above the height
              {
                //check velocity:
                //cout << "Impact:"<<endl<<"Xvel:" << gameInfo.velocity.x<<" Yvel: " << gameInfo.velocity.y << endl << "Rot:" << gameInfo.rotationForce << "." << endl;

                if(gameInfo.velocity.y >= gameRules.maxLandingYel) //If it's not smaller, it's not faster
                {
                  float temp = gameInfo.velocity.x;
                  if(temp < 0)
                    temp *= -1.0;

                  if(temp <= gameRules.maxLandingXvel) //it have to be slower
                  {

                    temp = gameInfo.rotationForce;
                    if(temp < 0)
                      temp *= -1.0;
                    if(temp <= gameRules.maxLandingRotForce)
                    {
                      return(1);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    prevColType = baseIt->collision;
    if(prevColType==2)
      baseA = baseIt->p;
  }
  return(0);
}

void setMission(int missionId, vector<entity> ents)
{
  gameInfo.destBase = gameInfo.nextObjective[missionId];

  //Set destination on radar.
  for(vector<entity>::iterator searchIt = ents.begin(); searchIt != ents.end(); ++searchIt)
  {
    if(searchIt->id == gameInfo.destBase)
    {
      gameInfo.radarDest = searchIt->p;
    }
  }
}

void initGame(vector< vector<vert> >& polys, vector<entity>& ents)
{
  loadMap(polys, ents);

  gameInfo.currentObjective=0;
  gameInfo.score=0;
  gameInfo.destBase=0;
  gameInfo.fuel = gameRules.fuelMaxFuel;
  gameInfo.ammo = gameRules.ammoMaxAmmo;

  if(gameInfo.nextObjective.size() > 1)
    setMission(0,ents);



}



void initNewGame(vector< vector<vert> >& polys, vector<entity>& ents)
{
  gameRules.maxLandingRotForce = 1.0; //degrees, both ways
  gameRules.maxLandingYel = -0.20; //downward
  gameRules.maxLandingXvel= 0.15; //both sides
  gameRules.fuelConsumptionThrust = 15;
  gameRules.fuelConsumptionTurn = 4;
  gameRules.fuelMaxFuel = 5500;
  gameRules.ammoMaxAmmo = 1000;


  gameState = GameStatePlaying;

  gameInfo.numMissions=0; //Amount of missions taken
  gameInfo.level=gameRules.startLevel;
  initGame(polys, ents);

}

void shipCrash(entity ship)
{

  gameInfo.velocity.x=0;
  gameInfo.velocity.y=0;
  gameInfo.thrust=0;
  gameInfo.rotationForce=0;
  gameState = GameStateGameOver;

  cout << endl;
  cout << "Dead" << endl;
  cout << "Level "<<gameInfo.level << endl;
}

struct gameInfoStruct snap;


bool parseCmdLine(int argc, char **argv)
{
  bool chosenLevel=0, chosenDemo=0;
  for(int i=1; i < argc; i++)
  {
    if( i == 1)
    {
      if(argv[1][0] != '-')
      {
        gameRules.startLevel = atoi(argv[1]);
        levelFile = DATADIR"levels/";
        levelFile.append(argv[1]);
        levelFile.append(".level");
        chosenLevel=1;
      }
    }

    if( strcmp(argv[i], "--levelfile") == 0 )
    {
      i++;
      if(i > argc)
      {
        cout << "Error: Specify level file." << endl;
        return(0);
      }
      chosenLevel=1;
      levelFile = argv[i];
    } else if(i!=1) {
      cout << "Error: unknown argument '" << argv[i] << "'" << endl;
      return(0);
    }


  }

  return(1);
}

int main(int argc, char **argv)
{

  srand ( time(NULL) );

  /* These can be overwritten by the call to parseCmdLine */
  levelFile = DATADIR"levels/0.level";

  gameState = GameStateNewGame;

  if(!parseCmdLine(argc, argv))
  {
    return(1);
  }

  SDL_Event event;
  //Init sdl and screen
  if(SDL_Init(SDL_INIT_TIMER) <0 )
  {
    cout << SDL_GetError() << endl;
  }




  cout << "Osgg Server"<<endl;
  cout << "Using level file '" << levelFile << "'" << endl;

  int ticks=0, lastTicks=0;


/** GameVars **/

  clientState_t client;
  memset( &client, 0, sizeof(clientState_t) );
  clientState_t client2;
  memset( &client2, 0, sizeof(clientState_t) );
  clientState_t client1;
  memset( &client1, 0, sizeof(clientState_t) );

  vector<vert> testVerts;
  vert tempVert;
  gPs collisionPoint;
  bool crashed=0;
  char score[256];
  vector<entity> ents; //entities
  vector<vert> activeVerts;
  vector< vector<vert> > polys;

  readEnt("ship.txt", gameInfo.shipStaticVerts);
  readEnt("base.txt", gameInfo.baseStaticVerts);
  readEnt("enemy.txt", gameInfo.enemyStaticVerts);

  if(SDLNet_Init()==-1) {
    printf("SDLNet_Init: %s\n", SDLNet_GetError());
    exit(2);
  } else {
    printf("Net initialized..\n");
  }

  //Allocate udp packet

  //Open socket
  UDPsocket udpsock;

  udpsock=SDLNet_UDP_Open(1337);
  if(!udpsock) {
    printf("SDLNet_UDP_Open: %s\n", SDLNet_GetError());
    exit(2);
  } else {
    printf("Listening for UDP connections on port 1337..\n");
  }

  //Allocate a packet
  UDPpacket* packet = SDLNet_AllocPacket( sizeof(clientState_t) );
  UDPpacket* out = SDLNet_AllocPacket( sizeof(int32_t) );

  //Enter Main loop
  int nextId=0;

  printf("Gamestate: %i %i\n", gameState, GameStateNewGame);
  while(gameState != GameStateQuit)
  {

    while(SDL_PollEvent(&event))
    {

    }

    switch(gameState)
    {
      case GameStateNewGame:
        printf("Starting new game..\n");
        initNewGame(polys,ents);
        printf("Started, entering gameloop..\n");
        gameState=GameStatePlaying;
      break;

      case GameStatePlaying:
       // printf("Pretty loopy\n");


      //Incoming data?
      //  printf("Loop start!\n");

      memset( &client1, 0, sizeof(clientState_t) );

        while(SDLNet_UDP_Recv(udpsock, packet)!=0)
        {
        //  printf("Got packet!\n");
        //  printf("Got packet!\n");

          //Accept new clients

          //Delete clients who left

          //Get states from network
          memcpy( &client, packet->data, sizeof(clientState_t) );
 //                   dumpCS( &client);
          if( client.id==1 )
          {
            memcpy( &client1, &client, sizeof(clientState_t) );

            memcpy( packet->data, &client1, sizeof(clientState_t) );
            if( SDLNet_UDP_Send(udpsock, 2, packet )==0 )
            {
           //   printf("Couldn't send data!! =(\n");
            }

          } else if( client.id == 2 )
          {
            memcpy( &client2, &client, sizeof(clientState_t) );
            memcpy( packet->data, &client2, sizeof(clientState_t) );

            if( SDLNet_UDP_Send(udpsock, 1, packet )==0 )
            {
            //  printf("Couldn't send data!! =(\n");
            }
          }

          if( client.id==0 )
          {
            //Reply with next id:
            if(!SDLNet_UDP_Bind(udpsock, ++nextId, &packet->address))
            {
              printf("Error binding..\n");
            }

            out->len=sizeof(int32_t);
            out->channel=nextId;

            memcpy( out->data, &nextId, sizeof(int32_t) );
            if( !SDLNet_UDP_Send(udpsock, nextId, out) )
            {
              printf("Error sending back..\n");
            } else {
              printf("New client added on channel: %i\n", nextId);


              entity tEnt;
              tEnt.p.x=client.posX;
              tEnt.p.y=client.posY;
              tEnt.vel.x=0;
              tEnt.vel.y=0;
              tEnt.baseP = tEnt.p;
              tEnt.type=entShip;
              tEnt.rotation = 90.0;
              tEnt.id = nextId;

              ents.push_back(tEnt);


            }

          } /*else {
            //Tell it about something interesting
            client.posX += 10;
            client.posY += 10;
            int socketChannel = client.id;
            client.id=1;

            memcpy( packet->data, &client, sizeof(clientState_t) );

            if( SDLNet_UDP_Send(udpsock, socketChannel, packet )==0 )
            {
              printf("Couldn't send data!! =(\n");
            }
          }*/


        }


        //Check if any bullets hit the enviroment:
        bullets.envCol(polys);
        bullets.render();

        //Ents:
        for(vector<entity>::iterator it = ents.begin(); it != ents.end(); ++it)
        {
          if(it->type == entShip)
          {




	    //Update the speed
        if( it->id == 1 )
        {
          it->p.x = client1.posX;
          //printf("Posx: %f vs %f\n", client1.posX, it->p.x);
          //printf("Posy: %f\n", client1.posY);
          it->p.y = client1.posY;
          it->vel.x = client1.velX;
          it->vel.y = client1.velY;
          it->rotation = client1.rot;
//          dumpCS(&client1);
          //printf("Updating entity (%f %f) %f..\n", it->id, it->p.x, it->p.y);
            updateEntVerts(*it, gameInfo.shipVerts, gameInfo.shipStaticVerts);

        }
	    gameInfo.speed = abs2(it->vel.x*100)+abs2(it->vel.y*100);
      //printf("Speed: %f\n", gameInfo.speed);
	    //Update velocities
            gameInfo.velocity.x += gameInfo.thrust * cos( (it->rotation*0.0174532925) );
            gameInfo.velocity.y += gameInfo.thrust * sin( (it->rotation*0.0174532925) );

            gameInfo.velocity.y -= GRAVITY;


            if(gameInfo.rotationForce > 0)
            {

              gameInfo.rotationForce /= 1.01;
              if(gameInfo.rotationForce < 0)
              {
                gameInfo.rotationForce = 0;
              }
            } else if(gameInfo.rotationForce < 0)
            {
              gameInfo.rotationForce /= 1.01;
              if(gameInfo.rotationForce > 0)
              {
                gameInfo.rotationForce = 0;
              }
            }

            //Collision with terrain
            for(vector< vector<vert> >::iterator PolyIt = polys.begin(); PolyIt != polys.end(); ++PolyIt)
            {
              if(PolyCol(*PolyIt, gameInfo.shipVerts))
              {
                printf("Client %i crashed into a wall\n", it->id);
                shipCrash(*it);
              }
            }

            crashed=0;
           //Collision with ents
            for(vector<entity>::iterator entIt = ents.begin(); entIt != ents.end(); ++entIt)
            {
              //Collition with entities
              if(entIt->type==entBase)
              {
                updateEntVerts(*entIt, gameInfo.baseVerts, gameInfo.baseStaticVerts);
                crashed=PolyCol(gameInfo.baseVerts, gameInfo.shipVerts);
              } else if(entIt->type==entEnemy)
              {
                updateEntVerts(*entIt, gameInfo.enemyVerts, gameInfo.enemyStaticVerts);
                crashed=PolyCol(gameInfo.enemyVerts, gameInfo.shipVerts);

                //check if this enemy is being hit
                if(bullets.col(gameInfo.enemyVerts, 0))
                {
                  entIt = ents.erase(entIt);
//                   gameInfo.score -= 3000;
                  break;
                }
              }

              if(crashed)
              {
                shipCrash(*it);
              } else {
                //Is he landing on a base?
                if(entIt->type==entBase)
                {
                  if(landCol(gameInfo.baseVerts, gameInfo.shipVerts))
                  {

                    //Subtract 1 from score again
//                     gameInfo.score -= 1;

                    if(gameInfo.fuel < gameRules.fuelMaxFuel)
                    gameInfo.fuel += 15;
                    if(gameInfo.fuel > gameRules.fuelMaxFuel)
                    gameInfo.fuel = gameRules.fuelMaxFuel;

                    if(gameInfo.ammo < gameRules.ammoMaxAmmo)
                    gameInfo.ammo += 3;
                    if(gameInfo.ammo > gameRules.ammoMaxAmmo)
                    gameInfo.ammo = gameRules.ammoMaxAmmo;


                    it->rotation=90.0;

                    if(gameInfo.velocity.y < 0.0)
                      gameInfo.velocity.y=0;

                    gameInfo.velocity.x=0;
                    gameInfo.rotationForce=0;

                    if(gameInfo.numBases > 1)
                    {
                      //Is this the destination base?
                      if(gameInfo.destBase == entIt->id)
                      {

                        gameInfo.numMissions++;

                        //Do he have more missions left?
                        gameInfo.currentObjective++;
                        if(gameInfo.currentObjective < gameInfo.nextObjective.size())
                        {
                          //Give it to him
                          setMission(gameInfo.currentObjective, ents);
                        } else {
                          gameState = GameStateNextLevel;
                        }
                      }
                    }
                  }
                }
              } //not crashing
            }

            it->rotation += gameInfo.rotationForce;
            it->p.x += gameInfo.velocity.x;
            it->p.y += gameInfo.velocity.y;

          } else
          /** Update enemies **/
          if(it->type == entEnemy)
          {
            it->vel.y -= GRAVITY;

            if(it->p.y <= it->baseP.y-0.3)
            {
              it->vel.y += 0.01;
            }
            it->p.y += it->vel.y;
          }
        }



      break;

      /** END OF GAME **/

    }






    ticks += SDL_GetTicks() - lastTicks;
    lastTicks = SDL_GetTicks();
    SDL_Delay(300);
  }

  SDLNet_Quit();
  SDL_Quit();

  return(0);
}
