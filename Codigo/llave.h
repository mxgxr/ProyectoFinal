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
    int posx,posy;
    float radianes,A,grados;
public:
    int pos;
    llave(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void movimiento();
};

#endif // LLAVE_H
