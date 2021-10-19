#include "resorte.h"

Resorte::Resorte(int x, int y, int a)
{
    this->posx=x;
    this->posy=y;
    this->amplitud=a;
    setPos(posx,-posy);
}

void Resorte::cPosicion()
{
    posx=amplitud*cos(dt*sqrt(k/masa));
    setPos(posx,-posy);
}

void Resorte::cVelocidad()
{
    velx=-1*amplitud*sqrt(k/masa)*sin(dt*sqrt(k/masa));
}

void Resorte::cAceleracion()
{
    acex=-1*amplitud*k/masa*cos(dt*sqrt(k/masa));
}
