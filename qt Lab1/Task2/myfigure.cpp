#include "myfigure.h"

myfigure::myfigure(size_t size):ram_size(size)
{

}

double myfigure::get_Area()
{
    return ram_size * (ram_size / 2);
}

double myfigure::get_Perimeter()
{
    return 2 * ram_size + ram_size;
}

QRectF myfigure::boundingRect() const
{
    return QRectF(QPoint(x_scene - ram_size / 2, y_scene - ram_size / 2),
                  QPoint(ram_size / 2 + x_scene, ram_size / 2 + y_scene));
}

void myfigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPolygon(polygon());
}

QPolygonF myfigure::polygon() const
{
    QPolygonF polygon;
    polygon << QPointF(x_scene - ram_size / 2, y_scene)
            << QPointF(x_scene - ram_size / 6, y_scene - ram_size / 6)
            << QPointF(x_scene, y_scene - ram_size / 2)
            << QPointF(x_scene + ram_size / 6, y_scene - ram_size / 6)
            << QPointF(x_scene + ram_size / 2, y_scene)
            << QPointF(x_scene + ram_size / 6, y_scene + ram_size / 6)
            << QPointF(x_scene, y_scene + ram_size / 2)
            << QPointF(x_scene - ram_size / 6, y_scene + ram_size / 6);
    return polygon;
}

