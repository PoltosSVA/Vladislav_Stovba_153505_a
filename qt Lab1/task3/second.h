#ifndef SECOND_H
#define SECOND_H

#include <QMainWindow>

namespace Ui {
class Second;
}

class Second : public QMainWindow
{
    Q_OBJECT

public:
    explicit Second(QWidget *parent = nullptr);
    ~Second();
signals:
    void second();
private:
    Ui::Second *secondui;
};

#endif // SECOND_H
