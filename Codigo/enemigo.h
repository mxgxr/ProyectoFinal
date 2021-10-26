#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>

#define g 1
#define dt 0.5

class Enemigo : public QGraphicsItem, public QObject
{
private:
    double posx,posy,vel,velx,vely,angulo,maxX,minX;
public:
    QPixmap enemigoBrush;
    Enemigo(double x, double y, double ang, double max, double mix, QPixmap brush);
    void cVelocidad();
    void cPosicion();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setAngulo(double value);
    double getPosx() const;
    double getPosy() const;
    double getMaxX() const;
    double getMinX() const;
};

#endif // ENEMIGO_H
