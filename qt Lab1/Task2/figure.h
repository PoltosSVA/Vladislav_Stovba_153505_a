#ifndef FIGURE_H
#define FIGURE_H

#include <QPoint>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include "math.h"

class figure:public QGraphicsObject
{
public:
    figure();
    virtual double get_Area();
    virtual QPointF get_Center();
    virtual double get_Perimeter();
private:
    QRect rect;
protected:
    size_t x_scene = 200;
    size_t y_scene = 250;
};

#endif // FIGURE_H
