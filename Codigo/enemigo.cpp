#include "enemigo.h"

Enemigo::Enemigo(double x, double y, double ang)
{
    this->posx=x;
    this->posy=y;
    this->angulo=ang;
    this->vel=0;
    setPos(posx,-posy);
}

void Enemigo::cVelocidad()
{
    velx=vel*cos(angulo);
    vely=vel*sin(angulo)-g*dt;
    vel=sqrt(pow(velx,2)+pow(vely,2));
    if(velx!=0){
        angulo=atan2(vely,velx);
    }
}

void Enemigo::cPosicion()
{
    posx=posx+velx*dt;
    posy=posy+vely*dt-0.5*g*dt*dt;
    setPos(posx,-posy);
}

QRectF Enemigo::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
