#ifndef PACKET_HPP_INCLUDED
#define PACKET_HPP_INCLUDED

typedef struct clientState_s
{
  int32_t id;
  float velX,velY;
  float rot;
  float rotf;
  float posX, posY;
  int8_t shooting;
} clientState_t;

void dumpCS(clientState_t* cs) { printf("Client (%i) State:\n   velX %f\n   velY %f\n   posX %f\n   posY %f\n   rot %f\n   shot %i\n",cs->id, cs->velX,cs->velY,cs->posX,cs->posY,cs->rot, (int)cs->shooting); }

#endif // PACKET_HPP_INCLUDED
