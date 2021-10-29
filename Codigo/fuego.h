#ifndef FUEGO_H
#define FUEGO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

#define dt 1

class fuego : public QGraphicsItem
{
    int posx,posy;
    int vel=50;
    double angulo;
public:
    fuego(int x, int y, int a);
    void cPosicion();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // FUEGO_H
