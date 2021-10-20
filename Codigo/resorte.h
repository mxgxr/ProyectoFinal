#ifndef RESORTE_H
#define RESORTE_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

#define dt 0.001
#define masa 5
#define k 1


class Resorte : public QGraphicsItem
{
private:
    int posx,posy,amplitud,velx,acex,fuerza;
public:
    Resorte(int x, int y, int a);
    void cPosicion();
    void cVelocidad();
    void cAceleracion();
    void cFuerza();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // RESORTE_H
