#include "pared.h"

Pared::Pared(int x, int y)
{
    this->posx=x;
    this->posy=y;
    setPos(posx,-posy);
}

QRectF Pared::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(boundingRect());
    /*QPixmap pxMap(":/pacmanlindo.png");
    painter->drawPixmap(boundingRect(), pxMap, pxMap.rect());*/
}
