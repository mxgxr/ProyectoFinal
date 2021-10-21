#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "pared.h"

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
    void eRegistro();
    void eInicio();
    void level1();
    void level2();
    void level3();


private slots:

private:
    QGraphicsScene *scene1, *scene2, *scena3, *scena4, *scena5, *scena6, *scene7, *scene8; //1. inicio(ingresar/registrar) 2.ingresar 3.registrar 4.nivel1 5.nivel2 6.nivel3 7.continuar,salir 8.finalizado el juego
    QImage *letrero2;
    QPushButton *registrar, *ingresar;
    QLabel *title1;
    Pared *pared1;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
