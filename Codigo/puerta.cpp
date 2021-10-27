#include "puerta.h"

puerta::puerta(int x,int y)
{
    posx=x;
    posy=y;
    setPos(posx,-posy);
}
QRectF puerta::boundingRect() const
{
    return QRectF(-30,-25,80,50);
}

void puerta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    QPixmap puertabrush(":/images/puerta.png");
    painter->drawPixmap(boundingRect(), puertabrush, puertabrush.rect());
}
