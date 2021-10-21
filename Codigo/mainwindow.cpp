#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("The master key");
    scene1 = new QGraphicsScene();
    ui->graphicsView->setScene(scene1);
    scene1->setSceneRect(-600,-300,1200,600);
    letrero2 = new QImage("images/letrero2.jpg");
    scene1->addPixmap(QPixmap::fromImage(*letrero2));
  /*  scene1 = new QGraphicsScene();
    ui->graphicsView->setScene(scene1);
    scene1->setSceneRect(-600,-300,1200,600);
    pared1 = new Pared(0,0);
    scene1->addItem(pared1);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

