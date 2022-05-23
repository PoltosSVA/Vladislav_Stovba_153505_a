#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),

      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Range();
    table = new QStandardItemModel(rSize,1,this);
    SOREV = new List_class[MaxSize];

    table->setHeaderData(0,Qt::Horizontal,"Строки");//название столбцов


    ui->tableView->setModel(table);
}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(0, "Open File", "", "(*.cpp)");//получил путь к файлу
    /*
        дальше нужно закинуть все содержимое файла в textEdit
    */
    ReadFile();
}

void MainWindow::ReadFile()
{
    if(filePath == "") {
        return;
    }

    QFile file(filePath);
    if(!file.open(QFile::ReadOnly)) {
        QMessageBox::information(this, "Ошибка", "Файл не открыт");
        return;
    }
    QTextStream in(&file);

    text = in.readAll();//Взял все из файла

    ui->textEdit->setText(text);
    /*
        Сейчас все в textEdit
    */


}
void MainWindow::on_pushButton_4_clicked()
{

    if(filePath==""){
        return;
    }

    QString fullLine = text+'\r'+'\n';

    QString soloLine = "";

    int counter =0;

    int fullLen = fullLine.length();



    while(counter<fullLen){

        while(fullLine[counter]!='\n'&&counter<fullLen){

            soloLine.push_back(fullLine[counter++]);

        }

        counter++;



        Library* str = new Library(soloLine);


        SOREV->push_back(str);

        rSize++;
        soloLine = "";
    }
    Range();
    refresh_table();

}



//void MainWindow::FileDelete()
//{

//    int NumDel = ui->spinBox_3->value();
//    ArrayList* new_a = new ArrayList[MaxSize];
//    int j = 0;
//    for (int n = 0; n < rSize; n++) {
//        if (n != NumDel-1)
//            new_a[j++] = SOREV[n];
//    }



//    SOREV = new_a;

//    rSize--;

//}
void MainWindow::Replace_Code(){


    int start = ui->spinBox->value();//5

    int end = ui->spinBox_2->value();//6

    int pos = ui->spinBox_3->value();//2

    int num = end - start+1;//2
    if(num<0){
        num= num * (-1);
    }
    while(num){
        num--;
        Library* mas= new Library(SOREV->getitem(start - 1)->item->get_Name());
        SOREV->insert(pos,*mas);
        pos++;
        start+=2;
        rSize++;
    }


//    Library* mas= new Library(SOREV->getitem(0)->item->get_Name());
//    SOREV->insert(2,*mas);
//    mas= new Library(SOREV->getitem(0)->item->get_Name());
//    SOREV->insert(3,*mas);

    refresh_table();


    QMessageBox::information(this, "info", "success");
    exit(0);
}
void MainWindow::on_pushButton_2_clicked()
{
    if(filePath==""){
        return;
    }
    Replace_Code();
}
void MainWindow::on_pushButton_3_clicked()
{
    if(filePath==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;
    }

}

void MainWindow::refresh_table()//обнова таблицы
{

    Range();
    table->setRowCount(rSize);


    for(int i=0;i<rSize;i++){
        table->setData( table->index(i,0), SOREV->getitem(i)->item->get_Name());

    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);


}

//QString MainWindow::return_name()
//{
//    QString str;
//    str=ui->Name->text();
//    return  str;
//}



//void MainWindow::File_Add(){


//    QFile file(str);
//    if(!file.open(QIODevice::ReadWrite)){
//        return;
//    }

//    file.open(QIODevice::ReadWrite);

//    QTextStream stream(&file);

//    while(!stream.atEnd()){


//        QString name = stream.readLine();



//        Work* library = new Work(name);
//        SOREV[rSize].push_back(library);

//        rSize++;



//    }




//    QTextStream in(&file);
//    isFile = true;
//    text = in.readAll().toStdString();







//    Range();
//    refresh_table();

//}
//void MainWindow::metodStandart()
//{


//    QFile file(str);

//    file.open(QIODevice::WriteOnly);

//    QTextStream stream(&file);

//    for(int i=0;i<rSize;i++){

//        stream<<  SOREV[i].array->item->get_Name()<<'\n';



//    }


//    file.close();
//    qDebug()<<"Zap";
//}



////void MainWindow::on_pushButton_clicked()
////{
////    if(str==""){
////          QMessageBox::critical(this,"Error","Пустой файл");
////          return;

////      }
////      QString Name = ui->Name->text();
////      QString ser_name = ui->ser_name->text();
////      QString second_name = ui->second_name->text();
////      QString country = ui->country->text();
////      QString team = ui->team->text();

////      QString reg_num = ui->reg_num->text();
////      QString Rost = ui->Rost->text();
////      QString ves = ui->Ves->text();
////      QString age = ui->Age->text();

////      if(return_name()==""||return_second_name()==""||return_ser_name()==""||return_country()==""||return_team()==""||return_reg_num()==""||return_Rost()==""||return_ves()==""||return_age()==""){
////              QMessageBox::critical(this,"Error","Присутствуют пустые поля");
////              return;
////          }
////      Work* library = new Work(Name);
////      SOREV[rSize].push_back(library);


//////      SOREV[rSize].array->item->set_Name(Name);
//////      SOREV[rSize].array->item->set_ser_name(ser_name);
//////      SOREV[rSize].array->item->set_second_name(second_name);
//////      SOREV[rSize].array->item->set_country(country);
//////      SOREV[rSize].array->item->set_team(team);
//////      SOREV[rSize].array->item->set_reg_num(reg_num);
//////      SOREV[rSize].array->item->set_Rost(Rost);
//////      SOREV[rSize].array->item->set_ves(ves);
//////      SOREV[rSize].array->item->set_age(age);

////       rSize++;
////       metodStandart();
////       refresh_table();

////}






//void MainWindow::CheckVoid()
//{

//    QFile file(str);
//    file.open(QIODevice::ReadOnly);
//    QTextStream stream(&file);
//    QString strin = stream.readAll();
//    if(strin == ""){
//        QMessageBox::critical(0,"Error","Пустой файл");
//        return;

//    }


//}

//void MainWindow::on_pushButton_5_clicked()
//{
//    if(str==""){
//        QMessageBox::critical(this,"Error","Пустой файл");
//        return;

//    }
//    if(rSize==0){
//        CheckVoid();
//        return;
//    }
//    int a = ui->spinBox->value();
//    SOREV[a-1].erase(a)
//            ;
//    Range();
//    FileDelete();
//    refresh_table();
//    metodStandart();
//}

//void MainWindow::show_Error()
//{

//    QMessageBox::critical(0,"Error","Поврежденная строка ");



//}
void MainWindow::Range(){
    ui->spinBox->setRange(1,rSize);
    ui->spinBox_2->setRange(1,rSize);
    ui->spinBox_3->setRange(1,rSize);
}



//bool compare(const QString left, const QString right) {
//                return left < right;
//}
// void swap(Node* left, Node* right) {
//    Node* temp = left;
//    left = right;
//    right = temp;
//}













