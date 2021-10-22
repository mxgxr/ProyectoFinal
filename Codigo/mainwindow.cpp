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
   // ePrincipal();

    //connect(registrar, SIGNAL (&QPushButton::clicked),this, SLOT (&MainWindow::eRegistro()));


    scene9 = new QGraphicsScene();
    ui->graphicsView->setScene(scene9);
    scene9->setSceneRect(-500,-300,1000,600);
    pared1 = new Pared(0,0,50);
    QPixmap pintura1(jugador_1),pintura2(jugador_2);
    jugadores.push_back(jugador1= new personajes(posx1,posy1,pintura1));
    jugadores.push_back(jugador2= new personajes(posx2,posy2,pintura2));
    scene9->addItem(pared1);
    scene9->addItem(jugador1);
    scene9->addItem(jugador2);

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

    letrero2 = new QImage(":/images/letrero2.jpg");
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
    connect(ingresar, SIGNAL (clicked()),this, SLOT (level1())); //-------------CAMBIAR
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
    regist = new QLabel();
    regist->setGeometry(400,100,300,100);
    scene3->addWidget(regist);
    if(users->Registrar(usuario1->text().toStdString(),contra->text().toStdString())){
        regist->setText("Usuario registrado correctamente");
    }
    else {
        regist->setText("No se pudo registrar correctamente");
    }
}

void MainWindow::eInicio()
{


}

void MainWindow::level1()
{
    scene4 = new QGraphicsScene();
    ui->graphicsView->setScene(scene4);
    scene4->setSceneRect(-500,-300,1000,600);
    //paredes1.push_back(new Pared(0,0,50));
    //scene4->addItem(paredes1.back());

    paredes1.push_back(new Pared(-475,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-425,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-375,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-325,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-275,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-225,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-175,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-125,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-75,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-25,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(25,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(75,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(125,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(175,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(225,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(275,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(325,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(375,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(425,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,275,50));
    scene4->addItem(paredes1.back());

    paredes1.push_back(new Pared(-475,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-425,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-375,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-325,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-275,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-225,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-175,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-125,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-75,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-25,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(25,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(75,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(125,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(175,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(225,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(275,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(325,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(375,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(425,-275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,-275,50));
    scene4->addItem(paredes1.back());

    paredes1.push_back(new Pared(-475,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,225,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,175,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,125,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,75,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,25,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,-25,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,-75,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,-125,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,-175,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(-475,-225,50));
    scene4->addItem(paredes1.back());

    paredes1.push_back(new Pared(475,275,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,225,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,175,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,125,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,75,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,25,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,-25,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,-75,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,-125,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,-175,50));
    scene4->addItem(paredes1.back());
    paredes1.push_back(new Pared(475,-225,50));
    scene4->addItem(paredes1.back());

    ui->graphicsView->show();
}
void MainWindow::keyPressEvent(QKeyEvent *movimiento){
    QPixmap pintura1(derecha_1),pintura2(izquierda_1),pintura3(derecha_2),pintura4(izquierda_2);
    switch (movimiento->key()) {
    case Qt::Key_A:
    {
        posx1-=5;
        jugador1->personajebrush=pintura2;
    }
        break;
    case Qt::Key_D:
    {
        posx1+=5;
        jugador1->personajebrush=pintura1;
    }
        break;
    case Qt::Key_H:
    {
        posx2-=5;
        jugador2->personajebrush=pintura4;
    }
        break;
    case Qt::Key_K:
    {
        posx2+=5;
        jugador2->personajebrush=pintura3;
    }
        break;
    case Qt::Key_F:
    {
        tirarflecha1= new flecha(posx1+35,posy1);
        scene9->addItem(tirarflecha1);
        /*
        flecham=new QTimer(this);
        connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
        flecham->start(100);
        */
    }
        break;
    case Qt::Key_G:
    {
        tirarflecha2= new flecha(posx2+35,posy2);
        scene9->addItem(tirarflecha2);
    }
        break;
    }
    jugador1->setPos(posx1,posy1);
    jugador2->setPos(posx2,posy2);
}

