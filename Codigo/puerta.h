#ifndef PUERTA_H
#define PUERTA_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>

class puerta:public QGraphicsItem
{
private:
    int posx,posy;
public:
    puerta(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PUERTA_H
