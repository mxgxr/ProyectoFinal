#include "llave.h"

llave::llave(int x, int y)
{
    posx=x;
    posy=y;
    grados=0.0f;
    A=20;
    setPos(posx,posy);
}
QRectF llave::boundingRect() const
{
    return QRectF(-5,-5,50,35);
}

void llave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    QPixmap llavebrush(":/images/llave.png");
    painter->drawPixmap(boundingRect(), llavebrush, llavebrush.rect());
}
void llave::movimiento(){
    radianes=qDegreesToRadians(grados);
    grados+=5;
    setPos(posx+A*qCos(radianes),posy+A*qSin(radianes));
}
