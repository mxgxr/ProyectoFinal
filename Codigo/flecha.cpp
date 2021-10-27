#include "flecha.h"

flecha::flecha(int x, int y, int posflecha)
{
    posx=x;
    posy=y;
    pos=posflecha;
    A=50;
    if(pos==1){//cuando pos es 1 indica que la flecha estara dirigida a la derecha
        grados=180.0f;
    }
    else if(pos==0){//cuando pos es 0 indica que la flecha estara dirigida a la izquierda
        grados=0.0f;
    }
    Yinicial=posy;
    setPos(posx,posy);
}
QRectF flecha::boundingRect() const
{
    return QRectF(-5,-5,40,16);
}

void flecha::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255,255,255,0));
    painter->drawRect(boundingRect());
    painter->drawPixmap(boundingRect(), flechabrush, flechabrush.rect());
}
void flecha::calcularPos(){
    QPixmap pintura5(flechad),pintura6(flechai);
    radianes=qDegreesToRadians(grados);
    if(pos==1){
        grados+=5;
    }
    else if(pos==0){
        grados-=5;
    }
    Yfinal=posy+A*qSin(radianes);
    setPos(posx+A*qCos(radianes),posy+A*qSin(radianes));
    if(pos==1){
        flechabrush=pintura5;
    }
    else if(pos==0){
        flechabrush=pintura6;
    }
}

