
#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
class hexagon:public figure
{
public:
    hexagon(size_t size,size_t c_angle);
    virtual double get_Area() override;
    virtual double get_Perimeter() override;
protected:
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    QPolygonF polygon() const;
protected:
    size_t ram_size;
    size_t m_c_angle;

};

#endif // HEXAGON_H
