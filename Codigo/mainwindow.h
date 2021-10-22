#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include <QList>
#include <QVector>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "pared.h"
#include "usuarios.h"
#include "resorte.h"
#include "enemigo.h"

#include <QPixmap>

#include "personajes.h"



#define jugador_1 "../sprites/1personaje.png"
#define jugador_2 "../sprites/2personaje.png"



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

public slots:

private slots:
    void eRegistro();
    void funcRegistro();
    void eInicio();
    void level1();
   // void level2();
   // void level3();

private:

    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5, *scene6, *scene7, *scene8, *scene9; //1. inicio(ingresar/registrar) 2.ingresar 3.registrar 4.nivel1 5.nivel2 6.nivel3 7.continuar,salir 8.finalizado el juego
    QImage *letrero2;
    QPushButton *registrar, *ingresar, *aceptarR;
    QLabel *title1, *regist;
    QLineEdit *usuario1, *contra;
    Usuarios *users;
    QList<Pared*>paredes1;


    Pared *pared1;
    personajes *jugador1,*jugador2;

    Ui::MainWindow *ui;
    //QGraphicsScene *scene9;
};
#endif // MAINWINDOW_H
