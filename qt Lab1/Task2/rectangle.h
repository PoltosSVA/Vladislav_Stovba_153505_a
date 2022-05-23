#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class rectangle:public figure
{
public:
    rectangle(size_t size);
    virtual double get_Area() override;
    virtual double get_Perimeter() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    QPolygonF polygon() const;
protected:
    size_t ram_size;
};

#endif // RECTANGLE_H
