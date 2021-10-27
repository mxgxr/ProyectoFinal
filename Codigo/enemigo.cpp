#include "enemigo.h"

void Enemigo::setAngulo(double value)
{
    angulo = value;
}

double Enemigo::getPosx() const
{
    return posx;
}

double Enemigo::getPosy() const
{
    return posy;
}

double Enemigo::getMaxX() const
{
    return maxX;
}

double Enemigo::getMinX() const
{
    return minX;
}

double Enemigo::getVidas() const
{
    return vidas;
}

void Enemigo::setVidas()
{
    vidas--;
}

double Enemigo::getAngulo() const
{
    return angulo;
}

Enemigo::Enemigo(double x, double y, double ang, double max, double mix, QPixmap brush, int vid)
{
    this->posx=x;
    this->posy=y;
    this->angulo=(ang*3.141598)/180;
    this->maxX=max;
    this->minX=mix;
    this->vidas=vid;
    this->vel=10;
    enemigoBrush=brush;
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
    posx=posx+vel*dt*cos(angulo);
    //posx=posx+velx*dt;
    //posy=posy+vely*dt-0.5*g*dt*dt;
    setPos(posx,-posy);
}

QRectF Enemigo::boundingRect() const
{
    return QRectF(-25,-25,70,50);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    painter->drawPixmap(boundingRect(), enemigoBrush, enemigoBrush.rect());
}
