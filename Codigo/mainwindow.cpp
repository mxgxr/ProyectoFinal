#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("The master key");
    users = new Usuarios;
    //QPixmap pintura3(enemigoDere);
    //enemigo1 = new Enemigo(150,-245,180,pintura3);
    ePrincipal();


    //connect(registrar, SIGNAL (&QPushButton::clicked),this, SLOT (&MainWindow::eRegistro()));

/*
    scene9 = new QGraphicsScene();
    ui->graphicsView->setScene(scene9);
    scene9->setSceneRect(-500,-300,1000,600);
    pared1 = new Pared(0,0,50);
    QPixmap pintura1(jugador_1),pintura2(jugador_2);
    jugadores.push_back(jugador1= new personajes(posx1,posy1,pintura1));
    jugadores.push_back(jugador2= new personajes(posx2,posy2,pintura2));
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

    letrero2 = new QImage(":/images/letrero2.jpg");
    scene1->addPixmap(QPixmap::fromImage(*letrero2));
    registrar = new QPushButton("Registrar");
    registrar->setGeometry(350,320,300,50);
    registrar->setStyleSheet("font: 10pt ;" "font: Modern;" "color: rgb(255, 255, 255);" "background-color: rgba(3,112,71,80%);");
    //registrar->setGeometry(QRect(QPoint(0,100), QSize(300,100)));
    scene1->addWidget(registrar);
    ingresar = new QPushButton("Ingresar");
    ingresar->setGeometry(QRect(QPoint(350,380), QSize(300,50)));
    ingresar->setStyleSheet("font: 10pt ;" "font: Modern;" "color: rgb(255, 255, 255);" "background-color: rgba(3,112,71,80%);");
    scene1->addWidget(ingresar);
    title1 = new QLabel("Welcome to The master key");
    title1->setGeometry(300,80,600,300);
    title1->setStyleSheet("font: 30pt ;" "font: Modern;" "color: rgb(234, 190, 63);" "background-color: rgba(0,0,0,0%);" "font style: Negrita;");
    //title1->setAlignment(Qt::AlignHCenter);
    scene1->addWidget(title1);


    connect(registrar, SIGNAL (clicked()),this, SLOT (eRegistro()));
    connect(ingresar, SIGNAL (clicked()),this, SLOT (eInicio()));
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

void MainWindow::movEnemigo()
{
    QPixmap pintura3(enemigoDere), pintura4(enemigoIzq);
    QVector<Enemigo*>::iterator iter;
    for(iter=enemigos1.begin(); iter!=enemigos1.end(); iter++){
        if((*iter)->getPosx()+5>=(*iter)->getMaxX()){
            (*iter)->setAngulo(180);
            //(*iter)->cVelocidad();
            (*iter)->cPosicion();
            (*iter)->enemigoBrush=pintura4;
        }
        else if((*iter)->getPosx()-5<=(*iter)->getMinX()){
            (*iter)->setAngulo(0);
            //(*iter)->cVelocidad();
            (*iter)->cPosicion();
            (*iter)->enemigoBrush=pintura3;
        }
        else{
            //(*iter)->cVelocidad();
            (*iter)->cPosicion();
        }
    }
}

void MainWindow::movResorte()
{
    //QTime time = QTime::currentTime();
    //double tiempo=time.toString().toDouble();
    resorte1->cPosicion(tiempo);
    tiempo++;
}

bool MainWindow::colParedes(QGraphicsItem *elemento)
{
    QList<Pared*>::Iterator it;
    for(it=paredes.begin();it!=paredes.end();it++){
        if((*it)->collidesWithItem(elemento)){
            return true;
        }
    }
    return false;
}

void MainWindow::eRegistro()
{
    ventana1 = new Dialog(this);
    ventana1->setModal(true);

    ventana1->show();
    connect(ventana1, SIGNAL (back()),this, SLOT (funcRegistro()));

    /*scene3 = new QGraphicsScene();

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



    connect(aceptarR, SIGNAL (clicked()),this, SLOT (funcRegistro()));*/
}

void MainWindow::funcRegistro()
{
    ventana1->close();
    regist = new QLabel();
    regist->setGeometry(0,0,300,100);
    scene1->addWidget(regist);
    if(users->Registrar(ventana1->getUsuario(),ventana1->getContra())){
        regist->setText("Usuario registrado correctamente");
    }
    else {
        regist->setText("No se pudo registrar correctamente");
    }


}

void MainWindow::eInicio()
{
    ventana2 = new Dialog(this);
    ventana2->setModal(true);

    ventana2->show();
    connect(ventana2, SIGNAL (back()),this, SLOT (funcAcceder()));

}

void MainWindow::funcAcceder()
{
    ventana2->close();
    regist = new QLabel();
    string level;
    regist->setGeometry(0,0,300,100);
    scene1->addWidget(regist);
    if(users->Validar(ventana2->getUsuario(),ventana2->getContra())){
        level=users->getLevel(ventana2->getUsuario());
        if(level=="1"){
            level1();
        }
        else if (level=="2"){
            level2();
        }
    }
    else{
        regist->setText("No se pudo acceder correctamente");
    }

}

void MainWindow::level1()
{
    timer = new QTimer(this);
    timer->start(10);
    timer2 = new QTimer(this);
    timer2->start(1000);

    scene4 = new QGraphicsScene();
    ui->graphicsView->setScene(scene4);
    scene4->setSceneRect(-500,-300,1000,600);
    scene4->setBackgroundBrush(Qt::darkGreen);

    loadLevel("../level1.txt",scene4);

    QPixmap pintura1(jugador_1),pintura2(jugador_2),pintura3(enemigoDere),pintura4(enemigoIzq);
    jugador1 = new personajes(-455,-220,pintura1);
    jugador2 = new personajes(-395,-220,pintura2);
    scene4->addItem(jugador1);
    scene4->addItem(jugador2);

    enemigos1.push_back(new Enemigo(150,-245,180,150,-430,pintura3));
    scene4->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-215,55,0,120,-215,pintura4));
    scene4->addItem(enemigos1.back());

    resorte1 = new Resorte(385,-150,60);
    scene4->addItem(resorte1);

    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo()));
    //connect(timer2,SIGNAL(timeout()),this,SLOT(movResorte()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(ene1()));


    ui->graphicsView->show();
}

void MainWindow::level2()
{
    scene5 = new QGraphicsScene();
    ui->graphicsView->setScene(scene5);
    scene5->setSceneRect(-500,-300,1000,600);

    loadLevel("../level2.txt",scene5);


    QPixmap pintura1(jugador_1),pintura2(jugador_2);
    jugador1= new personajes(10,0,pintura1);
    jugador2= new personajes(50,0,pintura2);
    scene5->addItem(jugador1);
    scene5->addItem(jugador2);
}

void MainWindow::keyPressEvent(QKeyEvent *movimiento){
    QPixmap pintura1(derecha_1),pintura2(izquierda_1),pintura3(derecha_2),pintura4(izquierda_2),pintura5(flechad),pintura6(flechai);
    switch (movimiento->key()) {
    case Qt::Key_A:
    {
        posx1-=5;
        jugador1->personajebrush=pintura2;
        Pos=0;
    }
        break;
    case Qt::Key_D:
    {
        posx1+=5;
        jugador1->personajebrush=pintura1;
        Pos=1;
    }
        break;
    case Qt::Key_H:
    {
        posx2-=5;
        jugador2->personajebrush=pintura4;
        Pos=0;
    }
        break;
    case Qt::Key_K:
    {
        posx2+=5;
        jugador2->personajebrush=pintura3;
        Pos=1;
    }
        break;
    case Qt::Key_F:
    {
        if(Pos==0){
            tirarflecha= new flecha(posx1-35,posy1+25,0);
            tirarflecha->flechabrush=pintura6;
            scene9->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(80);
        }
        else if(Pos==1){
            tirarflecha= new flecha(posx1+35,posy1+25,1);
            tirarflecha->flechabrush=pintura5;
            scene9->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(80);
        }
    }
        break;
    case Qt::Key_G:
    {
        if(Pos==0){
            tirarflecha= new flecha(posx2-35,posy2+25,0);
            tirarflecha->flechabrush=pintura6;
            scene9->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(80);
        }
        else if(Pos==1){
            tirarflecha= new flecha(posx2+35,posy2+25,1);
            tirarflecha->flechabrush=pintura5;
            scene9->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(80);
        }
    }
        break;
    }
    jugador1->setPos(posx1,posy1);
    jugador2->setPos(posx2,posy2);
}
void MainWindow::movimientoflecha(){
    tirarflecha->calcularPos();
    if(tirarflecha->posy>tirarflecha->Yinicial){
        flecham->stop();
        tirarflecha->hide();
    }
}
