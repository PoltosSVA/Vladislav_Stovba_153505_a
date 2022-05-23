#include "widget.h"
#include "ui_widget.h"
#include <QPointF>
#include <QPoint>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    CreateSceneAndView();



    circle = new class Circle;
    wheel = new class Wheel;


    scene->addItem(wheel->wheel_item_out);
    scene->addItem(circle->line1);
    scene->addItem(circle->line2);
    scene->addItem(circle->line3);
    scene->addItem(circle->line4);

    scene->addItem(circle->wheel_speen_in);

    int transX = 425;
    int transY = 300;



    speen_wheel_timer = new QTimer(this);
    speen_wheel_timer->start(1000/60);

    wheel->wheel_item_out->setTransformOriginPoint(transX,transY);
    circle->wheel_speen_in->setTransformOriginPoint(transX,transY);
    circle->line1->setTransformOriginPoint(transX,transY);
    circle->line2->setTransformOriginPoint(transX,transY);
    circle->line3->setTransformOriginPoint(transX,transY);
    circle->line4->setTransformOriginPoint(transX,transY);
    connect(speen_wheel_timer, &QTimer::timeout, this, &Widget::func_wheel_speen);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::CreateSceneAndView()
{


    scene = new QGraphicsScene(0, 0, 800, 600, this);
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();
}

void Widget::func_wheel_speen()
{
    circle->line1->setRotation(circle->line1->rotation() + 0.5);
    circle->line2->setRotation(circle->line2->rotation() + 0.5);
    circle->line3->setRotation(circle->line3->rotation() + 0.5);
    circle->line4->setRotation(circle->line4->rotation() + 0.5);

    circle->wheel_speen_in->setRotation(circle->wheel_speen_in->rotation() + 0.5);
    wheel->wheel_item_out->setRotation(wheel->wheel_item_out->rotation() + 0.5);


    static int x =0 , y = 0;
    x++;


        wheel->wheel_item_out->setPos(x, y);
        circle->wheel_speen_in->setPos(x, y);
        circle->line1->setPos(x,y);
        circle->line2->setPos(x,y);
        circle->line3->setPos(x,y);
        circle->line4->setPos(x,y);

    if(x == 300){

        speen_wheel_timer->stop();
    }
}



