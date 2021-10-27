#ifndef FLECHA_H
#define FLECHA_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <qmath.h>
#define flechad ":/images/flecha.png"
#define flechai ":/images/flecha2.png"

class flecha : public QGraphicsItem
{
private:
     float radianes,A,grados;
     int pos;
public:
    double posx,posy,Yinicial,Yfinal;
    flecha(int,int,int);
    QPixmap flechabrush;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void calcularPos();//utilizamos la formula vectorial de la parabola
};

#endif // FLECHA_H
