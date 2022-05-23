#include "hexagon.h"

hexagon::hexagon(size_t size, size_t c_angle):ram_size(size),m_c_angle(c_angle)
{

}

double hexagon::get_Area(){
    return (ram_size/2)*(ram_size/2)*m_c_angle/2*sin(2*3.14159265/m_c_angle);
}

double hexagon::get_Perimeter(){
    return 2*(ram_size/2)*sin(3.14159265/m_c_angle)*m_c_angle;
}

QRectF hexagon::boundingRect() const{
    return QRectF(QPoint(x_scene-ram_size/2,y_scene-ram_size/2),
                  QPoint(ram_size/2+x_scene,ram_size/2+y_scene));

}

void hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPolygon(polygon());
}

QPolygonF hexagon::polygon() const{
    QPolygonF polygon;
    double aUnit = 6.28/m_c_angle;
    for(int i=0;i<m_c_angle;i++){
        polygon << QPointF((cos(aUnit * i) * ram_size+  ram_size) / 2 + x_scene - ram_size / 2,
                           (sin(aUnit * i) *  ram_size + ram_size) / 2 + y_scene-ram_size / 2);
    }
    return polygon;
}
