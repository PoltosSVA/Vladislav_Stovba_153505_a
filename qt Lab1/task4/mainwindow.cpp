#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    name__(QRegularExpression("^[A-Z][a-z]{2,17}")),
    sername__(QRegularExpression("^[A-Z][a-z]{2,17}")),
    secondname__(QRegularExpression("^[A-Z][a-z]{2,17}")),
    publishing__(QRegularExpression("^[A-Z][a-z]{2,17}")),

    booktitle__(QRegularExpression("^[A-Z][a-z]{2,17}"))
{
    ui->setupUi(this);






    ui->lineEdit->setValidator(&name__);
    ui->lineEdit_2->setValidator(&secondname__);
    ui->lineEdit_3->setValidator(&sername__);
    ui->lineEdit_4->setValidator(&publishing__);
    ui->lineEdit_5->setValidator(&booktitle__);


    book_list = new Book[MaxSize];


    table = new QStandardItemModel(rSize,7,this);//создание шаблона таблицы



    table->setHeaderData(0,Qt::Horizontal,"Фамилия");//название столбцов
    table->setHeaderData(1,Qt::Horizontal,"Имя");
    table->setHeaderData(2,Qt::Horizontal,"Отчество");
    table->setHeaderData(3,Qt::Horizontal,"Название");
    table->setHeaderData(4,Qt::Horizontal,"Издательство");
    table->setHeaderData(5,Qt::Horizontal,"Страницы");
    table->setHeaderData(6,Qt::Horizontal,"Год издания");




    ui->tableView->setModel(table);


    Range();
    qDebug()<<rSize;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::LoadTextFile(){

}

void MainWindow::File_Add(){


    QFile file(str);
    if(!file.open(QIODevice::ReadWrite)){
        return;
    }
    file.open(QIODevice::ReadWrite);

    QTextStream stream(&file);

    while(!stream.atEnd()){


        QString name = stream.readLine();
        QString ser_name = stream.readLine();
        QString second_name = stream.readLine();
        QString book_title = stream.readLine();
        QString publishing = stream.readLine();
        QString pages = stream.readLine();
        QString y_publish = stream.readLine();

        book_list[rSize].set_Name(name);
        book_list[rSize].set_ser_name(ser_name);
        book_list[rSize].set_second_name(second_name);
        book_list[rSize].set_book_title(book_title);
        book_list[rSize].set_publishing(publishing);
        book_list[rSize].set_pages(pages);
        book_list[rSize].set_y_publish(y_publish);

        rSize++;



    }
    Range();
    refresh_table();

}

void MainWindow::From_table_to_Massiv()
{
    table->setRowCount(rSize);

   for(int i=0;i<rSize;i++){





       QString name = table->item(i,0)->text();
       QString ser_name = table->item(i,1)->text();
       QString second_name = table->item(i,2)->text();
       QString book_title = table->item(i,3)->text();
       QString publishing = table->item(i,4)->text();
       QString pages = table->item(i,5)->text();
       QString y_publish = table->item(i,6)->text();

       book_list[i].set_Name(name);
       book_list[i].set_ser_name(ser_name);
       book_list[i].set_second_name(second_name);
       book_list[i].set_book_title(book_title);
       book_list[i].set_publishing(publishing);
       book_list[i].set_pages(pages);
       book_list[i].set_y_publish(y_publish);


   }
   for(int i=0;i<rSize;i++){
       qDebug()<< table->item(i,0)->text();
   }




}

void MainWindow::Search_publishing()
{
    int count =0;
    if(vosh){
        on_pushButton_6_clicked();
    }

    QString from_line = ui->lineEdit->text();

    for(int i=0;i<rSize;i++){
        if(from_line==""){
            QMessageBox::critical(this,"Error","Заполните форму");
            return;
        }
        if(from_line!=book_list[i].get_publishing()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }

        }

    }

    vosh = true;


}

void MainWindow::FileDelete()
{




    Book* new_a = new Book[MaxSize];
    int j = 0;
    for (int n = 0; n < rSize; n++) {
        if (n != NumDel - 1)
            new_a[j++] = book_list[n];
    }



    book_list = new_a;

    rSize--;

}

void MainWindow::CheckVoid()
{

    QFile file(str);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString strin = stream.readAll();
    if(strin == ""){
        QMessageBox::critical(0,"Error","Пустой файл");
        return;

    }


}

bool MainWindow::File_deff()
{
    std::regex rt_text("^[A-Za-z]+$");
    for(int i =0;i<rSize;++i){
        if((!std::regex_match(book_list[i].get_Name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(book_list[i].get_ser_name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(book_list[i].get_second_name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(book_list[i].get_book_title().toStdString().c_str(),rt_text))
           ||(!std::regex_match(book_list[i].get_publishing().toStdString().c_str(),rt_text)))
        {
            return false;

        }
    }

    std::regex rx_num("^([1-9])$|^([1-9][0-9])$|^([1-9][0-9][0-9])$|^([1-9][0-9][0-9][0-9])$|(10000)");//  | [1-9][0-9][0-9][0-9] | (10000)");
    for(int i =0;i<rSize;++i){

        if((!std::regex_match(book_list[i].get_pages().toStdString().c_str(),rx_num))){

            return false;

        }

    }
    //qDebug()<<"File_defll"<<File_deff();
    return true;
}

void MainWindow::show_Error()
{

    QMessageBox::critical(0,"Error","Поврежденная строка ");



}

void MainWindow::metodStandart()
{


    QFile file(str);

    file.open(QIODevice::WriteOnly);

    QTextStream stream(&file);

    for(int i=0;i<rSize;i++){

        stream<< book_list[i].get_Name()<<"\n"
                <<book_list[i].get_ser_name()<<"\n"
                <<book_list[i].get_second_name()<<"\n"
                <<book_list[i].get_book_title()<<"\n"
                <<book_list[i].get_publishing()<<"\n"
                <<book_list[i].get_pages()<<"\n"
                <<book_list[i].get_y_publish()<<"\n";


    }


    file.close();
    qDebug()<<"Zap";
}

void MainWindow::metodCheck()
{

    QFile file(str);

    file.open(QIODevice::WriteOnly);

    QTextStream stream(&file);

    for(int i=0;i<rSize;i++){

        stream<< book_list[i].get_Name()<<"\n"
                <<book_list[i].get_ser_name()<<"\n"
                <<book_list[i].get_second_name()<<"\n"
                <<book_list[i].get_book_title()<<"\n"
                <<book_list[i].get_publishing()<<"\n"
                <<book_list[i].get_pages()<<"\n"
                <<book_list[i].get_y_publish()<<"\n";


    }


    file.close();
    qDebug()<<"Zap";
}



void MainWindow::on_pushButton_clicked()//добавить
{
    if(str==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;

    }
    List *list = new List(0,book_list, &rSize);


    list->show();

    connect(list,SIGNAL(refreshTable()),SLOT(refresh_table()));
    connect(list,SIGNAL(sig()),SLOT(metodStandart()));


}





void MainWindow::on_pushButton_5_clicked()
{
    str="";
    exit(0);
}



void MainWindow::refresh_table()
{
    Range();

    table->setRowCount(rSize);


    for(int i=0;i<rSize;i++){
        table->setData( table->index(i,0), book_list[i].get_Name());
        table->setData( table->index(i,1), book_list[i].get_ser_name());
        table->setData( table->index(i,2), book_list[i].get_second_name());
        table->setData( table->index(i,3), book_list[i].get_book_title());
        table->setData( table->index(i,4), book_list[i].get_publishing());
        table->setData( table->index(i,5), book_list[i].get_pages());
        table->setData( table->index(i,6), book_list[i].get_y_publish());
    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);

    qDebug()<<"table";

}





void MainWindow::on_pushButton_3_clicked()
{
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }
    Search_publishing();

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->model()->sort(6,Qt::DescendingOrder);
    From_table_to_Massiv();


    refresh_table();
    metodStandart();
}


void MainWindow::on_pushButton_6_clicked()
{
    for(int i=0;i<rSize;i++){
        ui->tableView->showRow(i);
    }

}


void MainWindow::on_pushButton_7_clicked()//ФИО
{
    if(vosh){

        on_pushButton_6_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }
    QString from_line_name = ui->lineEdit_2->text();
    QString from_line_sername = ui->lineEdit_3->text();
    QString from_line_secondname = ui->lineEdit_4->text();
    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_line_name==""||from_line_sername==""||from_line_secondname==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(
           from_line_name!=book_list[i].get_Name()
           && from_line_sername!=book_list[i].get_ser_name()
           && from_line_secondname != book_list[i].get_second_name()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}


void MainWindow::on_pushButton_8_clicked()//название книги
{
    int count =0;
    if(vosh){
        on_pushButton_6_clicked();
    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }
    QString from_line_book_title = ui->lineEdit_5->text();
    for(int i=0;i<rSize;i++){
        if(from_line_book_title == ""||str==""){
            QMessageBox::critical(this,"Error","Заполните форму");
            return;

        }
        if(from_line_book_title!=book_list[i].get_book_title()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }

    }
    vosh = true;
}


void MainWindow::on_pushButton_10_clicked()//редактирование
{


    if(str==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;

    }
    else{
        Range();
    }
    if(rSize==0){
        CheckVoid();
        return;
    }
     NumEdit = (ui->spinBox_2->text()).toInt();
    Save *save_list = new Save(0,book_list, &NumEdit);


    save_list->show();

    connect(save_list,SIGNAL(Savetable()),SLOT(refresh_table()));

    connect(save_list,SIGNAL(sign()),SLOT(metodStandart()));


}


void MainWindow::on_pushButton_9_clicked()//удаление
{


    if(str==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;

    }
    else{

        Range();
    }
    NumDel = (ui->spinBox->text()).toInt();

          if(rSize==0){
              CheckVoid();
              return;
          }

         FileDelete();
          refresh_table();
          metodStandart();
}




void MainWindow::on_pushButton_2_clicked()
{




    str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "Text files (*.txt)");
    if(check_count ==0&&str==""){
        check_count--;
    }
    ++check_count;

    if(check_count>1 && str==""){
        while(str==""){
            str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "Text files (*.txt)");

            qDebug()<<check_count;
        }
    }

    rSize=0;



    File_Add();

    if(!File_deff()){
        show_Error();
        rSize=0;
        refresh_table();
        return;


    }



}

void MainWindow::Range(){
    ui->spinBox->setRange(1,rSize);
    ui->spinBox_2->setRange(1,rSize);
}
