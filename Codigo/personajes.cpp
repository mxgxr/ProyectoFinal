#include "personajes.h"

personajes::personajes(int x,int y,QPixmap brush)
{
    personajebrush=brush;
    setPos(x,-y);
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
