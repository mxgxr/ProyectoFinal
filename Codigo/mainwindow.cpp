#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("The master key");
    users = new Usuarios;
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

void MainWindow::colEnemigo(QGraphicsItem *elemento)
{
    QVector<Enemigo*>::iterator iter;

    for(iter=enemigos1.begin();iter!=enemigos1.end();iter++){
        if((*iter)->collidesWithItem(elemento)){
            (*iter)->setVidas();
            if((*iter)->getVidas()==0){
                scene4->removeItem((*iter));
                enemigos1.erase(iter);
            }
        }
    }
}

bool MainWindow::colPersonaje(QGraphicsItem *elemento)
{
    QList<personajes*>::iterator per;
    for(per=jugadores.begin();per!=jugadores.end();per++){
        if((*per)->collidesWithItem(elemento)){
            (*per)->setVida();
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

}

void MainWindow::funcRegistro()
{
    ventana1->close();
    regist = new QLabel();
    regist->setGeometry(0,0,300,100);
    scene1->addWidget(regist);
    if(users->Registrar(ventana1->getUsuario(),ventana1->getContra())){
        regist->setText("Usuario registrado correctamente");
        users->Guardar();
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

    vida1 = new QLCDNumber();
    vida1->setDecMode();
    vida1->setGeometry(-500,-255,20,30);
    vida1->setDigitCount(2);
    vida1->setStyleSheet("color: rgb(255, 255, 255);" "background-color: rgba(0,0,0,0%);");
    vida1->show();

    vida2 = new QLCDNumber();
    vida2->setDecMode();
    vida2->setGeometry(-420,-255,20,30);
    vida2->setDigitCount(2);
    vida2->setStyleSheet("color: rgb(255, 255, 255);" "background-color: rgba(0,0,0,0%);");
    vida2->show();

    scene4 = new QGraphicsScene();
    ui->graphicsView->setScene(scene4);
    scene4->setSceneRect(-500,-300,1000,600);
    scene4->setBackgroundBrush(Qt::darkGreen);

    loadLevel("../level1.txt",scene4);

    QPixmap pintura1(jugador_1),pintura2(jugador_2),pintura3(enemigoDere),pintura4(enemigoIzq);
    posx1=-455;
    posy1=220;
    posx2=-395;
    posy2=220;
    jugador1 = new personajes(posx1,posy1,pintura1,10);
    vida1->display(jugador1->getVida());

    jugador2 = new personajes(posx2,posy2,pintura2,10);
    vida2->display(jugador2->getVida());
    key= new llave(-455,220);
    scene4->addItem(jugador1);
    scene4->addItem(jugador2);
    scene4->addWidget(vida1);
    scene4->addWidget(vida2);

    scene4->addItem(key);
    llavem= new QTimer();
    connect(llavem,SIGNAL(timeout()),this,SLOT(movimientollave()));
    llavem->start(30);

    enemigos1.push_back(new Enemigo(150,-245,180,150,-430,pintura3,2));
    scene4->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-215,55,0,120,-215,pintura4,2));
    scene4->addItem(enemigos1.back());

    resorte1 = new Resorte(385,-150,60);
    scene4->addItem(resorte1);

    puerta1 = new puerta(340,230);
    scene4->addItem(puerta1);

    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(movResorte()));
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
    jugador1= new personajes(10,0,pintura1,12);
    jugador2= new personajes(50,0,pintura2,12);
    scene5->addItem(jugador1);
    scene5->addItem(jugador2);
}

void MainWindow::keyPressEvent(QKeyEvent *movimiento){
    QPixmap pintura1(derecha_1),pintura2(izquierda_1),pintura3(derecha_2),pintura4(izquierda_2);
    switch (movimiento->key()) {
    case Qt::Key_A:
    {
        posx1-=5;
        jugador1->personajebrush=pintura2;
        if(colParedes(jugador1)){
            posx1+=10;
        }
        Pos=0;
    }
        break;
    case Qt::Key_D:
    {
        posx1+=5;
        jugador1->personajebrush=pintura1;
        if(colParedes(jugador1)){
            posx1-=10;
        }
        Pos=1;
    }
        break;
    case Qt::Key_H:
    {
        posx2-=5;
        jugador2->personajebrush=pintura4;
        if(colParedes(jugador2)){
            posx2+=10;
        }
        Pos=0;
    }
        break;
    case Qt::Key_K:
    {
        posx2+=5;
        jugador2->personajebrush=pintura3;
        if(colParedes(jugador2)){
            posx2-=10;
        }
        Pos=1;
    }
        break;
    case Qt::Key_W:
    {
        direccion=true;
        limite=posy1-30;
        salto=new QTimer(this);
        connect(salto,SIGNAL(timeout()),this,SLOT(saltopersonaje1()));
        salto->start(80);
    }
        break;
    case Qt::Key_U:
    {
        direccion=true;
        limite=posy2-30;
        salto=new QTimer(this);
        connect(salto,SIGNAL(timeout()),this,SLOT(saltopersonaje2()));
        salto->start(80);
    }
        break;
    case Qt::Key_F:
    {
        if(Pos==0){
            tirarflecha= new flecha(posx1-60,posy1+25,0);
            scene4->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));

            //connect(flecham, SIGNAL(timeout()),this,SLOT(movFuego()));
            flecham->start(50);

          

        }
        else if(Pos==1){
            tirarflecha= new flecha(posx1+60,posy1+25,1);
            scene4->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));

            //connect(flecham, SIGNAL(timeout()),this,SLOT(movFuego()));
            flecham->start(50);

           

        }
    }
        break;
    case Qt::Key_G:
    {
        if(Pos==0){
            tirarflecha= new flecha(posx2-60,posy2+25,0);
            scene4->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));

            //connect(flecham, SIGNAL(timeout()),this,SLOT(movFuego()));
            flecham->start(50);

            

        }
        else if(Pos==1){
            tirarflecha= new flecha(posx2+60,posy2+25,1);
            scene4->addItem(tirarflecha);
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));

            //connect(flecham, SIGNAL(timeout()),this,SLOT(movFuego()));
            flecham->start(50);

         

        }
    }
        break;
    }
    jugador1->setPos(posx1,posy1);
    jugador2->setPos(posx2,posy2);
}

void MainWindow::movimientoflecha(){
    tirarflecha->calcularPos();
    colEnemigo(tirarflecha);
    colPersonaje(tirarflecha);
    if(tirarflecha->Yfinal>tirarflecha->Yinicial){
        flecham->stop();
        tirarflecha->hide();
    }
}


void MainWindow::movFuego()
{
    QVector<Enemigo*>::iterator iter;
    for(iter=enemigos1.begin(); iter!=enemigos1.end(); iter++){
        fuegos.push_back(new fuego((*iter)->getPosx(),(*iter)->getPosy(),(*iter)->getAngulo()));
        scene4->addItem(fuegos.back());
    }
    QVector<fuego*>::iterator it;
    for(it=fuegos.begin(); it!=fuegos.end(); it++){
        (*it)->cPosicion();
        if(colPersonaje((*it))){
            scene4->removeItem((*it));
            fuegos.erase(it);
        }
        else if(colParedes((*it))){
            scene4->removeItem((*it));
            fuegos.erase(it);
        }
    }
}

void MainWindow::movimientollave()
{
    key->movimiento();
}
void MainWindow::saltopersonaje1(){
    if(direccion){
        jugador1->arriba();
        posy1=jugador1->posy;
        jugador1->setPos(posx1,posy1);
        if(colParedes(jugador1)){
            direccion=false;
        }
        else if(posy1==limite){
            direccion=false;
        }
    }
    else if(!direccion){
        jugador1->abajo();
        posy1=jugador1->posy;
        jugador1->setPos(posx1,posy1);
        if(colParedes(jugador1)){
            salto->stop();
        }
    }
}
void MainWindow::saltopersonaje2(){
    if(direccion){
        jugador2->arriba();
        posy2=jugador2->posy;
        jugador2->setPos(posx2,posy2);
        if(colParedes(jugador2)){
            direccion=false;
        }
        else if(posy2==limite){
            direccion=false;
        }
    }
    else if(!direccion){
        jugador2->abajo();
        posy2=jugador2->posy;
        jugador2->setPos(posx2,posy2);
        if(colParedes(jugador2)){
            salto->stop();
        }
    }
}
