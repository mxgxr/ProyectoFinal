#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("The master key");
    users = new Usuarios;
    //ui->graphicsView->setSceneRect(0,0,1000,600);
    ePrincipal();

    //connect(registrar, SIGNAL (&QPushButton::clicked),this, SLOT (&MainWindow::eRegistro()));

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
    scene1->setSceneRect(0,0,1000,600);

    letrero2 = new QImage("../images/letrero2.jpg");
    scene1->addPixmap(QPixmap::fromImage(*letrero2));
    registrar = new QPushButton("Registrar");
    registrar->setGeometry(200,300,300,100);
    //registrar->setGeometry(QRect(QPoint(0,100), QSize(300,100)));
    scene1->addWidget(registrar);
    ingresar = new QPushButton("Ingresar");
    ingresar->setGeometry(QRect(QPoint(600,300), QSize(300,100)));
    scene1->addWidget(ingresar);
    title1 = new QLabel("Welcome to \n The master key");
    title1->setGeometry(400,100,300,100);
    scene1->addWidget(title1);


    connect(registrar, SIGNAL (clicked()),this, SLOT (eRegistro()));
    connect(ingresar, SIGNAL (clicked()),this, SLOT (eInicio()));
    /*connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));*/
}

void MainWindow::eRegistro()
{

    scene3 = new QGraphicsScene();

    ui->graphicsView->setScene(scene3);

    scene3->setSceneRect(0,0,1000,600);
    scene3->addPixmap(QPixmap::fromImage(*letrero2));
    aceptarR = new QPushButton("Aceptar");
    aceptarR->setGeometry(50,300,200,50);
    scene3->addWidget(aceptarR);
    usuario1 = new QLineEdit();
    usuario1->setGeometry(50,100,100,50);
    usuario1->setMaxLength(10);
    scene3->addWidget(usuario1);
    contra = new QLineEdit();
    contra->setGeometry(50,200,100,50);
    contra->setMaxLength(10);
    scene3->addWidget(contra);
    ui->graphicsView->show();



    connect(aceptarR, SIGNAL (clicked()),this, SLOT (funcRegistro()));
}

void MainWindow::funcRegistro()
{
    if(users->Registrar(usuario1->text().toStdString(),contra->text().toStdString())){

    }
    else {

    }
}

void MainWindow::eInicio()
{

}


