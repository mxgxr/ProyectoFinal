#ifndef FLECHA_H
#define FLECHA_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>

class flecha : public QGraphicsItem
{
public:
    int posx,posy;
    flecha(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // FLECHA_H
