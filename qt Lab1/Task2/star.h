#ifndef STAR_H
#define STAR_H

#include "figure.h"
class star:public figure
{
public:
    star(size_t size,size_t c_angle);
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

#endif // STAR_H
