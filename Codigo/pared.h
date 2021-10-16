#ifndef PARED_H
#define PARED_H

#include <QGraphicsItem>
#include <QPainter>

class Pared : public QGraphicsItem
{
public:
    int posx,posy;
    Pared(int x, int y);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PARED_H
