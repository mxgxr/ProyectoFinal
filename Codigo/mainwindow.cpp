#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("The master key");
    ePrincipal();




  /* scene1->setSceneRect(-600,-300,1200,600);
    letrero2 = new QImage("../images/letrero2.jpg");
    scene1->addPixmap(QPixmap::fromImage(*letrero2));
    scene1 = new QGraphicsScene();
    ui->graphicsView->setScene(scene1);
    scene1->setSceneRect(-600,-300,1200,600);
    pared1 = new Pared(0,0);
    scene1->addItem(pared1);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ePrincipal()
{
    scene1 = new QGraphicsScene();
    ui->graphicsView->setScene(scene1);
    ui->graphicsView->show();
    ui->graphicsView->setSceneRect(0,0,1000,600);

    letrero2 = new QImage("../images/letrero2.jpg");
    scene1->addPixmap(QPixmap::fromImage(*letrero2));
    registrar = new QPushButton("Registrar",this);
    registrar->setGeometry(200,300,300,100);
    //registrar->setGeometry(QRect(QPoint(0,100), QSize(300,100)));
    scene1->addWidget(registrar);
    ingresar = new QPushButton("Ingresar",this);
    ingresar->setGeometry(QRect(QPoint(600,300), QSize(300,100)));
    scene1->addWidget(ingresar);
    title1 = new QLabel("Welcome to \n The master key",this);
    title1->setGeometry(400,100,300,100);
}

