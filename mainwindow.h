#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include<iostream>

#include "myshape.h"


#include<QString>
#include<QPainter>
#include <QMainWindow>
#include <QTextStream>
#include<QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include<qcolordialog.h>
#include <QColorDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


// class myshape
// {
// public:

//     virtual void draw(QPainter *painter)=0;
//     virtual void save(QTextStream &stream)=0;

// };
// class mycircle:public myshape
// {
// public:
//     int x=-1;
//     int y;
//     int r;
//     virtual void draw(QPainter *painter ) override
//     {
//         painter->drawEllipse(x,y,r,r);

//     }
//     virtual void save(QTextStream &stream) override
//     {
//         stream<<x<<" "<<y<<" "<<r<<'\n';
//     }
// };
// class myrect:public myshape
// {
// public:
//     int x;
//     int y;
//     int w;
//     int h;


//     myrect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
//     myrect(){}
//     virtual void draw(QPainter *painter)override
//     {

//         painter->drawRect(x,y,w,h);
//     }
//     virtual void save(QTextStream &stream) override
//     {
//         int i=2;
//         stream<< i<<" "<<x<<" "<<y<<" "<<w<<" "<<h<<'\n';
//     }

// };



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void savefile();

    //QPen mPen;  //在这里！！！

    void openfile();
    void drawcircle();
    void drawrect();

    void changere();
    void changeyellow();
    //void undo();
   // void redoAction();
    std::vector<myshape*> getCurrentShapes() const;

protected    :
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);

private:
    Ui::MainWindow *ui;
    int operateflag;

    QColor temp_color=Qt::black;
    std::vector<myshape*>shapelist;
    //std::vector<QPainter*>colorlist;
    std::vector <QColor>colorlist;//等一下删掉

    std::list<myshape*> redolist;


signals:

private slots:
    void changeColor();
    void undo();
    void redo();//要加一个没有东西可以redo的判定

};
#endif
