#include "rectangle.h"

rectangle::rectangle(size_t size):ram_size(size)
{

}

double rectangle::get_Area()
{
    return ram_size * (ram_size / 2);
}

double rectangle::get_Perimeter()
{
    return 2 * ram_size + ram_size;
}

QRectF rectangle::boundingRect() const
{
    return QRectF(QPoint(x_scene - ram_size / 2, y_scene - ram_size / 2),
                  QPoint(ram_size / 2 + x_scene, ram_size / 2 + y_scene));
}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPolygon(polygon());
}

QPolygonF rectangle::polygon() const
{
    QPolygonF polygon;
    polygon << QPointF(x_scene - ram_size / 2, ram_size / 4 + y_scene - ram_size / 2)
            << QPointF(x_scene - ram_size / 2, ram_size * 3 / 4 + y_scene - ram_size / 2)
            << QPointF(ram_size + x_scene - ram_size / 2, ram_size * 3 / 4 + y_scene - ram_size / 2)
            << QPointF(ram_size + x_scene - ram_size / 2, ram_size / 4 + y_scene - ram_size / 2);
    return polygon;
}
