#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>

class personajes:public QGraphicsItem
{ 
public:
    int posx,posy;
    QPixmap personajebrush;
    personajes(int,int,QPixmap);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void arriba();
    void abajo();
};

#endif // PERSONAJES_H
