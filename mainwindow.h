#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include<iostream>


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


class myshape
{
public:

    virtual void draw(QPainter *painter)=0;
    virtual void save(QTextStream &stream)=0;

};
class mycircle:public myshape
{
public:
    int x=-1;
    int y;
    int r;
    virtual void draw(QPainter *painter ) override
    {
        painter->drawEllipse(x,y,r,r);

    }
    virtual void save(QTextStream &stream) override
    {
        stream<<x<<" "<<y<<" "<<r<<'\n';
    }
};
class myrect:public myshape
{
public:
    int x;
    int y;
    int w;
    int h;


    myrect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    myrect(){}
    virtual void draw(QPainter *painter)override
    {

        painter->drawRect(x,y,w,h);
    }
    virtual void save(QTextStream &stream) override
    {
        int i=2;
        stream<< i<<" "<<x<<" "<<y<<" "<<w<<" "<<h<<'\n';
    }

};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void savefile();
    QPen mPen;

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

    std::vector<myshape*>shapelist;
    std::vector<QPainter*>colorlist;
    QColor color;
    std::list<myshape*> history;
    std::list<myshape*> redolist;


signals:

private slots:
    void changeColor();
    void undo();
    void redo();

};
#endif
