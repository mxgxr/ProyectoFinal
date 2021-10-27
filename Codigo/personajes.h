#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>

class personajes:public QGraphicsItem
{ 
public:
    int posx,posy,vida;
    QPixmap personajebrush;
    personajes(int,int,QPixmap,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getVida() const;
    void setVida();
};

#endif // PERSONAJES_H
