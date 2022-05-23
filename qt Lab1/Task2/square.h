#ifndef SQUARE_H
#define SQUARE_H
#include "figure.h"

class square: public figure
{
public:
    square(size_t size);
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

#endif // SQUARE_H
