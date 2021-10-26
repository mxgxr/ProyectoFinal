#include "flecha.h"

flecha::flecha(int x, int y, int posflecha)
{
    posx=x;
    posy=y;
    pos=posflecha;
    if(pos==1){//cuando pos es 1 indica que la flecha estara dirigida a la derecha
        verticeH=posx+50;//coordenada x del vertice
        verticeK=posy-20;//coordenada y del vertice
    }
    else if(pos==0){
        verticeH=posx-50;//coordenada x del vertice
        verticeK=posy-20;//coordenada y del vertice
    }
    Yinicial=posy;
    setPos(posx,posy);
}
QRectF flecha::boundingRect() const
{
    return QRectF(-5,-5,25,8);
}

void flecha::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    painter->drawPixmap(boundingRect(), flechabrush, flechabrush.rect());
}
void flecha::calcularPos(){
    if(pos==1){
        posx+=2;//avanzamos cada dos pixeles
        posy+=pow(posx-verticeH,2)/(4*P)+verticeK;//ecuacion de la parabola
    }
    else if(pos==0){
        posx-=2;//avanzamos cada dos pixeles
        posy+=pow(posx-verticeH,2)/(4*P)+verticeK;//ecuacion de la parabola
    }
    setPos(posx,posy);
}
