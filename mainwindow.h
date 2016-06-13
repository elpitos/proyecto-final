#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItemAnimation>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include <QtCore>
#include <QTimer>
#include <QString>
#include <QValidator>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>
#include <QObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void mover();
    void moverr();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item,*cube;
    QGraphicsItem *reloj;
    QSvgRenderer *render;
    QTimer *time;
    double g,m,K,V,X,O,L,x,y,vx,vy,vc;

};

#endif // MAINWINDOW_H
