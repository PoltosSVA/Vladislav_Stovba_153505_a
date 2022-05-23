#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class triangle:public figure
{
public:
    triangle(size_t size);
    virtual double get_Area() override;
    virtual QPointF get_Center() override;
    virtual double get_Perimeter() override;


protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    QPolygonF polygon() const;
protected:
    size_t ram_size;
};

#endif // TRIANGLE_H
