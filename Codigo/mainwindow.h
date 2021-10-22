#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include "pared.h"
#include "personajes.h"

#define jugador_1 "../Codigo/sprites/1personaje.png"
#define jugador_2 "../Codigo/sprites//2personaje.png"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Pared *pared1;
    personajes *jugador1,*jugador2;
    Ui::MainWindow *ui;
    QGraphicsScene *scene1;
};
#endif // MAINWINDOW_H
