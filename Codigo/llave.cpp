#include "llave.h"

llave::llave(int x, int y)
{
    posx=x;
    posy=y;
    setPos(posx,posy);
}
QRectF llave::boundingRect() const
{
    return QRectF(-5,-5,35,20);
}

void llave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    QPixmap llavebrush(":/images/llave.png");
    painter->drawPixmap(boundingRect(), llavebrush, llavebrush.rect());
}
