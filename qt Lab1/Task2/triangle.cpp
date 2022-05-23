#include "triangle.h"

triangle::triangle(size_t size):ram_size(size)
{

}

double triangle::get_Area()
{
    return ram_size * ram_size / 2;
}

QPointF triangle::get_Center()
{
    return QPointF(0, 50/3);
}

double triangle::get_Perimeter()
{
    return ram_size + ram_size * sqrt(5) / 2;
}

QRectF triangle::boundingRect() const
{
    return QRectF(QPoint(x_scene - ram_size / 2, y_scene - ram_size / 2),
                  QPoint(ram_size / 2 + x_scene, ram_size / 2 + y_scene));
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPolygon(polygon());
}

QPolygonF triangle::polygon() const
{
    QPolygonF polygon;
    polygon << QPointF(x_scene - ram_size / 2, ram_size + y_scene - ram_size / 2)
            << QPointF(ram_size / 2 + x_scene - ram_size / 2, y_scene - ram_size / 2)
            << QPointF(ram_size + x_scene - ram_size / 2, ram_size + y_scene - ram_size / 2);
    return polygon;
}
