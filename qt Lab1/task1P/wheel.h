#ifndef WHEEL_H
#define WHEEL_H
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QHBoxLayout>
class Wheel:public QGraphicsView, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Wheel(QGraphicsEllipseItem *parent = nullptr);
    QGraphicsScene* scene;
    QGraphicsEllipseItem* wheel_item_out;
    virtual QRectF boundingRect() const override;
    virtual void draw();



private:



protected:

    int R;
    int G;
    int B;
};



#endif // WHEEL_H
