#include "point.h"

point::point(size_t size):ram_size(size)
{

}
QRectF point::boundingRect() const{
    return QRectF(QPoint(x_scene-ram_size/2,y_scene-ram_size/2),
                  QPoint(ram_size/2+x_scene,ram_size/2+y_scene));

}

void point::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QPen pen;
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawEllipse(x_scene-ram_size/2,y_scene - ram_size/2,ram_size,ram_size);
}
