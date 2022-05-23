#include "circle.h"
#include <QPointF>
Circle::Circle()
{

    draw();


}

QRectF Circle::boundingRect() const
{

}

void Circle::draw()
{
    wheel_speen_in = new QGraphicsEllipseItem(375,250,100,100);

    wheel_speen_in ->setPen(QPen(Qt::red,4,Qt::SolidLine));

    line1 = new QGraphicsLineItem(354, 232, 388, 266);
    line1->setPen(QPen(Qt::black,4,Qt::SolidLine));

    line2 = new QGraphicsLineItem(496, 235, 465, 266);
    line2->setPen(QPen(Qt::black,4,Qt::SolidLine));

    line3 = new QGraphicsLineItem(354, 369, 388, 335);
    line3->setPen(QPen(Qt::black,4,Qt::SolidLine));

    line4 = new QGraphicsLineItem(496, 368, 465, 335);
    line4->setPen(QPen(Qt::black,4,Qt::SolidLine));





}



