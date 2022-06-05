#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    table = new QStandardItemModel(0, 1, this);
    table->setHeaderData(0, Qt::Horizontal, "Строка-стек");

    uomap = new Unordered_map<int, int, HashFunctor>();


    ui->tableView->setModel(table);

    UpdateTable();

}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::UpdateTable() {
    QModelIndex index;

    auto array = uomap->getArr();

    int countRow = uomap->capacity();

    table->setRowCount(countRow);

    for(int i = 0; i < countRow; ++i) {

        QString string;

        for(auto v : array[i]) {

            string += QString::number(v.first);
        }

        index = table->index(i, 0);

        table->setData(index, string);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int value1 = ui->spinBox->value();
    int value2 = value1;
    values.push_back(value2);
    uomap->insert(std::make_pair(value1, value2));
    UpdateTable();
}


void MainWindow::on_pushButton_2_clicked()
{
    int value = ui->spinBox_2->value();
    uomap->remove(value);
    UpdateTable();
}


void MainWindow::on_pushButton_3_clicked()
{
    bool value = uomap->find(ui->spinBox_3->value());

    QString string;
    string = value ? "true" : "false";
    UpdateTable();
    ui->textEdit->setText(string);
}


void MainWindow::on_pushButton_4_clicked()
{
    uomap->clear();
    UpdateTable();
}

