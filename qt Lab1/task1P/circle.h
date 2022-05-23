#ifndef CIRCLE_H
#define CIRCLE_H

#include "wheel.h"
#include <QGraphicsLineItem>
class Circle:public Wheel
{
public:
    Circle();

    QRectF boundingRect() const override;
    void draw() override;

    QGraphicsLineItem* line1;
    QGraphicsLineItem* line2;
    QGraphicsLineItem* line3;
    QGraphicsLineItem* line4;
    QGraphicsEllipseItem* wheel_speen_in;
private:
    QTimer *myTimer;
private slots:


};

#endif // CIRCLE_H
