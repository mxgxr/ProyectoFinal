#ifndef RESORTE_H
#define RESORTE_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QPixmap>

#define dt 0.01
#define masa 1
#define k 1


class Resorte : public QGraphicsItem
{
private:
    double posx,posy,amplitud,velx,acex,fuerza,posxi;
public:
    Resorte(double x, double y, double a);
    void cPosicion(double t);
    void cVelocidad();
    void cAceleracion();
    void cFuerza();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // RESORTE_H
