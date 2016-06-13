#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setBackgroundBrush(Qt::cyan);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,930,470);
    scene->addRect(scene->sceneRect());
    cube = new QGraphicsPixmapItem;
    item = new QGraphicsPixmapItem;
    QFile file("/home/ivan/proyecto/reloj.svg");
    reloj= new QGraphicsSvgItem(file.fileName());
    reloj->setFlags(QGraphicsItem::ItemClipsToShape);
    reloj->setCacheMode(QGraphicsItem::NoCache);
    reloj->setZValue(0);
    reloj->setFlag(QGraphicsItem::ItemIsMovable);
    QPixmap pix("/home/ivan/proyecto/pelot0.svg");
    item->setPixmap(pix);
    QPixmap pix0("/home/ivan/proyecto/morao.svg");
    cube->setPixmap(pix0);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    scene->addItem(cube);
    scene->addItem(reloj);
    item->setPos(80,370);
    cube->setPos(630,10);
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::green);
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(mover()));
    time->start(0.1);
    m=20;
    K=90;
    g=9.8;
    vc=0.9;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //ui->masa->setText("30");
    time->stop();
    disconnect(time,SIGNAL(timeout()),this,SLOT(mover()));
    //bool ok;
    //if(ui->masa->text()!=""){
      //  m=(ui->masa->text()).toDouble(&ok);
    //}
    //if(ui->resor->text()!=""){
      //  K=(ui->resor->text()).toDouble(&ok);
    //}
    x=item->x();y=item->y();
    O=atan(((item->y())-370)/(80-(item->x())));
    X=pow(((pow(((item->y())-370),2))+(pow((80-(item->x())),2))),0.5);
    L=113.137085;
    V=pow((((K*X*X)/m)-(2*g*X*(sin(O)))),0.5);
    vx=V*(cos(O));vy=V* (sin(O));
    connect(time,SIGNAL(timeout()),this,SLOT(moverr()));
    time->start(10);
    vc=10;
}
void MainWindow::mover(){
    cube->setY(cube->y()+vc);
    if(cube->y()< 0 || cube->y()>440){
        vc *= -1;
    }
    if((item->x())>80){
        item->setX(80);
    }
    if((item->x())<-10){
        item->setX(-10);
    }
    if((item->y())<370){
        item->setY(370);
    }
    if((item->y())>440){
        item->setY(440);
    }

}

void MainWindow::moverr()
{
   if(item->collidesWithItem(cube)){
       vx= -vx;
   }

   item->setPos(x,y);
   x+=vx*(0.1);
   if(x < -10){
       vx *= (-1);
   }
   if(x > 910){
       vx *= (-1);
   }
   y=y-(vy*(0.1))+(((g*(pow((0.1),2)))/2));
   vy=vy-(g*(0.1));
   if(y < 0){
       vy *= (-1);
   }
   if(y > 440){

       vy *= (-1);
   }
   cube->setY(cube->y()+vc);
   if(cube->y()< 0 || cube->y()>440){
       vc *= -1;
   }
}
