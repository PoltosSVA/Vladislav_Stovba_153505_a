#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    refresh();

    ui->Flip_spinBox->setRange(0, 31);
    ui->Reset_One_spinBox->setRange(0, 31);
    ui->Test_spinBox->setRange(0, 31);
    ui->set_oper_spinBox->setRange(0, 31);
    ui->set_value_spinBox->setRange(0, 1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh()
{
    QString str = "";

    for(size_t i = 0; i < 32; i++){

        str += QString::number(bits.test(i));
    }

    for(int i = 0; i < str.size() / 2; i++){
        QChar temp = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = temp;
    }

    ui->BitLine->setText(str);

    ui->ULongLine->setText(QString::number(bits.to_ulong()));

    ui->StringLine->setText(bits.to_string());
}

void MainWindow::on_AllButton_clicked()
{
    ui->all_label->setText(QString::number(bits.all()));
}


void MainWindow::on_AnyButton_clicked()
{
    ui->any_label->setText(QString::number(bits.any()));
}


void MainWindow::on_CountButton_clicked()
{
    ui->count_label->setText(QString::number(bits.count()));
}


void MainWindow::on_Flip_all_Button_clicked()
{
    bits.flip();
    refresh();
}


void MainWindow::on_Flip_one_Button_clicked()
{
    bits.flip(ui->Flip_spinBox->value());
    refresh();
}


void MainWindow::on_NoneButton_clicked()
{
    ui->none_label->setText(QString::number(bits.none()));
}


void MainWindow::on_ResetButton_clicked()
{
    bits.reset();
    refresh();
}


void MainWindow::on_ResetOneButton_clicked()
{
    bits.reset(ui->Reset_One_spinBox->value());
    refresh();
}


void MainWindow::on_SetOneButton_clicked()
{
    bits.set(ui->Set_spinBox->value());
    refresh();
}


void MainWindow::on_SetAllButton_clicked()
{
    bits.set();
    refresh();
}


void MainWindow::on_SizeButton_clicked()
{
    ui->size_label->setText(QString::number(bits.size()));
}


void MainWindow::on_TestButton_clicked()
{
    ui->Test_label->setText(QString::number(bits.test(ui->Test_spinBox->value())));
}


void MainWindow::on_SetOperButton_clicked()
{
    bits[ui->set_oper_spinBox->value()] = ui->set_value_spinBox->value();
    refresh();
}
