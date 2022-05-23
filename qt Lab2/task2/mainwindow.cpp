#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include "stack.h"

void MainWindow::add_to_textEdit()
{
    QFile file(str);


    ui->textEdit->setReadOnly(false);
    ui->textEdit->clear();

    file.open(QFile::ReadWrite);

    QTextStream stream(&file);

    ui->textEdit->setText(stream.readAll());



    file.close();

}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "Text files (*.txt)");
    add_to_textEdit();
}


bool MainWindow::balanced(const QString&s) {



    Stack<QChar> stack;
    int size = s.length();

    QChar c;

    for (int i = 0; i <size; i++){


       // qDebug()<<stolb<<"\n";
        qDebug()<<size;
        c = s[i];

        stolb++;
        if(c=='\n'){
            strok++;
            stolb = 0;
        }


        if(c=='('){
            stack.push(')');


        }
        else if(c=='['){
            stack.push(']');

        }
        else if(c=='{'){
            stack.push('}');

        }


        else if(c==')'||c==']'||c=='}'){
            if (stack.empty() || stack.top() != c) {

                            return false;
            }
            stack.pop();

        }


    }

    return stack.empty();
}
void MainWindow::test(const QString& s) {

    if(balanced(s)){
        QMessageBox::information(0,"Error", "Success\n");
    }
    else{
        QString str;
        str = "Строка" + QString::number(strok)+ " " + "Столбец" + QString::number(stolb);
         QMessageBox::information(0,"Error", str);

    }



//     QMessageBox::critical(0,"Error",(balanced(s) ? "yes\n" : "no\n"));
//     if(1){
//         qDebug()<<"Строка"<<strok<<" "<<"Столбец"<<stolb;

//     }

}
void MainWindow::on_pushButton_2_clicked()
{
    QString str2 = ui->textEdit->toPlainText();
    qDebug()<<str2<<"\n";


    test(str2);
    strok = 1;
    stolb = 0;
}

