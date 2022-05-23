#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QTimer>
#include <QHBoxLayout>
#include <QObject>
#include <QtWidgets>
#include <QPainter>
#include "circle.h"
#include "wheel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void CreateSceneAndView();
    void CreateLayouts();
    void ConnectButtons();

private:
    Ui::Widget *ui;

    QGraphicsScene* scene;
    QGraphicsView* view;
    QHBoxLayout* layout;

    QHBoxLayout *myLayout;
    Wheel *graphicsView;
    Circle* circle;
    Wheel* wheel;
    QTimer *speen_wheel_timer;
private slots:
    void func_wheel_speen();


};


#endif // WIDGET_H
