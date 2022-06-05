#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitset.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refresh();
private slots:
    void on_AllButton_clicked();

    void on_AnyButton_clicked();

    void on_CountButton_clicked();

    void on_Flip_all_Button_clicked();

    void on_Flip_one_Button_clicked();

    void on_NoneButton_clicked();

    void on_ResetButton_clicked();

    void on_ResetOneButton_clicked();

    void on_SetOneButton_clicked();

    void on_SetAllButton_clicked();

    void on_SizeButton_clicked();

    void on_TestButton_clicked();

    void on_SetOperButton_clicked();

private:
    Ui::MainWindow *ui;
    bitset<32> bits;
};
#endif // MAINWINDOW_H
