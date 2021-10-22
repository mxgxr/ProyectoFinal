#ifndef PARED_H
#define PARED_H

#include <QGraphicsItem>
#include <QPainter>


class Pared : public QGraphicsItem
{
public:
    int posx,posy,tam;
    Pared(int x, int y, int t);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PARED_H
