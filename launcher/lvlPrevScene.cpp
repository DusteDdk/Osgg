#include <iostream>
#include <fstream>
#include "lvlPrevScene.h"
#include <QLineF>
#include <QVector>

struct pos_s {
  qreal x,y;
  float color[3];
  bool collision;
};

typedef struct pos_s pos_t;

using namespace std;
lvlPrevScene::lvlPrevScene()
{
  setBackgroundBrush(Qt::black);
}

void lvlPrevScene::load(const char* file)
{
  string line;
  ifstream load;
  
  load.open(file);

  if(!load.is_open())
  {
    cout << "could not load '" << file << "'" << endl;
    return;
  }

  int parseState=0, dataNum=0;
 
 pos_t l;
 QVector<pos_t> tp; //temp poly
 QVector< QVector<pos_t> > map; 
 clear();
  
  while(!load.eof())
  {
    getline(load, line);
    if(line == "StartPoly")
    {
      parseState=1;
    } else if(line=="EndPoly")
    {
      parseState=0;
      map.push_back( tp );
      tp.clear();
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
        tp.push_back( l );
        parseState=1;
      } else {
        dataNum++;
        switch(dataNum)
        {
          case 1:
            l.x = atof(line.data());
          break;
          case 2:
            l.y = atof(line.data());
          break;
          case 3:
          l.color[0] = atof(line.data());
          break;
          case 4:
          l.color[1] = atof(line.data());
          break;
          case 5:
          l.color[2] = atof(line.data());
          break;
          case 6:
          l.collision = atoi(line.data());
          break;
        }
      }
    }
  } //while
  
  load.close();
  
  //Biggest, Smallest pos
  pos_t b,s;
  b.x=0;
  b.y=0;
  s = b;
  
  qreal x,y;
  float c=0;
  bool start;
  QPen pen(0xff00ff00);
  
  for( QVector< QVector<pos_t> >::iterator it = map.begin() ;  it < map.end() ; ++ it)
  {
    //poly
    start=1;

    c=0;
    for( QVector<pos_t>::iterator pit = it->begin() ; pit < it->end() ; ++ pit)
    {
        
        /* Find smallest and biggest points */
        if(pit->x > b.x)
        {
          b.x = pit->x;
        } else if(pit->x < s.x)
        {
          s.x = pit->x;
        }
        if(pit->y > b.y)
        {
          b.y = pit->y;
        } else if(pit->y < s.y)
        {
          s.y = pit->y;
        }
        
        //Add polys
        if(start)
        {
          start=0;
        } else {
          if( c !=-1 && pit->color[0] != -1 )
          {
            addLine(x,y,pit->x,pit->y,pen);
          }
        }
        x=pit->x;
        y=pit->y;
        c=pit->color[0];

    }
  }
  cout << sceneRect().width() << "x" << sceneRect().height() << endl;
  
  
}