#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
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

#include "dialog.h"
#include "pared.h"
#include "usuarios.h"
#include "resorte.h"
#include "enemigo.h"
#include "personajes.h"
#include "flecha.h"
#include "llave.h"
#include "puerta.h"

#define jugador_1 ":/jugadores/sprites/1personaje.png"
#define jugador_2 ":/jugadores/sprites/2personaje.png"
#define derecha_1 ":/jugadores/sprites/1flechad.png"
#define izquierda_1 ":/jugadores/sprites/1flechai.png"
#define derecha_2 ":/jugadores/sprites/2flechad.png"
#define izquierda_2 ":/jugadores/sprites/2flechai.png"
#define flechad ":/images/flecha.png"
#define flechai ":/images/flecha2.png"
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
    void ePrincipal();
    void loadLevel(QString ruta, QGraphicsScene *escena);
    bool colParedes(QGraphicsItem *elemento);

public slots:

private slots:
    void eRegistro();
    void funcRegistro();
    void eInicio();
    void funcAcceder();
    void ene1();
    void movEnemigo();
    void level1();
    void movimientoflecha();//aplicar movimiento parabolico
    //void movimientollave();//aplicar movimiento circular
    void level2();
   // void level3();
protected:
     void keyPressEvent(QKeyEvent *movimiento);
private:

    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5, *scene6, *scene7, *scene8, *scene9; //1. inicio(ingresar/registrar) 2.ingresar 3.registrar 4.nivel1 5.nivel2 6.nivel3 7.continuar,salir 8.finalizado el juego
    QImage *letrero2;
    QPushButton *registrar, *ingresar, *aceptarR;
    QLabel *title1, *regist;
    QLineEdit *usuario1, *contra;
    Usuarios *users;
    QList<Pared*>paredes;
    Dialog *ventana1, *ventana2;
    Enemigo *enemigo1, *enemigo2;
    QTimer *timer;
    QVector<Enemigo*>enemigos1;

    Pared *pared1;
    personajes *jugador1,*jugador2;
    flecha *tirarflecha;
    int posx1=10,posy1=0,posx2=50,posy2=0;
    bool Pos;
    QList<personajes*> jugadores;
    QList<personajes*>::iterator pers1,pers2;
    QTimer *flecham;
    llave *key;
    puerta *abrirpuerta;

    Ui::MainWindow *ui;
    //QGraphicsScene *scene9;
};
#endif // MAINWINDOW_H
