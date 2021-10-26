#ifndef LLAVE_H
#define LLAVE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>


class llave:public QGraphicsItem
{
public:
    int posx,posy;
    llave(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // LLAVE_H
