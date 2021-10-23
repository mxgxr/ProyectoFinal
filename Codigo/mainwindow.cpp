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

/*
    scene9 = new QGraphicsScene();
    ui->graphicsView->setScene(scene9);
    scene9->setSceneRect(-500,-300,1000,600);
    pared1 = new Pared(0,0,50);
    QPixmap pintura1(jugador_1),pintura2(jugador_2);
    jugador1= new personajes(10,0,pintura1);
    jugador2= new personajes(50,0,pintura2);
    scene9->addItem(pared1);
    scene9->addItem(jugador1);
    scene9->addItem(jugador2);*/

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
    connect(ingresar, SIGNAL (clicked()),this, SLOT (level1())); //-------------CAMBIAR
    /*connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));*/
}

void MainWindow::loadLevel(QString ruta, QGraphicsScene *escena)
{
    QFile archivo(ruta);
    QString  strX="", strY="", strTam="";
    int x,y,tam,cont=0;

    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream txtInput(&archivo);
        QString linea;
        while(!txtInput.atEnd()){
            linea=txtInput.readLine();
            for(int i=0; i<linea.size(); i++){
                if(linea[i]!=',' and linea[i]!=';'){
                    if(cont==0){
                        strX+=linea[i];
                    }
                    else if(cont==1){
                        strY+=linea[i];
                    }
                    else if(cont==2){
                        strTam+=linea[i];
                    }
                }
                else if (linea[i]==','){
                    cont++;
                }
                else{
                    cont=0;
                    x=strX.toInt();
                    y=strY.toInt();
                    tam=strTam.toInt();
                    paredes.push_back(new Pared(x,y,tam));
                    escena->addItem(paredes.back());
                    strX="";
                    strY="";
                    strTam="";
                }
            }

        }
    }
}

void MainWindow::eRegistro()
{
   /* Dialog *ventana1 = new Dialog(this);
    ventana1->setModal(true);
    textEdit.
    ventana1->show();
    connect(Dialog::aceptar1, SIGNAL (clicked()),this, SLOT (funcRegistro()));*/

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

    loadLevel("../level1.txt",scene4);

    QPixmap pintura1(jugador_1),pintura2(jugador_2);
    jugador1= new personajes(10,0,pintura1);
    jugador2= new personajes(50,0,pintura2);
    scene4->addItem(jugador1);
    scene4->addItem(jugador2);


    ui->graphicsView->show();
}


