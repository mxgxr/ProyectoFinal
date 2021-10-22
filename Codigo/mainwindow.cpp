#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("RobinHood");
    scene1 = new QGraphicsScene();
    ui->graphicsView->setScene(scene1);
    scene1->setSceneRect(-600,-300,1200,600);
    pared1 = new Pared(0,0);
    QPixmap pintura1(jugador_1),pintura2(jugador_2);
    jugador1= new personajes(10,0,pintura1);
    jugador2= new personajes(50,0,pintura2);
    scene1->addItem(pared1);
    scene1->addItem(jugador1);
    scene1->addItem(jugador2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

