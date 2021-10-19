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
    int posx,posy,amplitud,velx,acex;
public:
    Resorte(int x, int y, int a);
    void cPosicion();
    void cVelocidad();
    void cAceleracion();
};

#endif // RESORTE_H
