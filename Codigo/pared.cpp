#include "pared.h"

Pared::Pared(int x, int y, int t)
{
    this->posx=x;
    this->posy=y;
    this->tam=t;
    setPos(-posx,-posy);
}

QRectF Pared::boundingRect() const
{
    return QRectF(-tam/2,-tam/2,tam,tam);
}

void Pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::green);
    //painter->drawRect(boundingRect());
    QPixmap pxMap("../images/ladrillos.jpg");
    painter->drawPixmap(boundingRect(), pxMap, pxMap.rect());
}
