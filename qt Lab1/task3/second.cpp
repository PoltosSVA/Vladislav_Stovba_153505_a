#include "second.h"
#include "ui_second.h"

Second::Second(QWidget *parent) :
    QMainWindow(parent),
    secondui(new Ui::Second)
{
    secondui->setupUi(this);
}

Second::~Second()
{
    delete secondui;
}
