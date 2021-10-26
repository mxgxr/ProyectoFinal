#ifndef LLAVE_H
#define LLAVE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>


class llave:public QGraphicsItem
{
private:
    int posx,posy;
public:
    llave(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // LLAVE_H
