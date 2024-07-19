#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "myshape.h"

class mycircle:public myshape
{
public:
    int x=-1;
    int y;
    int r;
    QColor m_color;

    virtual void draw(QPainter *painter ) override
    {

        painter->drawEllipse(x,y,r,r);

    }
    virtual void save(QTextStream &stream) override
    {
        stream<<x<<" "<<y<<" "<<r<<" "<<red<<" "<<green<<" "<<blue<<'\n';
    }

};
#endif // MYCIRCLE_H
