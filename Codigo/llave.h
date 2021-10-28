#ifndef LLAVE_H
#define LLAVE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <qmath.h>

class llave:public QGraphicsItem
{
private:
    float radianes,A,grados;
public:
    int pos,posx,posy;
    llave(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void movimiento();
};

#endif // LLAVE_H
