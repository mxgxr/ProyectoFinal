#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QKeyEvent>
#include <QList>
#include <QVector>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <iterator>
#include <QLCDNumber>

#include "dialog.h"
#include "pared.h"
#include "usuarios.h"
#include "resorte.h"
#include "enemigo.h"
#include "personajes.h"
#include "flecha.h"
#include "llave.h"
#include "puerta.h"
#include "fuego.h"

#define jugador_1 ":/jugadores/sprites/1personaje.png"
#define jugador_2 ":/jugadores/sprites/2personaje.png"
#define derecha_1 ":/jugadores/sprites/1flechad.png"
#define izquierda_1 ":/jugadores/sprites/1flechai.png"
#define derecha_2 ":/jugadores/sprites/2flechad.png"
#define izquierda_2 ":/jugadores/sprites/2flechai.png"
#define enemigoDere ":/jugadores/sprites/fantasmader.png"
#define enemigoIzq ":/jugadores/sprites/fantasmaizq.png"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void ePrincipal();
    void eFinLevel();
    void eEndGame();
    void loadLevel(QString ruta, QGraphicsScene *escena);
    bool colParedes(QGraphicsItem *elemento);
    void colEnemigo(QGraphicsItem *elemento, QGraphicsScene *scena);
    bool colPersonaje(QGraphicsItem *elemento);

public slots:

private slots:
    void ePrincipal();
    void eRegistro();
    void funcRegistro();
    void eInicio();
    void funcAcceder();
    void movEnemigo();
    void movResorte();
    void level1();

   
    void movFuego();
   

    void movimientoflecha();//aplicar movimiento semicircular
    void movimientollave();//aplicar movimiento circular
    void saltopersonaje1();
    void saltopersonaje2();

    void level2();
   // void level3();
protected:
     void keyPressEvent(QKeyEvent *movimiento);
private:

    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5, *scene6; //1. inicio(ingresar/registrar) 2.finlevel 3.fingame 4.nivel1 5.nivel2 6.nivel3
    QImage *letrero1, *letrero2;
    QPushButton *registrar, *ingresar, *aceptarR, *salir, *continuar, *abandonar;
    QLabel *title1, *regist, *title2;
    QLineEdit *usuario1, *contra;
    Usuarios *users;
    QList<Pared*>paredes;
    Dialog *ventana1, *ventana2;
    Enemigo *enemigo1, *enemigo2;
    QTimer *timer, *timer2;
    QVector<Enemigo*>enemigos1;
    Resorte *resorte1;
    double tiempo=0, trad;
    puerta *puerta1;
    QVector<fuego*>fuegos;
    QLCDNumber *vida1, *vida2;
    string nomUsuario;

    Pared *pared;
    personajes *jugador1,*jugador2;
    flecha *tirarflecha;
    int posx1,posy1,posx2,posy2,limite;
    bool Pos,direccion;
    QList<personajes*> jugadores;
    QList<personajes*>::iterator pers1,pers2;
    QTimer *flecham;
    QTimer *llavem;
    QTimer *salto;
    llave *key;
    puerta *abrirpuerta;

    Ui::MainWindow *ui;
    //QGraphicsScene *scene9;
};
#endif // MAINWINDOW_H
