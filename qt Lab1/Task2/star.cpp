

#include "star.h"

star::star(size_t size,size_t c_angle):ram_size(size),m_c_angle(c_angle)
{

}

double star::get_Area()
{
    return 1;
}

double star::get_Perimeter()
{
    return 1;
}

QRectF star::boundingRect() const
{
    return QRectF(QPoint(x_scene - ram_size / 2, y_scene - ram_size / 2),
                  QPoint(ram_size / 2 + x_scene, ram_size / 2 + y_scene));
}

void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPolygon(polygon());
}

QPolygonF star::polygon() const
{
    QPolygonF polygon;
    double aUnit = 6.283185307 / m_c_angle;
    double aVertex = 4.71238898037;
    double aCentralVertex = aVertex;
    double a, size_central;
    double PI = 3.14159265359;
    double angle = (180 * (m_c_angle - 2)) / m_c_angle;
    a = ram_size / (tan(angle / 2 / 180 * PI) + tan((180 - angle) / 180 * PI));
    size_central = a / cos(angle / 2 / 180 * PI);
    aCentralVertex += (180 - angle) / 360 * PI;

    for(int i = 0; i < m_c_angle; ++i) {
        polygon << QPointF((cos(aVertex) * ram_size + ram_size) / 2 + x_scene - ram_size / 2,
                           (sin(aVertex) * ram_size + ram_size) / 2 + y_scene - ram_size / 2);
        polygon << QPointF((cos(aCentralVertex) * size_central + ram_size) / 2 + x_scene - ram_size / 2,
                           (sin(aCentralVertex) * size_central + ram_size) / 2 + y_scene - ram_size / 2);

        aVertex += aUnit;
        aCentralVertex += aUnit;
    }



    return polygon;
}
