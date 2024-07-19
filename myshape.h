#ifndef MYSHAPE_H
#define MYSHAPE_H

#include<QString>
#include<QPainter>
#include <QMainWindow>
#include <QTextStream>



class myshape
{
public:
    QColor m_color;
    int red;
    int green;
    int blue;
    virtual void draw(QPainter *painter)=0;
    virtual void save(QTextStream &stream)=0;



};

#endif // MYSHAPE_H
