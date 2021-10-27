#include "personajes.h"

int personajes::getVida() const
{
    return vida;
}

void personajes::setVida()
{
    if(vida-1>=0){
        vida = vida--;
    }
}

personajes::personajes(int x, int y, QPixmap brush, int v)
{
    personajebrush=brush;

    this->vida=v;

    posy=y;

    setPos(x,y);
}
QRectF personajes::boundingRect() const
{
    return QRectF(-5,-5,35,50);
}

void personajes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    painter->drawPixmap(boundingRect(), personajebrush, personajebrush.rect());
}
void personajes::arriba(){
    posy-=6;
}
void personajes::abajo(){
    posy+=8;
}
