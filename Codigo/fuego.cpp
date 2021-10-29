#include "fuego.h"

fuego::fuego(int x, int y, int a)
{
    this->posx=x;
    this->posy=y;
    this->angulo=a;
    setPos(posx,-posy);
}

void fuego::cPosicion()
{
    posx=posx+vel*cos(angulo);
    setPos(posx,-posy);
}

QRectF fuego::boundingRect() const
{
    return QRectF(-8,-8,16,16);
}

void fuego::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    QPixmap fuegobrush(":/images/fueguito.png");
    painter->drawPixmap(boundingRect(), fuegobrush, fuegobrush.rect());
}
