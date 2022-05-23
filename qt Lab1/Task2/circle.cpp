#include "circle.h"

circle::circle(size_t size): ram_size(size)
{

}

QRectF circle::boundingRect() const{
    return QRectF(QPoint(x_scene-ram_size/2,y_scene-ram_size/2),
                  QPoint(ram_size/2+x_scene,ram_size/2+y_scene));
}

double circle::get_Area(){
    return (ram_size/2)*(ram_size/2)*3.14159265359;
}
double circle::get_Perimeter(){
    return 2*(ram_size/2)*3.14159265359;
}
void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawEllipse(x_scene-ram_size/2,y_scene-ram_size/2,ram_size,ram_size);
}
