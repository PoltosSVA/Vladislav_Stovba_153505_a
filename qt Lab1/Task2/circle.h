

#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"
class circle:public figure
{
public:
    circle(size_t size);
    virtual double get_Area() override;
    virtual double get_Perimeter() override;
protected:
    QRectF boundingRect()const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
    size_t ram_size;
};

#endif // CIRCLE_H
