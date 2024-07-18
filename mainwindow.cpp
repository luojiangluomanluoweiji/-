#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFile>
#include<QPen>
#include<QColor>
#include<QKeyEvent>
#include<QDebug>
#include<QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    QMenuBar *menubar=menuBar();
    QMenu *filemenu=menubar->addMenu("文件");
    QAction *saveaction=filemenu->addAction("保存");
    connect(saveaction,&QAction::triggered,this,&MainWindow::savefile);
    QAction *openaction=filemenu->addAction("打开");
    connect(openaction,&QAction::triggered,this,&MainWindow::openfile);


    QMenu *drawmenu=menubar->addMenu("绘图");
    QAction *drawcircle=drawmenu->addAction("画圆");
    QAction *drawrect=drawmenu->addAction("画矩形");

    connect(drawcircle,&QAction::triggered,this,&MainWindow::drawcircle);
    connect(drawrect,&QAction::triggered,this,&MainWindow::drawrect);

    QMenu *colorMenu = menubar->addMenu("颜色");
    QAction *changeColorAction = colorMenu->addAction("改变颜色");
    connect(changeColorAction, &QAction::triggered, this, &MainWindow::changeColor);

    QMenu *editMenu = menuBar()->addMenu("编辑");
    QAction *undoAction = new QAction("撤销", this);
    connect(undoAction,&QAction::triggered,this,&MainWindow::undo);
    QAction *redoAction = new QAction("redo", this);
    connect(redoAction,&QAction::triggered,this,&MainWindow::redo);
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::savefile()
{
    //代码改进：在class里加一个QString path
    //QString path="D:\\qt profram\\aemo\\test.txt"
    //不知道为什么教程里是两个|
    QFile myfile("D:\\qt profram\\aemo\\test.txt");
    if(myfile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream mystream(&myfile);
        for(int i=0;i<shapelist.size();i++)
            shapelist[i]->save(mystream);

        myfile.close();
    }
}
void MainWindow::openfile()
{
    //代码改进：地址用path代替
    QFile myfile("D:\\qt profram\\aemo\\test.txt");
    if(myfile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream mystream(&myfile);
        while(!mystream.atEnd())
        {
            QString s=mystream.readLine();
            QStringList ss=s.split(" ");
            if(ss.size()==3)
            {
                mycircle *circleobj=new mycircle();
                circleobj->x=ss[0].toInt();
                circleobj->y=ss[1].toInt();
                circleobj->r=ss[2].toInt();
                shapelist.push_back(circleobj);
            }
            if(ss.size()==4)
            {
                myrect *rectobj=new myrect();
                rectobj->x=ss[0].toInt();
                rectobj->y=ss[1].toInt();
                rectobj->w=ss[2].toInt();
                rectobj->h=ss[3].toInt();
                shapelist.push_back(rectobj);
            }
        }
        myfile.close();
        update();
    }
    else
        qDebug()<<"open fail!";

}

void  MainWindow::drawcircle(){
    operateflag=1;
}
void MainWindow::drawrect(){
    operateflag=2;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pt=event->pos();//返回点击的坐标
    if(operateflag==1)
    {
        mycircle *circleob=new mycircle();
        circleob->r=50;
        circleob->x=pt.rx();
        circleob->y=pt.ry();
        shapelist.push_back(circleob);
        //history.push_back(circleob);
    }
    if(operateflag==2)
    {


        myrect *rectobj=new myrect();
        rectobj->x=pt.rx();
        rectobj->y=pt.ry();
        rectobj->w=50;
        rectobj->h=30;
        shapelist.push_back(rectobj);
        //history.push_back(rectobj);

    }
    update();

}

void MainWindow::changeColor() {
    QColor selectedColor = QColorDialog::getColor(Qt::black, this);
    if (selectedColor.isValid()) {
        mPen.setColor(selectedColor);
        color = selectedColor; // 假设你已经在 MainWindow 类中定义了 QColor color;
    }
}


void MainWindow::undo()
{
    redolist.push_back(shapelist.back());
    shapelist.pop_back();
    update();


}

void MainWindow::redo()
{
    shapelist.push_back(redolist.back());
    redolist.pop_back();
    update();
}

/*void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter *p;
    QPen pen;
    p=new QPainter(this);

    for(int i=0;i<shapelist.size();i++){

         shapelist[i]->draw(p);



    }

    delete p;
}*/

//update()函数会触发这个函数
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(mPen); // 使用 mPen 来绘制，它会使用用户选择的颜色

    for (int i = 0; i < shapelist.size(); i++) {
        shapelist[i]->draw(&painter);
    }
}
