#include "personajes.h"

personajes::personajes(int x,int y,QPixmap brush)
{
    personajebrush=brush;
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
