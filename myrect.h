#ifndef MYRECT_H
#define MYRECT_H

#include "myshape.h"
class myrect:public myshape
{
public:
    int x;
    int y;
    int w;
    int h;
    QColor m_color=Qt::black;


    myrect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    myrect(){}
    virtual void draw(QPainter *painter)override
    {

        painter->drawRect(x,y,w,h);
    }
    virtual void save(QTextStream &stream) override
    {
        int i=2;
        stream<<x<<" "<<y<<" "<<w<<" "<<h<<" "<<red<<" "<<green<<" "<<blue<<'\n';
    }

};
#endif // MYRECT_H
