#include "wheel.h"

Wheel::Wheel(QGraphicsEllipseItem *parent):QGraphicsEllipseItem(parent)
{

    draw();

}

QRectF Wheel::boundingRect() const
{

}

void Wheel::draw()
{
    wheel_item_out = new QGraphicsEllipseItem(325,200,200,200);

    wheel_item_out->setPen(QPen(Qt::red,4,Qt::SolidLine));





}

//void Wheel::TimerMy()
//{
//    wheel_item_out->setRotation(wheel_item_out->rotation() + 0.5);
//}


