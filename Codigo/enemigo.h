#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsItem>
#include <QPainter>

#define g 10
#define dt 0.001

class Enemigo : public QGraphicsItem
{
private:
    double posx,posy,vel,velx,vely,angulo;
public:
    Enemigo(double x, double y, double ang);
    void cVelocidad();
    void cPosicion();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // ENEMIGO_H
