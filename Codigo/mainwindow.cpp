#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("The master key");
    users = new Usuarios;

    salir = new QPushButton();
    salir->setIcon(QIcon(":/images/botonsalir.png"));
    salir->setIconSize(QSize(40,40));
    regist = new QLabel();
    regist->setGeometry(0,0,300,50);
    regist->setStyleSheet("font: 12pt ;" "font: Modern;" "color: rgb(255, 0, 0);" "background-color: rgba(0,0,0,0%);");

    vida1 = new QLCDNumber();
    vida1->setDecMode();
    vida1->setGeometry(-430,-255,20,30);
    //vida1->setDigitCount(2);
    vida1->setStyleSheet("color: rgb(255, 255, 255);" "background-color: rgba(0,0,0,0%);");
    vida1->show();

    vida2 = new QLCDNumber();
    vida2->setDecMode();
    vida2->setGeometry(-350,-255,20,30);
    //vida2->setDigitCount(2);
    vida2->setStyleSheet("color: rgb(255, 255, 255);" "background-color: rgba(0,0,0,0%);");
    vida2->show();


    ePrincipal();


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



    scene1->addWidget(regist);


    connect(registrar, SIGNAL (clicked()),this, SLOT (eRegistro())); //eRegistro
    connect(ingresar, SIGNAL (clicked()),this, SLOT (eInicio())); //eInicio
    /*connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));*/
}

void MainWindow::eFinLevel()
{
    scene2 = new QGraphicsScene();

    ui->graphicsView->setScene(scene2);
    ui->graphicsView->show();
    scene2->setSceneRect(0,0,1000,600);

    letrero1 = new QImage(":/images/letrero2.jpg");
    scene2->addPixmap(QPixmap::fromImage(*letrero1));

    continuar = new QPushButton("Continuar");
    continuar->setGeometry(350,320,300,50);
    continuar->setStyleSheet("font: 10pt ;" "font: Modern;" "color: rgb(255, 255, 255);" "background-color: rgba(3,112,71,80%);");
    //registrar->setGeometry(QRect(QPoint(0,100), QSize(300,100)));
    scene2->addWidget(continuar);

    abandonar = new QPushButton("Salir");
    abandonar->setGeometry(QRect(QPoint(350,380), QSize(300,50)));
    abandonar->setStyleSheet("font: 10pt ;" "font: Modern;" "color: rgb(255, 255, 255);" "background-color: rgba(3,112,71,80%);");
    scene2->addWidget(abandonar);

    title2 = new QLabel("Nivel superado");
    title2->setGeometry(300,80,600,50);
    title2->setStyleSheet("font: 30pt ;" "font: Modern;" "color: rgb(234, 190, 63);" "background-color: rgba(0,0,0,0%);" "font style: Negrita;");
    scene2->addWidget(title2);

    ui->graphicsView->show();

    connect(abandonar, SIGNAL (clicked()),this, SLOT (ePrincipal()));

    if(users->getLevel(ventana2->getUsuario())=="1"){
        users->setLevel(ventana2->getUsuario(),"2");
        users->Guardar();
        connect(continuar, SIGNAL (clicked()),this, SLOT (level2()));
    }
    else if(users->getLevel(ventana2->getUsuario())=="2"){
        users->setLevel(ventana2->getUsuario(),"3");
        users->Guardar();
        connect(continuar, SIGNAL (clicked()),this, SLOT (level3()));
    }

}

void MainWindow::eEndGame()
{
    scene3 = new QGraphicsScene();

    ui->graphicsView->setScene(scene3);
    ui->graphicsView->show();
    scene3->setSceneRect(0,0,1000,600);

    letrero1 = new QImage(":/images/letrero2.jpg");
    scene3->addPixmap(QPixmap::fromImage(*letrero1));


    abandonar = new QPushButton("Salir");
    abandonar->setGeometry(QRect(QPoint(350,380), QSize(300,50)));
    abandonar->setStyleSheet("font: 10pt ;" "font: Modern;" "color: rgb(255, 255, 255);" "background-color: rgba(3,112,71,80%);");
    scene3->addWidget(abandonar);

    title2 = new QLabel("Fin del juego");
    title2->setGeometry(300,80,600,50);
    title2->setStyleSheet("font: 30pt ;" "font: Modern;" "color: rgb(234, 190, 63);" "background-color: rgba(0,0,0,0%);" "font style: Negrita;");
    scene3->addWidget(title2);

    users->setLevel(ventana2->getUsuario(),"4");
    users->Guardar();


    connect(abandonar, SIGNAL (clicked()),this, SLOT (ePrincipal()));

}

void MainWindow::loadLevel(QString ruta, QGraphicsScene *escena)
{
    enemigos1.clear();
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
    if(tiempo<=162){
        tiempo+=18;
    }
    else{
        tiempo=0;
    }
    trad=qDegreesToRadians(tiempo);
    resorte1->cPosicion(trad);
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

bool MainWindow::colEnemigo(QGraphicsItem *elemento, QGraphicsScene *scena)
{
    QVector<Enemigo*>::iterator iter;
    int cont=0;
    for(iter=enemigos1.begin();iter!=enemigos1.end();iter++){
        cont++;
        if((*iter)->collidesWithItem(elemento)){
            (*iter)->setVidas();
            if((*iter)->getVidas()==0){
                scena->removeItem((*iter));
                enemigos1.erase(iter);
                if(cont==numero){
                    mostrarllave();
                }
            }
            return true;
        }
    }
    return false;
}

bool MainWindow::colPersonaje(QGraphicsItem *elemento, personajes *personaje, QLCDNumber *crono)
{
    if(personaje->collidesWithItem(elemento)){
        personaje->setVida();
        crono->display(personaje->getVida());
        crono->show();
        return true;
    }
    return false;
}

void MainWindow::colPuerta(){
    if(key->collidesWithItem(puerta1)){
        if(level==1){
            eFinLevel();
        }
        else if(level==2){
            eFinLevel();
        }
        else if(level==3){
            eEndGame();
        }
    }
}

void MainWindow::eRegistro()
{
    regist->setVisible(false);

    ventana1 = new Dialog(this);
    ventana1->setModal(true);

    ventana1->show();
    connect(ventana1, SIGNAL (back()),this, SLOT (funcRegistro()));

}

void MainWindow::funcRegistro()
{
    ventana1->close();


    if(users->Registrar(ventana1->getUsuario(),ventana1->getContra())){
        regist->setText("Usuario registrado correctamente");
        regist->setVisible(true);
        users->Guardar();
    }
    else {
        regist->setText("No se pudo registrar correctamente");
        regist->setVisible(true);
    }


}

void MainWindow::eInicio()
{
    regist->setVisible(false);
    ventana2 = new Dialog(this);
    ventana2->setModal(true);

    ventana2->show();
    connect(ventana2, SIGNAL (back()),this, SLOT (funcAcceder()));

}

void MainWindow::funcAcceder()
{
    ventana2->close();
    string level;

    if(users->Validar(ventana2->getUsuario(),ventana2->getContra())){
        level=users->getLevel(ventana2->getUsuario());
        if(level=="1"){
            level1();
        }
        else if (level=="2"){
            level2();
        }
        else if(level=="3"){
            level3();
        }
        else if(level=="4"){
            eEndGame();
        }
    }
    else{
        regist->setVisible(true);
        regist->setText("No se pudo acceder correctamente");
    }

}
void MainWindow::esconderllave(){
    int longi;
    longi=enemigos1.length();
    numero = 1 + rand() % (longi+1 - 1);
}
void MainWindow::mostrarllave(){
    llaveshow=true;
    if(numjugador==0){
        llavenum=0;
        if(users->getLevel(ventana2->getUsuario())=="1"){
            key= new llave(posx1,posy1);
            scene4->addItem(key);
        }
        if(users->getLevel(ventana2->getUsuario())=="2"){
            key= new llave(posx1,posy1);
            scene5->addItem(key);
        }
        if(users->getLevel(ventana2->getUsuario())=="3"){
            key= new llave(posx1,posy1);
            scene6->addItem(key);
        }
        llavem= new QTimer();
        connect(llavem,SIGNAL(timeout()),this,SLOT(movimientollave()));
        llavem->start(30);
    }
    else if(numjugador==1){
        llavenum=1;
        if(users->getLevel(ventana2->getUsuario())=="1"){
            key= new llave(posx2,posy2);
            scene4->addItem(key);
        }
        if(users->getLevel(ventana2->getUsuario())=="2"){
            key= new llave(posx2,posy2);
            scene5->addItem(key);
        }
        if(users->getLevel(ventana2->getUsuario())=="3"){
            key= new llave(posx2,posy2);
            scene6->addItem(key);
        }
        llavem= new QTimer();
        connect(llavem,SIGNAL(timeout()),this,SLOT(movimientollave()));
        llavem->start(30);
    }
}

void MainWindow::createFuego(QGraphicsScene *scene)
{
    QVector<Enemigo*>::iterator iterEnemigos;
    for(iterEnemigos=enemigos1.begin(); iterEnemigos!=enemigos1.end(); iterEnemigos++){
        fuegos.push_back(new fuego((*iterEnemigos)->getPosx(),(*iterEnemigos)->getPosy(),(*iterEnemigos)->getAngulo()));
        scene->addItem(fuegos.back());
    }
}

void MainWindow::deleteFuego(QGraphicsItem *elemento)
{
    elemento->setVisible(false);
    //sceneaux->removeItem(elemento);

    //fuegos.erase(&elemento);
}

void MainWindow::level1()
{
    sceneaux=scene4;
    QVector<fuego*>::iterator it;
    for(it=fuegos.begin(); it!=fuegos.end(); it++){
        fuegos.erase(it);
    }
    level=1;

    timer = new QTimer(this);
    timer->start(10);
    timer2 = new QTimer(this);
    timer2->start(100);


    scene4 = new QGraphicsScene();
    ui->graphicsView->setScene(scene4);
    scene4->setSceneRect(-500,-300,1000,600);
    scene4->setBackgroundBrush(QPixmap(":/images/fondo1.jpg"));

    scene4->addWidget(salir);
    salir->setGeometry(475,285,40,40);

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

    scene4->addItem(jugador1);
    scene4->addItem(jugador2);
    scene4->addWidget(vida1);
    scene4->addWidget(vida2);

    enemigos1.push_back(new Enemigo(150,-245,180,150,-430,pintura3,2));
    scene4->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-215,55,0,120,-215,pintura4,2));
    scene4->addItem(enemigos1.back());

    resorte1 = new Resorte(-400,-120,90);

    scene4->addItem(resorte1);

    puerta1 = new puerta(330,230);
    scene4->addItem(puerta1);
    esconderllave();


    salir->setGeometry(-475,-270,45,45);
    salir->setIcon(QIcon(":/images/botonsalir.png"));
    salir->setIconSize(QSize(40,40));
    salir->setStyleSheet("background-color: rgba(0,0,0,0%);");

    scene4->addWidget(salir);

    fuegotimer=new QTimer(this);
    fuegotimer->start(1000);
    connect(fuegotimer, SIGNAL(timeout()),this,SLOT(movFuego()));

    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(movResorte()));
    connect(salir,SIGNAL(clicked()),this,SLOT(ePrincipal()));

    ui->graphicsView->show();
}

void MainWindow::level2()
{
    level=2;
    sceneaux=scene5;
    QVector<fuego*>::iterator it;
    for(it=fuegos.begin(); it!=fuegos.end(); it++){
        fuegos.erase(it);
    }
    scene5 = new QGraphicsScene();
    ui->graphicsView->setScene(scene5);
    scene5->setSceneRect(-500,-300,1000,600);
    scene5->setBackgroundBrush(QPixmap(":/images/fondo2.jpg"));

    loadLevel("../level2.txt",scene5);

    timer = new QTimer(this);
    timer->start(10);
    timer2 = new QTimer(this);
    timer2->start(100);

    scene5->addWidget(salir);
    salir->setGeometry(475,285,40,40);

    QPixmap pintura1(jugador_1),pintura2(izquierda_2),pintura3(enemigoDere),pintura4(enemigoIzq);
    posx1=-455;
    posy1=220;
    posx2=420;
    posy2=220;

    jugador1 = new personajes(posx1,posy1,pintura1,12);
    vida1->display(jugador1->getVida());

    jugador2 = new personajes(posx2,posy2,pintura2,12);
    vida2->display(jugador2->getVida());

    scene5->addItem(jugador1);
    scene5->addItem(jugador2);
    scene5->addWidget(vida1);
    scene5->addWidget(vida2);

    enemigos1.push_back(new Enemigo(-185,-245,180,-185,-450,pintura4,3));
    scene5->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(175,-245,0,450,175,pintura3,3));
    scene5->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-215,85,180,-215,-395,pintura4,3));
    scene5->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(115,85,180,115,-95,pintura4,3));
    scene5->addItem(enemigos1.back());

    resorte1 = new Resorte(355,85,60);
    scene5->addItem(resorte1);

    puerta1 = new puerta(-355,85);
    puerta1->setVisible(false);
    scene5->addItem(puerta1);
    esconderllave();


    salir->setGeometry(-475,-270,45,45);
    salir->setIcon(QIcon(":/images/botonsalir.png"));
    salir->setIconSize(QSize(40,40));
    salir->setStyleSheet("background-color: rgba(0,0,0,0%);");

    scene5->addWidget(salir);

    fuegotimer=new QTimer(this);
    fuegotimer->start(1000);
    connect(fuegotimer, SIGNAL(timeout()),this,SLOT(movFuego()));

    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(movResorte()));
    connect(salir,SIGNAL(clicked()),this,SLOT(ePrincipal()));

    ui->graphicsView->show();
}

void MainWindow::level3(){
    level=3;
    sceneaux=scene6;
    QVector<fuego*>::iterator it;
    for(it=fuegos.begin(); it!=fuegos.end(); it++){
        fuegos.erase(it);
    }
    timer = new QTimer(this);
    timer->start(10);
    timer2 = new QTimer(this);
    timer2->start(1000);



    scene6 = new QGraphicsScene();
    ui->graphicsView->setScene(scene6);
    scene6->setSceneRect(-500,-300,1000,600);
    scene6->setBackgroundBrush(QPixmap(":/images/fondo3.jpg"));

    loadLevel("../level3.txt",scene6);

    QPixmap pintura1(jugador_1),pintura2(jugador_2),pintura3(enemigoDere),pintura4(enemigoIzq);
    posx1=-455;
    posy1=220;
    posx2=-395;
    posy2=220;
    jugador1 = new personajes(posx1,posy1,pintura1,14);
    vida1->display(jugador1->getVida());

    jugador2 = new personajes(posx2,posy2,pintura2,14);
    vida2->display(jugador2->getVida());
    scene6->addItem(jugador1);
    scene6->addItem(jugador2);
    scene6->addWidget(vida1);
    scene6->addWidget(vida2);

    enemigos1.push_back(new Enemigo(-65,-255,180,-65,-435,pintura4,4));
    scene6->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(5,-255,180,455,5,pintura4,4));
    scene6->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(85,-105,180,85,-215,pintura4,4));
    scene6->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-435,-15,180,-35,-435,pintura3,4));
    scene6->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-285,75,180,115,-285,pintura3,4));
    scene6->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(465,-45,180,465,355,pintura4,4));
    scene6->addItem(enemigos1.back());
    enemigos1.push_back(new Enemigo(-435,165,180,205,-435,pintura3,4));
    scene6->addItem(enemigos1.back());

    resorte1 = new Resorte(-455,-15,60);
    scene6->addItem(resorte1);

    puerta1 = new puerta(-395,225);
    scene6->addItem(puerta1);

    salir->setGeometry(-475,-270,45,45);
    salir->setIcon(QIcon(":/images/botonsalir.png"));
    salir->setIconSize(QSize(40,40));
    salir->setStyleSheet("background-color: rgba(0,0,0,0%);");

    esconderllave();

    fuegotimer=new QTimer(this);
    fuegotimer->start(1000);

    connect(fuegotimer, SIGNAL(timeout()),this,SLOT(movFuego()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(movResorte()));
    connect(salir,SIGNAL(clicked()),this,SLOT(ePrincipal()));

     ui->graphicsView->show();
}


void MainWindow::keyPressEvent(QKeyEvent *movimiento){
    QPixmap pintura1(derecha_1),pintura2(izquierda_1),pintura3(derecha_2),pintura4(izquierda_2);
    switch (movimiento->key()) {
    case Qt::Key_A:
    {
        posx1-=15;
        jugador1->personajebrush=pintura2;
        if(colParedes(jugador1)){
            posx1+=10;
        }
        if(sceneaux==scene5){
            if(jugador1->collidesWithItem(puerta1)){
                puerta1->setVisible(true);
            }
        }
        while(jugador1->collidesWithItem(resorte1)){
            posx1+=60;
        }
        Pos=0;
    }
        break;
    case Qt::Key_D:
    {
        posx1+=15;
        jugador1->personajebrush=pintura1;
        if(colParedes(jugador1)){
            posx1-=10;
        }
        if(sceneaux==scene5){
            if(jugador1->collidesWithItem(puerta1)){
                puerta1->setVisible(true);
            }
        }
        while(jugador1->collidesWithItem(resorte1)){
            posx1-=60;
        }
        Pos=1;
    }
        break;
    case Qt::Key_H:
    {
        posx2-=15;
        jugador2->personajebrush=pintura4;
        if(colParedes(jugador2)){
            posx2+=10;
        }
        if(sceneaux==scene5){
            if(jugador2->collidesWithItem(puerta1)){
                puerta1->setVisible(true);
            }
        }
        while(jugador2->collidesWithItem(resorte1)){
            posx1+=60;
        }
        Pos=0;
    }
        break;
    case Qt::Key_K:
    {
        posx2+=15;
        jugador2->personajebrush=pintura3;
        if(colParedes(jugador2)){
            posx2-=10;
        }
        if(sceneaux==scene5){
            if(jugador2->collidesWithItem(puerta1)){
                puerta1->setVisible(true);
            }
        }
        while(jugador2->collidesWithItem(resorte1)){
            posx1-=60;
        }
        Pos=1;
    }
        break;
    case Qt::Key_W:
    {
        direccion=true;
        limite=posy1-90;
        salto=new QTimer(this);
        connect(salto,SIGNAL(timeout()),this,SLOT(saltopersonaje1()));
        salto->start(50);
    }
        break;
    case Qt::Key_U:
    {
        direccion=true;
        limite=posy2-90;
        salto=new QTimer(this);
        connect(salto,SIGNAL(timeout()),this,SLOT(saltopersonaje2()));
        salto->start(50);
    }
        break;
    case Qt::Key_F:
    {
        numjugador=0;
        if(Pos==0){
            tirarflecha= new flecha(posx1-60,posy1+25,0);
            if(users->getLevel(ventana2->getUsuario())=="1"){
                scene4->addItem(tirarflecha);
                createFuego(scene4);
            }
            else if(users->getLevel(ventana2->getUsuario())=="2"){
                scene5->addItem(tirarflecha);
                createFuego(scene5);
            }
            else if(users->getLevel(ventana2->getUsuario())=="3"){
                scene6->addItem(tirarflecha);
                createFuego(scene6);
            }
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(50);



          

        }
        else if(Pos==1){
            tirarflecha= new flecha(posx1+60,posy1+25,1);
            if(users->getLevel(ventana2->getUsuario())=="1"){
                scene4->addItem(tirarflecha);
                createFuego(scene4);
            }
            else if(users->getLevel(ventana2->getUsuario())=="2"){
                scene5->addItem(tirarflecha);
                createFuego(scene5);
            }
            else if(users->getLevel(ventana2->getUsuario())=="3"){
                scene6->addItem(tirarflecha);
                createFuego(scene6);
            }
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(50);



           

        }
    }
        break;
    case Qt::Key_G:
    {
        numjugador=1;
        if(Pos==0){
            tirarflecha= new flecha(posx2-60,posy2+25,0);
            if(users->getLevel(ventana2->getUsuario())=="1"){
                scene4->addItem(tirarflecha);
                createFuego(scene4);
            }
            else if(users->getLevel(ventana2->getUsuario())=="2"){
                scene5->addItem(tirarflecha);
                createFuego(scene5);
            }
            else if(users->getLevel(ventana2->getUsuario())=="3"){
                scene6->addItem(tirarflecha);
                createFuego(scene6);
            }
            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(50);



        }
        else if(Pos==1){
            tirarflecha= new flecha(posx2+60,posy2+25,1);
            if(users->getLevel(ventana2->getUsuario())=="1"){
                scene4->addItem(tirarflecha);
                createFuego(scene4);
            }
            else if(users->getLevel(ventana2->getUsuario())=="2"){
                scene5->addItem(tirarflecha);
                createFuego(scene5);
            }
            else if(users->getLevel(ventana2->getUsuario())=="3"){
                scene6->addItem(tirarflecha);
                createFuego(scene6);
            }

            flecham=new QTimer(this);
            connect(flecham,SIGNAL(timeout()),this,SLOT(movimientoflecha()));
            flecham->start(50);


         

        }
    }
        break;
    }
    jugador1->setPos(posx1,posy1);
    jugador2->setPos(posx2,posy2);
    if(llavenum==0 and llaveshow){
        key->posx=posx1;
        key->posy=posy1;
        colPuerta();
    }
    if(llavenum==1 and llaveshow){
        key->posx=posx2;
        key->posy=posy2;
        colPuerta();
    }
}

void MainWindow::movimientoflecha(){
    tirarflecha->calcularPos();
    if(users->getLevel(ventana2->getUsuario())=="1"){
        if(colEnemigo(tirarflecha,scene4)){
            flecham->stop();
            tirarflecha->hide();
        }
    }
    else if(users->getLevel(ventana2->getUsuario())=="2"){
        if(colEnemigo(tirarflecha,scene5)){
            flecham->stop();
            tirarflecha->hide();
        }
    }
    else if(users->getLevel(ventana2->getUsuario())=="3"){
        if(colEnemigo(tirarflecha,scene6)){
            flecham->stop();
            tirarflecha->hide();
        }
    }
    colPersonaje(tirarflecha, jugador1, vida1);
    colPersonaje(tirarflecha, jugador2, vida2);
    if(tirarflecha->Yfinal>tirarflecha->Yinicial){
        flecham->stop();
        tirarflecha->hide();
    }
}


void MainWindow::movFuego()
{
    QVector<fuego*>::iterator it;
    for(it=fuegos.begin(); it!=fuegos.end(); it++){
        (*it)->cPosicion();
        if(colPersonaje((*it),jugador1,vida1)){
            (*it)->setVisible(false);
            //fuegos.erase(it);
        }
        else if(colPersonaje((*it),jugador2,vida2)){
            (*it)->setVisible(false);
        }
        else if(colParedes((*it))){
            (*it)->setVisible(false);
            //fuegos.erase(it);
        }
    }

    /*if(fuegos.empty()){
        fuegotimer->stop();
    }*/

    /*for(int i=0; i<fuegos.size(); i++){
        fuegos[i]->cPosicion();
        if(colPersonaje(fuegos[i])){
            fuegos[i]->setVisible(false);
            sceneaux->removeItem(fuegos[i]);
            fuegos.erase(i);
        }
        else if(colParedes(fuegos[i])){
            fuegos[i]->setVisible(false);
            sceneaux->removeItem(fuegos[i]);
            fuegos.erase(i);
        }
    }*/
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
        if(llaveshow){
            key->posx=posx1;
            key->posy=posy1;
            colPuerta();
        }
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
        if(llaveshow){
            key->posx=posx1;
            key->posy=posy1;
            colPuerta();
        }
        if(colParedes(jugador1)){
            posy1-=10;
            jugador1->posy-=10;
            jugador1->setPos(posx1,posy1);
            salto->stop();
        }
    }
}
void MainWindow::saltopersonaje2(){
    if(direccion){
        jugador2->arriba();
        posy2=jugador2->posy;
        jugador2->setPos(posx2,posy2);
        if(llaveshow){
            key->posx=posx2;
            key->posy=posy2;
            colPuerta();
        }
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
        if(llaveshow){
            key->posx=posx2;
            key->posy=posy2;
            colPuerta();
        }
        if(colParedes(jugador2)){
            posy2-=10;
            jugador2->posy-=10;
            jugador2->setPos(posx2,posy2);
            salto->stop();
        }
    }
}
