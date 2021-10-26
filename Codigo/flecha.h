#ifndef FLECHA_H
#define FLECHA_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <math.h>
#define P -30

class flecha : public QGraphicsItem
{
private:
    double verticeH,verticeK,pos;
public:
    double posx,posy,Yinicial;
    flecha(int,int,int);
    QPixmap flechabrush;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void calcularPos();//utilizamos la formula vectorial de la parabola
};

#endif // FLECHA_H
