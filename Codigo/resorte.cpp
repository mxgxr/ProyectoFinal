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

void Resorte::cFuerza()
{
    fuerza=-1*k*posx;
}

QRectF Resorte::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
