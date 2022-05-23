#include "rhombus.h"

rhombus::rhombus(size_t size):ram_size(size)
{

}

double rhombus::get_Area()
{
    return ram_size * ram_size / 4;
}

double rhombus::get_Perimeter()
{
    return 2 * sqrt(ram_size * ram_size + ram_size  * ram_size / 4);
}

QRectF rhombus::boundingRect() const
{
    return QRectF(QPoint(x_scene - ram_size / 2, y_scene - ram_size / 2),
                  QPoint(ram_size / 2 + x_scene, ram_size / 2 + y_scene));
}

void rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPolygon(polygon());
}

QPolygonF rhombus::polygon() const
{
    QPolygonF polygon;
    polygon << QPointF(ram_size / 4 + x_scene - ram_size / 2, ram_size / 2 + y_scene - ram_size / 2)
            << QPointF(ram_size / 2 + x_scene - ram_size / 2, y_scene - ram_size / 2)
            << QPointF(ram_size * 3 / 4 + x_scene - ram_size / 2, ram_size / 2 + y_scene - ram_size / 2)
            << QPointF(ram_size / 2 + x_scene - ram_size / 2, ram_size + y_scene - ram_size / 2);
    return polygon;
}
