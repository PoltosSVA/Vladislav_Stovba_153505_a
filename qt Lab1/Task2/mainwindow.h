#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeEdit>
#include <QParallelAnimationGroup>
#include <QTimer>

#include <QPoint>
#include "circle.h"
#include "figure.h"
#include "hexagon.h"
#include "myfigure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"
#include "star.h"
#include "triangle.h"
#include "canvas.h"

#include <math.h>


#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>

\

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void FigureChanged();
    void FigureTransform(int x, int y, int angle, double scale);
private slots:
    void onRotate();
    void onTranslate();
    void onScale();
    void on_pushButton_7_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();



    void on_radioButton_clicked(bool checked);

   // void on_pushButton_10_pressed();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    square *Square;
    triangle *Triangle;
    circle *Circle;
    rhombus *Rhombus;
    hexagon *Hexagon;
    rectangle *Rectangle;
    star *Star;

    bool isCircle = false;
    bool isHexagon = false;
    bool isStar = false;
    int x_position = 0;
    int y_position = 0;
    int m_angle = 0;
    int m_speed_rotate = 0;
    int ram_size_x = 0;
    int ram_size_y = 0;
    double m_scale = 0;
    double m_speed_scale = 0;
    double m_speed_x = 0;
    double m_speed_y = 0;

    figure *temp_item = nullptr;
    point *Point = nullptr;
    QTimer *TimerRotation;
    QTimer *TimerTranslate;
    QTimer *TimerScale;
};
#endif // MAINWINDOW_H
