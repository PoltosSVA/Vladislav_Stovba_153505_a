#include "square.h"

square::square(size_t size):ram_size(size)
{

}

double square::get_Area()
{
    return ram_size * ram_size;
}

double square::get_Perimeter()
{
    return 4 * ram_size;
}

QRectF square::boundingRect() const
{
    return QRectF(QPoint(x_scene - ram_size / 2, y_scene - ram_size / 2),
                  QPoint(ram_size / 2 + x_scene, ram_size / 2 + y_scene));
}

void square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPolygon(polygon());
}

QPolygonF square::polygon() const
{
    QPolygonF polygon;
    polygon << QPointF(x_scene - ram_size / 2, y_scene - ram_size / 2)
            << QPointF(x_scene - ram_size / 2, ram_size + y_scene - ram_size / 2)
            << QPointF(ram_size + x_scene - ram_size / 2, ram_size + y_scene - ram_size / 2)
            << QPointF(ram_size + x_scene - ram_size / 2, y_scene - ram_size / 2);
    return polygon;
}
