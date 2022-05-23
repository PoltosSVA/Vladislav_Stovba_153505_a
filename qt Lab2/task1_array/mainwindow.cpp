#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , name__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      sername__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      secondname__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      country__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      team__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      Rost__(QRegularExpression("^[1-9]{2,4}")),
      vse__(QRegularExpression("^[1-9]{2,4}")),
      reg_num__(QRegularExpression("^[1-9]{2,4}")),
      sername___(QRegularExpression("^[A-Z][a-z]{2,17}")),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Range();
    table = new QStandardItemModel(rSize,9,this);
    SOREV = new ArrayList[MaxSize];

    table->setHeaderData(0,Qt::Horizontal,"Имя");//название столбцов
    table->setHeaderData(1,Qt::Horizontal,"Фамилия");
    table->setHeaderData(2,Qt::Horizontal,"Отчество");
    table->setHeaderData(3,Qt::Horizontal,"Страна");
    table->setHeaderData(4,Qt::Horizontal,"Команда");
    table->setHeaderData(5,Qt::Horizontal,"Номер");
    table->setHeaderData(6,Qt::Horizontal,"Рост");
    table->setHeaderData(7,Qt::Horizontal,"Вес");
    table->setHeaderData(8,Qt::Horizontal,"Возраст");

    ui->Name->setValidator(&name__);
    ui->second_name->setValidator(&secondname__);
    ui->ser_name->setValidator(&sername__);
    ui->country->setValidator(&country__);
    ui->team->setValidator(&team__);
    ui->reg_num->setValidator(&reg_num__);


    ui->Ves->setRange(1,100);
    ui->Rost->setRange(1,100);
    ui->Age->setRange(1,100);

    ui->lineEdit->setValidator(&sername___);
    ui->lineEdit_2->setValidator(&vse__);
    ui->lineEdit_3->setValidator(&Rost__);

    ui->tableView->setModel(table);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::return_name()
{
    QString str;
    str=ui->Name->text();
    return  str;
}

QString MainWindow::return_ser_name()
{
    QString str;
    str=ui->ser_name->text();
    return  str;
}

QString MainWindow::return_second_name()
{
    QString str;
    str=ui->second_name->text();
    return  str;
}

QString MainWindow::return_country()
{
    QString str;
    str=ui->country->text();
    return  str;
}

QString MainWindow::return_team()
{
    QString str;
    str=ui->team->text();
    return  str;
}
QString MainWindow::return_reg_num()
{
    QString str;
    str=ui->reg_num->text();
    return  str;

}
QString MainWindow::return_Rost()
{
    QString str;
    str=ui->Rost->text();
    return  str;
}

QString MainWindow::return_ves()
{
    QString str;
    str=ui->Ves->text();
    return  str;
}

QString MainWindow::return_age()
{
    QString str;
    str=ui->Age->text();
    return  str;
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
        QString country = stream.readLine();
        QString team = stream.readLine();
        QString reg_num = stream.readLine();
        QString Rost = stream.readLine();
        QString ves = stream.readLine();
        QString age = stream.readLine();


        Work* library = new Work(name, ser_name, second_name, country,team ,reg_num,Rost,ves,age);
        SOREV[rSize].push_back(library);

        rSize++;



    }
    Range();
    refresh_table();

}
void MainWindow::metodStandart()
{


    QFile file(str);

    file.open(QIODevice::WriteOnly);

    QTextStream stream(&file);

    for(int i=0;i<rSize;i++){

        stream<<  SOREV[i].array->item->get_Name()<<'\n'
        <<SOREV[i].array->item->get_ser_name()<<"\n"
        <<SOREV[i].array->item->get_second_name()<<"\n"
        <<SOREV[i].array->item->get_country()<<"\n"
        <<SOREV[i].array->item->get_team()<<"\n"
        <<SOREV[i].array->item->get_reg_num()<<"\n"
        <<SOREV[i].array->item->get_Rost()<<"\n"
        <<SOREV[i].array->item->get_ves()<<"\n"
        <<SOREV[i].array->item->get_age()<<"\n";


    }


    file.close();
    qDebug()<<"Zap";
}
void MainWindow::on_pushButton_4_clicked()
{



        SOREV->eraseall();

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
void MainWindow::refresh_table()
{

    Range();
    table->setRowCount(rSize);

    qDebug()<<rSize;
    for(int i=0;i<rSize;i++){
        table->setData( table->index(i,0), SOREV[i].array->item->get_Name());
        table->setData( table->index(i,1), SOREV[i].array->item->get_ser_name());
        table->setData( table->index(i,2), SOREV[i].array->item->get_second_name());
        table->setData( table->index(i,3), SOREV[i].array->item->get_country());
        table->setData( table->index(i,4), SOREV[i].array->item->get_team());
        table->setData( table->index(i,5), SOREV[i].array->item->get_reg_num());
        table->setData( table->index(i,6), SOREV[i].array->item->get_Rost());
        table->setData( table->index(i,7), SOREV[i].array->item->get_ves());
        table->setData( table->index(i,8), SOREV[i].array->item->get_age());


    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);


}

void MainWindow::on_pushButton_clicked()
{
    if(str==""){
          QMessageBox::critical(this,"Error","Пустой файл");
          return;

      }
      QString Name = ui->Name->text();
      QString ser_name = ui->ser_name->text();
      QString second_name = ui->second_name->text();
      QString country = ui->country->text();
      QString team = ui->team->text();

      QString reg_num = ui->reg_num->text();
      QString Rost = ui->Rost->text();
      QString ves = ui->Ves->text();
      QString age = ui->Age->text();

      if(return_name()==""||return_second_name()==""||return_ser_name()==""||return_country()==""||return_team()==""||return_reg_num()==""||return_Rost()==""||return_ves()==""||return_age()==""){
              QMessageBox::critical(this,"Error","Присутствуют пустые поля");
              return;
          }
      Work* library = new Work(Name, ser_name, second_name, country,team ,reg_num,Rost,ves,age);
      SOREV[rSize].push_back(library);


//      SOREV[rSize].array->item->set_Name(Name);
//      SOREV[rSize].array->item->set_ser_name(ser_name);
//      SOREV[rSize].array->item->set_second_name(second_name);
//      SOREV[rSize].array->item->set_country(country);
//      SOREV[rSize].array->item->set_team(team);
//      SOREV[rSize].array->item->set_reg_num(reg_num);
//      SOREV[rSize].array->item->set_Rost(Rost);
//      SOREV[rSize].array->item->set_ves(ves);
//      SOREV[rSize].array->item->set_age(age);

       rSize++;
       metodStandart();
       refresh_table();

}

void MainWindow::FileDelete()
{



    int NumDel = ui->spinBox->value();
    ArrayList* new_a = new ArrayList[MaxSize];
    int j = 0;
    for (int n = 0; n < rSize; n++) {
        if (n != NumDel-1)
            new_a[j++] = SOREV[n];
    }



    SOREV = new_a;

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

void MainWindow::on_pushButton_5_clicked()
{
    if(str==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;

    }
    if(rSize==0){
        CheckVoid();
        return;
    }
    int a = ui->spinBox->value();
    SOREV[a-1].erase(a)
            ;
    Range();
    FileDelete();
    refresh_table();
    metodStandart();
}
bool MainWindow::File_deff()
{
    std::regex rt_text("^[A-Za-z]+$");
    for(int i =0;i<rSize;++i){
        if((!std::regex_match(SOREV[i].array->item->get_Name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(SOREV[i].array->item->get_ser_name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(SOREV[i].array->item->get_second_name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(SOREV[i].array->item->get_country().toStdString().c_str(),rt_text))
           ||(!std::regex_match(SOREV[i].array->item->get_team().toStdString().c_str(),rt_text)))
        {
            return false;

        }
    }

    std::regex rx_num("^([1-9])$|^([1-9][0-9])$|^([1-9][0-9][0-9])$|^([1-9][0-9][0-9][0-9])$|(10000)");//  | [1-9][0-9][0-9][0-9] | (10000)");
    for(int i =0;i<rSize;++i){

        if((!std::regex_match(SOREV[i].array->item->get_reg_num().toStdString().c_str(),rx_num))){

            return false;

        }


    }

    return true;
}
void MainWindow::show_Error()
{

    QMessageBox::critical(0,"Error","Поврежденная строка ");



}
void MainWindow::Range(){
    ui->spinBox->setRange(1,rSize);
    ui->spinBox_2->setRange(1,rSize);
}
void MainWindow::on_pushButton_6_clicked()
{
    if(str==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;

    }
    if(rSize==0){
        CheckVoid();
        return;
    }
    int a = ui->spinBox_2->value();

    QString Name = ui->Name->text();
    QString ser_name = ui->ser_name->text();
    QString second_name = ui->second_name->text();
    QString country = ui->country->text();
    QString team = ui->team->text();

    QString reg_num = ui->reg_num->text();
    QString Rost = ui->Rost->text();
    QString ves = ui->Ves->text();
    QString age = ui->Age->text();

    if(return_name()==""||return_second_name()==""||return_ser_name()==""||return_country()==""||return_team()==""||return_reg_num()==""||return_Rost()==""||return_ves()==""||return_age()==""){
            QMessageBox::critical(this,"Error","Присутствуют пустые поля");
            return;
        }

            SOREV[a-1].array->item->set_Name(Name);
            SOREV[a-1].array->item->set_ser_name(ser_name);
            SOREV[a-1].array->item->set_second_name(second_name);
            SOREV[a-1].array->item->set_country(country);
            SOREV[a-1].array->item->set_team(team);
            SOREV[a-1].array->item->set_reg_num(reg_num);
            SOREV[a-1].array->item->set_Rost(Rost);
            SOREV[a-1].array->item->set_ves(ves);
            SOREV[a-1].array->item->set_age(age);

    refresh_table();
    metodStandart();
}





void MainWindow::on_pushButton_7_clicked()
{
    if(vosh){

        on_pushButton_10_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }

    QString from_line_sername = ui->lineEdit->text();

    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_line_sername==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(

           from_line_sername!=SOREV[i].array->item->get_ser_name()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}


void MainWindow::on_pushButton_10_clicked()
{
    for(int i=0;i<rSize;i++){
        ui->tableView->showRow(i);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(vosh){

        on_pushButton_10_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }

    QString from_line_ves = ui->lineEdit_2->text();

    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_line_ves==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(

           from_line_ves!=SOREV[i].array->item->get_ves()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}



void MainWindow::on_pushButton_9_clicked()
{
    if(vosh){

        on_pushButton_10_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }

    QString from_line_Rost = ui->lineEdit_3->text();

    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_line_Rost==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(

           from_line_Rost!=SOREV[i].array->item->get_Rost()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}






bool compare(const QString left, const QString right) {
                return left < right;
}
 void swap(Node* left, Node* right) {
    Node* temp = left;
    left = right;
    right = temp;
}


 void qsortName(ArrayList* array, int left, int right) {

    int l = left;
    int r = right;
    QString mid = array[(l + r) / 2].array->item->name;
    ///SOREV.array[(l + r) / 2]
    while (l <= r) {
        while (compare(array[l].array->item->name, mid))
            l++;

        while (compare(mid, array[r].array->item->name))
            r--;

        if (l <= r) {
            swap(array[l].array->item->name, array[r].array->item->name);
            l++; r--;
        }
    }

    if (left < r)
        qsortName(array, left, r);

    if (l < right)
        qsortName(array, l, right);

};

 void qsortSer_name(ArrayList* array, int left, int right) {

    int l = left;
    int r = right;
    QString mid = array[(l + r) / 2].array->item->ser_name;
    ///SOREV.array[(l + r) / 2]
    while (l <= r) {
        while (compare(array[l].array->item->ser_name, mid))
            l++;

        while (compare(mid, array[r].array->item->ser_name))
            r--;

        if (l <= r) {
            swap(array[l].array->item->ser_name, array[r].array->item->ser_name);
            l++; r--;
        }
    }

    if (left < r)
        qsortSer_name(array, left, r);

    if (l < right)
        qsortSer_name(array, l, right);

};
 void qsortSecond_name(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->second_name;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->second_name, mid))
             l++;

         while (compare(mid, array[r].array->item->second_name))
             r--;

         if (l <= r) {
             swap(array[l].array->item->second_name, array[r].array->item->second_name);
             l++; r--;
         }
     }

     if (left < r)
         qsortSecond_name(array, left, r);

     if (l < right)
         qsortSecond_name(array, l, right);

 };

 void qsortCountry(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->country;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->country, mid))
             l++;

         while (compare(mid, array[r].array->item->country))
             r--;

         if (l <= r) {
             swap(array[l].array->item->country, array[r].array->item->country);
             l++; r--;
         }
     }

     if (left < r)
         qsortCountry(array, left, r);

     if (l < right)
         qsortCountry(array, l, right);

 };

 void qsortTeam(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->team;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->team, mid))
             l++;

         while (compare(mid, array[r].array->item->team))
             r--;

         if (l <= r) {
             swap(array[l].array->item->team, array[r].array->item->team);
             l++; r--;
         }
     }

     if (left < r)
         qsortTeam(array, left, r);

     if (l < right)
         qsortTeam(array, l, right);

 };

 void qsortReg_num(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->reg_num;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->reg_num, mid))
             l++;

         while (compare(mid, array[r].array->item->reg_num))
             r--;

         if (l <= r) {
             swap(array[l].array->item->reg_num, array[r].array->item->reg_num);
             l++; r--;
         }
     }

     if (left < r)
         qsortReg_num(array, left, r);

     if (l < right)
         qsortReg_num(array, l, right);

 };

 void qsortRost(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->Rost;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->Rost, mid))
             l++;

         while (compare(mid, array[r].array->item->Rost))
             r--;

         if (l <= r) {
             swap(array[l].array->item->Rost, array[r].array->item->Rost);
             l++; r--;
         }
     }

     if (left < r)
         qsortRost(array, left, r);

     if (l < right)
         qsortRost(array, l, right);

 };

 void qsortVes(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->ves;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->ves, mid))
             l++;

         while (compare(mid, array[r].array->item->ves))
             r--;

         if (l <= r) {
             swap(array[l].array->item->ves, array[r].array->item->ves);
             l++; r--;
         }
     }

     if (left < r)
         qsortVes(array, left, r);

     if (l < right)
         qsortVes(array, l, right);

 };

 void qsortAge(ArrayList* array, int left, int right) {

     int l = left;
     int r = right;
     QString mid = array[(l + r) / 2].array->item->age;
     ///SOREV.array[(l + r) / 2]
     while (l <= r) {
         while (compare(array[l].array->item->age, mid))
             l++;

         while (compare(mid, array[r].array->item->age))
             r--;

         if (l <= r) {
             swap(array[l].array->item->age, array[r].array->item->age);
             l++; r--;
         }
     }

     if (left < r)
         qsortAge(array, left, r);

     if (l < right)
         qsortAge(array, l, right);

 };

void MainWindow::on_pushButton_2_clicked()
{
    if(str==""){
        QMessageBox::critical(this,"Error","Файл пустой");
        return;
    }
    qsortName(SOREV,0,rSize-1);
    qsortSer_name(SOREV,0,rSize-1);
    qsortSecond_name(SOREV,0,rSize-1);
    qsortCountry(SOREV,0,rSize-1);
    qsortTeam(SOREV,0,rSize-1);
    qsortReg_num(SOREV,0,rSize-1);
    qsortRost(SOREV,0,rSize-1);
    qsortVes(SOREV,0,rSize-1);
    qsortAge(SOREV,0,rSize-1);
    refresh_table();

    metodStandart();
}

