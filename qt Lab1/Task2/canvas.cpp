#include "canvas.h"
#include "ui_canvas.h"
#include <QGraphicsSceneMouseEvent>
canvas::canvas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
    paintscene = new paint_scene();
    paintscene->setSceneRect(0,0,850,600);
    ui->graphicsView->setScene(paintscene);
}

canvas::~canvas()
{
    delete ui;
}

paint_scene::paint_scene(QObject *parent):QGraphicsScene(parent)
{

}

paint_scene::~paint_scene()
{

}

void paint_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse (event->scenePos().x() - 5,
                event->scenePos().y() - 5,
                10,10,
                QPen(Qt::NoPen),
                QBrush(Qt::black));
    pre_point = event->scenePos();
}

void paint_scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine (pre_point.x() ,
                pre_point.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::black,10,Qt::SolidLine,Qt::RoundCap));

    pre_point = event->scenePos();
}

void canvas::on_pushButton_2_clicked()
{
    close();
}


void canvas::on_pushButton_clicked()
{
    paintscene->clear();
}

