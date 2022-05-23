#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"

class rhombus:public figure
{
public:
    rhombus(size_t size);
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

#endif // RHOMBUS_H
