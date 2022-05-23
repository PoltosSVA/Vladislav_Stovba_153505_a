#ifndef POINT_H
#define POINT_H

#include "figure.h"
class point:public figure
{
public:
    point(size_t size);
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
private:
    size_t ram_size;
};

#endif // POINT_H
