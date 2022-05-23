#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <regex>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->setRange(0,rSize);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_Error(){
    QMessageBox::critical(0,"Error","Поврежденная строка ");
}


bool MainWindow::Fail_deff(QString sof)
{
    std::regex rx("((0[1-9]|[12][0-9]|3[01])[- /.]"
    "(0[1-9]|1[012])[- /.]"
    "([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}))");

    if (sof.length() < 10 || sof[2] != '.' || sof[5] != '.')
    return false;

    if (!std::regex_match(sof.toStdString().c_str(), rx))
    return false;

    QString sday = "";
    for (int i = 0; i < 2; i++) {
    QString tmp = sof[i];
    sday += tmp;
    }

    QString smonth = "";
    for (int i = 3; i < 5; i++) {
    QString tmp = sof[i];
    smonth += tmp;
    }

    QString syear = "";
    for (int i = 6; i < 10; i++) {
    QString tmp = sof[i];
    syear += tmp;
    }

    int sec_day = sday.toInt();
    int sec_month = smonth.toInt();


    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (sec_day > daysInMonth[sec_month - 1])
        return false;

    return true;
}


void MainWindow::LoadFromFile(QFile &File){

    if(!File.open(QIODevice::ReadWrite)){
        qDebug()<< "Файл не открыт";
        return;
    }

    int MasSize= 40;
    int rSize=0;

    QTextStream stream(&File);
    stream.seek(0);

    Date *list = new Date[MasSize];

    while(!stream.atEnd()){

        QString str = stream.readLine();
        QList deff = str.split(".");

        Date date(deff[0].toInt(),deff[1].toInt(),deff[2].toInt());

        list[rSize]=date;
        rSize++;

        if(rSize==MasSize){

            list = fCheck(list,rSize,MasSize);

        }

    }

    File.close();

   QStandardItemModel *table = new QStandardItemModel(rSize,5,this);

    ui->spinBox->setRange(1,rSize);



    ui->tableView->setModel(table);


    for(int i = 0; i < table->rowCount(); i++){
        Date Current_Date(QDate::currentDate().day(),QDate::currentDate().month(),QDate::currentDate().year());

        table->setData( table->index(i,0), list[i].toStr());
        table->setData( table->index(i,1), list[i].NextDay().toStr());
        table->setData( table->index(i,2), list[i].Duration(Current_Date));
        table->setData( table->index(i,3), list[i].PreviousDay().toStr());
        table->setData( table->index(i,4), list[i].WeekNumber());
    }

    for (int i = 0; i < table->rowCount(); i++)
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);



    table->setHeaderData(0,Qt::Horizontal,"Дата");
    table->setHeaderData(1,Qt::Horizontal,"Следующий день");
    table->setHeaderData(2,Qt::Horizontal,"Разница");
    table->setHeaderData(3,Qt::Horizontal,"Предыдущий день");
    table->setHeaderData(4,Qt::Horizontal,"Номер недели");

    delete[] list;




}

Date* MainWindow::fCheck(Date *date, int rSize, int& MasSize)
{
    int N=MasSize+20;
    MasSize = N;
    Date *new_date = new Date[N];
    for(int i=0;i<rSize;i++){
        new_date[i]=date[i];
    }

    delete [] date;
    return new_date;

}//-----

Date ConvertDate(QDate New_Entered_Date){
    Date converted_date(New_Entered_Date.day(),New_Entered_Date.month(), New_Entered_Date.year());
    return converted_date;
}//-----

void MainWindow::on_pushButton_clicked()//добавить
{
    QFile file(str);
    if (str == ""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;
    }
    file.open(QIODevice::Append | QIODevice::Text);


    QDate New_Entered_Date = ui->dateEdit->date();
    Date Added_Date = ConvertDate(New_Entered_Date);

    QString Date_String = Added_Date.toStr();

    QTextStream stream(&file);
    stream << Date_String << "\n";

    file.close();

    Add_Date();
}//------


void MainWindow::on_pushButton_2_clicked()//редактирование
{

    if (str == ""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;
    }
    QDate New_Entered_Date = ui->dateEdit_2->date();
    Date New_Date = ConvertDate(New_Entered_Date);

    int NumToChange = (ui->spinBox->text()).toInt();

    EditFile(New_Date,NumToChange);
    Add_Date();

}//------

void MainWindow::on_pushButton_3_clicked()
{

     str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "Text files (*.txt)");//Файл

     rSize=0;

     Add_Date();


}//-------


void MainWindow::on_pushButton_4_clicked()//др
{
    QDate Birthday_Date = ui->dateEdit_4->date();
    Date Birth_Date = ConvertDate(Birthday_Date);

    Date Current_Date(QDate::currentDate().day(),QDate::currentDate().month(),QDate::currentDate().year());
    if(Current_Date.DaysTillBithday(Birth_Date) == 0)


        ui->label->setText("Сегодня др");
    else
        ui->label->setText("До др: " + QString::number(Current_Date.DaysTillBithday(Birth_Date)));
}


void MainWindow::EditFile(Date New_Date, int NumToChange){

    QFile file(str);
    if (str == ""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;
    }
    file.open(QIODevice::ReadWrite);

    QTextStream stream(&file);
    stream.seek(12 * (NumToChange - 1));

    QString Date_String = New_Date.toStr();
    stream << Date_String;

    file.close();
}//------






void MainWindow::Add_Date()
{
    QFile file(str);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    stream.seek(0);

    while(!stream.atEnd()){
        QString strin = stream.readLine();

        if(!Fail_deff(strin)){
            show_Error();
            exit(0);
        }
    }
    file.close();

    if (str == ""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;
    }
    LoadFromFile(file);
}//-------

