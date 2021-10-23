#include "flecha.h"

flecha::flecha(int x, int y)
{
    setPos(x,y);
}
QRectF flecha::boundingRect() const
{
    return QRectF(-5,-5,30,10);
}

void flecha::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    QPixmap flechabrush(":/images/flecha.png");
    painter->drawPixmap(boundingRect(), flechabrush, flechabrush.rect());
}
