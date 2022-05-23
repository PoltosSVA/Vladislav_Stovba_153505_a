#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 400, 500, this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//jjjgfodoogdfogjdfgiodfgkdfgdrgoiddorjgdjgkorirmdfkgfdgdfgdhfdhfghfghfghtfhfghthfhfhhfth
    TimerRotation = new QTimer(this);
    connect(TimerRotation, SIGNAL(timeout()), this, SLOT(onRotate()));

    TimerTranslate = new QTimer(this);
    connect(TimerTranslate, SIGNAL(timeout()), this, SLOT(onTranslate()));

    TimerScale = new QTimer(this);
    connect(TimerScale, SIGNAL(timeout()), this, SLOT(onScale()));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Point = new point(2);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete temp_item;
}

void MainWindow::onRotate()
{
    if(isCircle){
    temp_item->setTransformOriginPoint(200,200);
    }
    else{
        temp_item->setTransformOriginPoint(200,250);
    }


    if(temp_item != nullptr ) {
        if(m_angle != temp_item->rotation()) {

            temp_item->setRotation(temp_item->rotation() + m_speed_rotate);
        } else {
            TimerRotation->stop();
        }
    }//hdffdgfffdhhsgdggdfggsfsgsdgsrgsgsggsgsggsegs
}

void MainWindow::onTranslate()
{
    if(abs(temp_item->pos().x() - x_position) > 0.01 || abs(temp_item->pos().y() - y_position) > 0.01 ) {
        temp_item->setPos(temp_item->pos().x() + m_speed_x,
                          temp_item->pos().y() + m_speed_y);
        Point->setPos(Point->pos().x() + m_speed_x,
                      Point->pos().y() + m_speed_y);
    } else {
        TimerTranslate->stop();
    }
}

void MainWindow::onScale()
{
    if(abs(temp_item->scale() - m_scale) > 0.005) {
        temp_item->setScale(temp_item->scale() + m_speed_scale);
    } else {
        TimerScale->stop();
    }
    ui->lineEdit_7->setText(QString::number(temp_item->get_Perimeter() * temp_item->scale()));
    ui->lineEdit_8->setText(QString::number(temp_item->get_Area() * temp_item->scale() * temp_item->scale()));
}


void MainWindow::on_pushButton_7_clicked()
{
    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new square(100);
    scene->addItem(temp_item);
    FigureChanged();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new triangle(100);
    scene->addItem(temp_item);
    FigureChanged();
}


void MainWindow::on_pushButton_clicked()
{
    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new circle(100);
    scene->addItem(temp_item);
    FigureChanged();
    isCircle = true;
    ui->lineEdit_5->setText(QString::number(100));
}


void MainWindow::on_pushButton_4_clicked()
{
    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new rhombus(100);
    scene->addItem(temp_item);
    FigureChanged();
}


void MainWindow::on_pushButton_2_clicked()
{

    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new hexagon(100, 6);
    scene->addItem(temp_item);
    FigureChanged();
    isHexagon = true;
    ui->lineEdit_6->setText(QString::number(6));
}


void MainWindow::on_pushButton_8_clicked()
{
    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new rectangle(100);
    scene->addItem(temp_item);
    FigureChanged();

}


void MainWindow::on_pushButton_5_clicked()
{

    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new star(100, 5);
    scene->addItem(temp_item);
    FigureChanged();
    isStar = true;
    ui->lineEdit_6->setText(QString::number(5));
}





void MainWindow::FigureChanged()
{

    isCircle = false;
    isHexagon = false;
    isStar = false;

    ui->lineEdit->setText(QString::number(temp_item->pos().x()));
    ui->lineEdit_2->setText(QString::number(temp_item->pos().y()));
    ui->lineEdit_3->setText(QString::number(temp_item->rotation()));
    ui->lineEdit_4->setText(QString::number(temp_item->scale()));
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText(QString::number(temp_item->get_Perimeter()));
    ui->lineEdit_8->setText(QString::number(temp_item->get_Area()));

    TimerRotation->stop();
    TimerTranslate->stop();
    TimerScale->stop();
}

void MainWindow::FigureTransform(int x, int y, int angle, double scale)
{
    temp_item->setTransformOriginPoint(200, 250);
    temp_item->setPos(x,y);
    temp_item->setRotation(angle);
    temp_item->setScale(scale);
    ui->lineEdit->setText(QString::number(x));
    ui->lineEdit_2->setText(QString::number(y));
    ui->lineEdit_3->setText(QString::number(angle));
    ui->lineEdit_4->setText(QString::number(scale));
    Point->setPos(temp_item->pos().x(),temp_item->pos().y());
}




void MainWindow::on_pushButton_10_clicked()
{
    if(temp_item == nullptr) {
        QMessageBox::critical(this, "Ошибка", "Объект не создан");
        return;
    }
    if(tools::CheckStringToInt(ui->lineEdit_3->text())) {
        QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
        ui->lineEdit_3->setText("0");
        return;
    }

    QPointF pos = temp_item->get_Center();
    m_angle = ui->lineEdit_3->text().toInt();
    temp_item->setTransformOriginPoint(200, 250 + pos.y());
    if(m_angle < temp_item->rotation()) {
        m_speed_rotate = -1;
    } else {
        m_speed_rotate = 1;
    }
    TimerRotation->start(1000/60);

}


void MainWindow::on_pushButton_9_clicked()
{
    if(temp_item == nullptr) {
        QMessageBox::critical(this, "Ошибка", "Объект не создан");
        return;
    }
    if(tools::CheckStringToInt(ui->lineEdit->text())) {
        QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
        ui->lineEdit->setText("0");
        return;
    }
    if(tools::CheckStringToInt(ui->lineEdit_2->text())) {
        QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
        ui->lineEdit_2->setText("0");
        return;
    }
    x_position = ui->lineEdit->text().toInt();
    y_position = ui->lineEdit_2->text().toInt();
    m_speed_x = (x_position - temp_item->pos().x()) / 120;
    m_speed_y = (y_position - temp_item->pos().y()) / 120;
    TimerTranslate->start(1000/60);
}


void MainWindow::on_pushButton_11_clicked()
{
    if(temp_item == nullptr) {
        QMessageBox::critical(this, "Ошибка", "Объект не создан");
        return;
    }
    if(tools::CheckStringToInt(ui->lineEdit_4->text())) {
        QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
        ui->lineEdit_4->setText("0");
        return;
    }

    QPointF pos = temp_item->get_Center();
    temp_item->setTransformOriginPoint(200, 250 + pos.y());
    m_scale = ui->lineEdit_4->text().toDouble();
    if(temp_item->scale() > m_scale) {
        m_speed_scale = -0.005;
    } else {
        m_speed_scale = 0.005;
    }
    TimerScale->start(1000/60);
}


void MainWindow::on_pushButton_12_clicked()
{
    if(temp_item == nullptr) {
        QMessageBox::critical(this, "Ошибка", "Объект не создан");
        return;
    }
    if(tools::CheckStringToInt(ui->lineEdit_5->text())) {
        QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
        ui->lineEdit_5->setText("0");
        return;
    }

    if(isCircle) {
        int x,y,angle;
        double scale;
        x = temp_item->pos().x();
        y = temp_item->pos().y();

        angle = temp_item->rotation();
        scale = temp_item->scale();

        if(temp_item != nullptr) {
            scene->removeItem(temp_item);
            delete temp_item;
        }
        int number = ui->lineEdit_5->text().toInt();
        temp_item = new circle(number);
        scene->addItem(temp_item);
        FigureChanged();
        FigureTransform(x,y,angle,scale);
        isCircle = true;
        ui->lineEdit_5->setText(QString::number(number));
    }
    if(isStar){

            QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
            ui->lineEdit_5->setText("0");
            return;

    }
}


void MainWindow::on_pushButton_13_clicked()
{
    if(temp_item == nullptr) {
        QMessageBox::critical(this, "Ошибка", "Объект не создан");
        return;
    }
    if(tools::CheckStringToInt(ui->lineEdit_6->text())) {
        QMessageBox::critical(this, "Ошибка", "Некоректный ввод.");
        ui->lineEdit_6->setText("0");
        return;
    }

    if(isStar) {

        if(ui->lineEdit_6->text().toInt() > 4) {

            int x,y,angle;
            double scale;
            x = temp_item->pos().x();
            y = temp_item->pos().y();
            angle = temp_item->rotation();
            scale = temp_item->scale();

            if(temp_item != nullptr) {
                scene->removeItem(temp_item);
                delete temp_item;
            }
            int number = ui->lineEdit_6->text().toInt();
            temp_item = new star(100, number);
            scene->addItem(temp_item);
            FigureChanged();
            FigureTransform(x,y,angle,scale);
            isStar = true;
            ui->lineEdit_6->setText(QString::number(number));
        }
    }
    if(isHexagon) {
        if(ui->lineEdit_6->text().toInt() > 2) {
            int x,y,angle;
            double scale;
            x = temp_item->pos().x();
            y = temp_item->pos().y();
            angle = temp_item->rotation();
            scale = temp_item->scale();
            if(temp_item != nullptr) {
                scene->removeItem(temp_item);
                delete temp_item;
            }
            int number = ui->lineEdit_6->text().toInt();
            temp_item = new hexagon(100, number);
            scene->addItem(temp_item);
            FigureChanged();
            FigureTransform(x,y,angle,scale);
            isHexagon = true;
            ui->lineEdit_6->setText(QString::number(number));
        }
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    canvas *Canvas = new canvas(this);
    Canvas->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    if(temp_item != nullptr) {
        scene->removeItem(temp_item);
        delete temp_item;
    }
    temp_item = new myfigure(100);
    scene->addItem(temp_item);
    FigureChanged();
}


void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked) {
        if(temp_item != nullptr) {
            scene->addItem(Point);
            QPointF pos = temp_item->get_Center();
            Point->setPos(pos.x() + temp_item->pos().x(), pos.y() + temp_item->pos().y());
        }
    } else {
        scene->removeItem(Point);
    }
}




