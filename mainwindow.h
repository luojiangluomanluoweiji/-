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






class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void savefile();



    void openfile();
    void drawcircle();
    void drawrect();

    void changere();
    void changeyellow();

    std::vector<myshape*> getCurrentShapes() const;

protected    :
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);

private:
    Ui::MainWindow *ui;
    int operateflag;
    QColor temp_color=Qt::black;
    std::vector<myshape*>shapelist;
    std::list<myshape*> redolist;


signals:

private slots:
    void changeColor();
    void undo();
    void redo();//要加一个没有东西可以redo的判定

};
#endif
