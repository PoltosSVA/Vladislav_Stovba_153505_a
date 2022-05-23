#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <QMouseEvent>
#include "point.h"


namespace Ui {
class canvas;
}


class paint_scene: public QGraphicsScene{
    Q_OBJECT
public:
    explicit paint_scene(QObject *parent = 0);
    ~paint_scene();
private:
    QPointF pre_point;
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};



class canvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);
    ~canvas();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::canvas *ui;
    paint_scene *paintscene;
};

#endif // CANVAS_H
