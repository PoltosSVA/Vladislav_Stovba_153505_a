#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , name__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      sername__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      secondname__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      publishing__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      booktitle__(QRegularExpression("^[A-Z][a-z]{2,17}")),
      reg_num__(QRegularExpression("^[1-9]{2,4}")),

      reg_num___(QRegularExpression("^[1-9]{2,4}")),
      sername___(QRegularExpression("^[A-Z][a-z]{2,17}")),

      booktitle___(QRegularExpression("^[A-Z][a-z]{2,17}")),
      Year___(QRegularExpression ("^[1-9]{2,4}")),

      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Range();

    ui->Year->setRange(1564,2022);
    ui->Pages->setRange(1,2000);
    table = new QStandardItemModel(rSize,8,this);//создание шаблона таблицы

    BOOKS = new List_class[MaxSize];

    ui->Name->setValidator(&name__);
    ui->secondname->setValidator(&secondname__);
    ui->sername->setValidator(&sername__);
    ui->publishing->setValidator(&publishing__);
    ui->book->setValidator(&booktitle__);
    ui->reg_num->setValidator(&reg_num__);
    ui->lineEdit->setValidator(&booktitle___);
    ui->lineEdit_2->setValidator(&Year___);
    ui->lineEdit_3->setValidator(&sername___);
    ui->lineEdit_4->setValidator(&reg_num___);



    table->setHeaderData(0,Qt::Horizontal,"Фамилия");//название столбцов
    table->setHeaderData(1,Qt::Horizontal,"Имя");
    table->setHeaderData(2,Qt::Horizontal,"Отчество");
    table->setHeaderData(3,Qt::Horizontal,"Название");
    table->setHeaderData(4,Qt::Horizontal,"Издательство");
    table->setHeaderData(5,Qt::Horizontal,"Страницы");
    table->setHeaderData(6,Qt::Horizontal,"Год издания");
    table->setHeaderData(7,Qt::Horizontal,"Номер");




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
    str=ui->sername->text();
    return  str;
}

QString MainWindow::return_second_name()
{
    QString str;
    str=ui->secondname->text();
    return  str;
}

QString MainWindow::return_publishing()
{
    QString str;
    str=ui->publishing->text();
    return  str;
}

QString MainWindow::return_book_title()
{
    QString str;
    str=ui->book->text();
    return  str;
}

QString MainWindow::return_pages()
{
    QString str;
    str=ui->Pages->text();
    return  str;
}

QString MainWindow::return_y_publish()
{
    QString str;
    str=ui->Year->text();
    return  str;
}

QString MainWindow::return_reg_num()
{
    QString str;
    str=ui->reg_num->text();
    return  str;

}

void MainWindow::show_Error()
{

    QMessageBox::critical(0,"Error","Поврежденная строка ");



}
void MainWindow::on_pushButton_clicked()
{

    BOOKS->delall();
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
        QString reg_num = stream.readLine();


        Library* library = new Library(name, ser_name, second_name, book_title, publishing,pages,y_publish,reg_num);
        BOOKS->push_back(library);

        rSize++;



    }
    Range();
    refresh_table();

}

bool MainWindow::File_deff()
{
    std::regex rt_text("^[A-Za-z]+$");
    for(int i =0;i<rSize;++i){
        if((!std::regex_match(BOOKS->getitem(i)->item->get_Name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(BOOKS->getitem(i)->item->get_ser_name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(BOOKS->getitem(i)->item->get_second_name().toStdString().c_str(),rt_text))
           ||(!std::regex_match(BOOKS->getitem(i)->item->get_book_title().toStdString().c_str(),rt_text))
           ||(!std::regex_match(BOOKS->getitem(i)->item->get_publishing().toStdString().c_str(),rt_text)))
        {
            return false;

        }
    }

    std::regex rx_num("^([1-9])$|^([1-9][0-9])$|^([1-9][0-9][0-9])$|^([1-9][0-9][0-9][0-9])$|(10000)");//  | [1-9][0-9][0-9][0-9] | (10000)");
    for(int i =0;i<rSize;++i){

        if((!std::regex_match(BOOKS->getitem(i)->item->get_pages().toStdString().c_str(),rx_num))){

            return false;

        }

    }

    return true;
}

void MainWindow::metodStandart()
{


    QFile file(str);

    file.open(QIODevice::WriteOnly);

    QTextStream stream(&file);

    for(int i=0;i<rSize;i++){

        stream<<  BOOKS->getitem(i)->item->get_Name()<<"\n"
        <<BOOKS->getitem(i)->item->get_ser_name()<<"\n"
        <<BOOKS->getitem(i)->item->get_second_name()<<"\n"
        <<BOOKS->getitem(i)->item->get_book_title()<<"\n"
        <<BOOKS->getitem(i)->item->get_publishing()<<"\n"
        <<BOOKS->getitem(i)->item->get_pages()<<"\n"
        <<BOOKS->getitem(i)->item->get_y_publish()<<"\n"
        <<BOOKS->getitem(i)->item->get_reg_num()<<"\n";


    }


    file.close();
    qDebug()<<"Zap";
}

void MainWindow::refresh_table()
{
    Range();

    table->setRowCount(rSize);


    for(int i=0;i<rSize;i++){
        table->setData( table->index(i,0), BOOKS->getitem(i)->item->get_Name());
        table->setData( table->index(i,1), BOOKS->getitem(i)->item->get_ser_name());
        table->setData( table->index(i,2), BOOKS->getitem(i)->item->get_second_name());
        table->setData( table->index(i,3), BOOKS->getitem(i)->item->get_book_title());
        table->setData( table->index(i,4), BOOKS->getitem(i)->item->get_publishing());
        table->setData( table->index(i,5), BOOKS->getitem(i)->item->get_pages());
        table->setData( table->index(i,6), BOOKS->getitem(i)->item->get_y_publish());
        table->setData( table->index(i,7), BOOKS->getitem(i)->item->get_reg_num());


    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);


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
       QString reg_num = table->item(i,7)->text();

       Library* library = new Library(name, ser_name, second_name, book_title, publishing,pages,y_publish,reg_num);
       BOOKS->push_back(library);


   }
   for(int i=0;i<rSize;i++){
       qDebug()<< table->item(i,0)->text();
   }




}

void MainWindow::on_pushButton_2_clicked()
{       if(str==""){
        QMessageBox::critical(this,"Error","Пустой файл");
        return;

    }
    QString Name = ui->Name->text();
    QString ser_name = ui->sername->text();
    QString second_name = ui->secondname->text();
    QString publishing = ui->publishing->text();
    QString book_title = ui->book->text();
    QString Year = ui->Year->text();
    QString Pages = ui->Pages->text();
    QString reg_num = ui->reg_num->text();

    if(return_name()==""||return_second_name()==""||return_ser_name()==""||return_publishing()==""||return_book_title()==""||return_reg_num()==""){
            QMessageBox::critical(this,"Error","Присутствуют пустые поля");
            return;
        }
    Library* library = new Library(Name, ser_name, second_name, book_title, publishing,Pages,Year,reg_num);
    BOOKS->push_back(library);

    qDebug()<<BOOKS;
    rSize++;

     refresh_table();
     metodStandart();

}





void MainWindow::FileDelete()
{



    int NumDel = ui->spinBox->value();
    List_class* new_a = new List_class[MaxSize];
    int j = 0;
    for (int n = 0; n < rSize; n++) {
        if (n != NumDel)
            new_a[j++] = BOOKS[n];
    }



    BOOKS = new_a;

    rSize--;

}
void MainWindow::on_pushButton_4_clicked()//удаление
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
    BOOKS->del(a);
    Range();
    FileDelete();
    refresh_table();
    metodStandart();
}


void MainWindow::on_pushButton_5_clicked()//редактирование
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
    Range();
    QString Name = ui->Name->text();
    QString ser_name = ui->sername->text();
    QString second_name = ui->secondname->text();
    QString publishing = ui->publishing->text();
    QString book_title = ui->book->text();
    QString Year = ui->Year->text();
    QString Pages = ui->Pages->text();
    QString reg_num = ui->reg_num->text();

    if(return_name()==""||return_second_name()==""||return_ser_name()==""||return_publishing()==""||return_book_title()==""||return_reg_num()==""){
            QMessageBox::critical(this,"Error","Присутствуют пустые поля");
            return;
        }

    BOOKS->getitem(a-1)->item->set_Name(Name);
    BOOKS->getitem(a-1)->item->set_ser_name(ser_name);
    BOOKS->getitem(a-1)->item->set_second_name(second_name);
    BOOKS->getitem(a-1)->item->set_book_title(book_title);
    BOOKS->getitem(a-1)->item->set_publishing(publishing);
    BOOKS->getitem(a-1)->item->set_pages(Pages);
    BOOKS->getitem(a-1)->item->set_y_publish(Year);
    BOOKS->getitem(a-1)->item->set_reg_num(reg_num);

    refresh_table();
    metodStandart();



}
void MainWindow::Range(){
    ui->spinBox->setRange(1,rSize);
    ui->spinBox_2->setRange(1,rSize);
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

Node* partition_name(Node* left, Node* right)
{
    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->name <= pivot->item->name)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->name;
            i->item->name = ptr->item->name;
            ptr->item->name = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->name;
    i->item->name = pivot->item->name;
    pivot->item->name = temp;
    return i;
}

void QuickSort_name(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_name(left, right);
        QuickSort_name(left, p->prev);
        QuickSort_name(p->next, right);
    }
}





Node* partition_ser_name(Node* left, Node* right)
{
    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->ser_name <= pivot->item->ser_name)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->ser_name;
            i->item->ser_name = ptr->item->ser_name;
            ptr->item->ser_name = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->ser_name;
    i->item->ser_name = pivot->item->ser_name;
    pivot->item->ser_name = temp;
    return i;
}

void QuickSort_ser_name(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_ser_name(left, right);
        QuickSort_ser_name(left, p->prev);
        QuickSort_ser_name(p->next, right);
    }
}





Node* partition_second_name(Node* left, Node* right)
{
    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->second_name <= pivot->item->second_name)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->second_name;
            i->item->second_name = ptr->item->second_name;
            ptr->item->second_name = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->second_name;
    i->item->second_name = pivot->item->second_name;
    pivot->item->second_name = temp;
    return i;
}

void QuickSort_second_name(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_second_name(left, right);
        QuickSort_second_name(left, p->prev);
        QuickSort_second_name(p->next, right);
    }
}








Node* partition_publishing(Node* left, Node* right)
{
    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->publishing <= pivot->item->publishing)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->publishing;
            i->item->publishing = ptr->item->publishing;
            ptr->item->publishing = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->publishing;
    i->item->publishing = pivot->item->publishing;
    pivot->item->publishing = temp;
    return i;
}

void QuickSort_publishing(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_publishing(left, right);
        QuickSort_publishing(left, p->prev);
        QuickSort_publishing(p->next, right);
    }
}






Node* partition_book_title(Node* left, Node* right)
{
    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->book_title <= pivot->item->book_title)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->book_title;
            i->item->book_title = ptr->item->book_title;
            ptr->item->book_title = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->book_title;
    i->item->book_title = pivot->item->book_title;
    pivot->item->book_title = temp;
    return i;
}

void QuickSort_book_title(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_book_title(left, right);
        QuickSort_book_title(left, p->prev);
        QuickSort_book_title(p->next, right);
    }
}



Node* partition_pages(Node* left, Node* right)
{

    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->pages <= pivot->item->pages)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->pages;
            i->item->pages = ptr->item->pages;
            ptr->item->pages = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->pages;
    i->item->pages = pivot->item->pages;
    pivot->item->pages = temp;
    return i;
}

void QuickSort_pages(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_pages(left, right);
        QuickSort_pages(left, p->prev);
        QuickSort_pages(p->next, right);
    }
}




Node* partition_y_publish(Node* left, Node* right)
{

    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->y_publish <= pivot->item->y_publish)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->y_publish;
            i->item->y_publish = ptr->item->y_publish;
            ptr->item->y_publish = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->y_publish;
    i->item->y_publish = pivot->item->y_publish;
    pivot->item->y_publish = temp;
    return i;
}

void QuickSort_y_publish(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_y_publish(left, right);
        QuickSort_y_publish(left, p->prev);
        QuickSort_y_publish(p->next, right);
    }
}








Node* partition_reg_num(Node* left, Node* right)
{

    Node* pivot = right;
    Node* i = left->prev;
    for (Node* ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->item->reg_num <= pivot->item->reg_num)
        {
            i = (i == nullptr ? left : i->next);
            QString temp = i->item->reg_num;
            i->item->reg_num = ptr->item->reg_num;
            ptr->item->reg_num = temp;
        }
    }
    i = (i == nullptr ? left : i->next);
    QString temp = i->item->reg_num;
    i->item->reg_num = pivot->item->reg_num;
    pivot->item->reg_num = temp;
    return i;
}

void QuickSort_reg_num(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->next)
    {
        Node* p = partition_reg_num(left, right);
        QuickSort_reg_num(left, p->prev);
        QuickSort_reg_num(p->next, right);
    }
}







void MainWindow::on_pushButton_3_clicked()
{




    if(str==""){
        QMessageBox::critical(this,"Error","Файл пустой");
        return;
    }


        QuickSort_name(BOOKS->getfront(),BOOKS->getback());



           QuickSort_ser_name(BOOKS->getfront(),BOOKS->getback());


        QuickSort_second_name(BOOKS->getfront(),BOOKS->getback());



        QuickSort_book_title(BOOKS->getfront(),BOOKS->getback());



        QuickSort_publishing(BOOKS->getfront(),BOOKS->getback());




        QuickSort_pages(BOOKS->getfront(),BOOKS->getback());




        QuickSort_y_publish(BOOKS->getfront(),BOOKS->getback());
        refresh_table();
        metodStandart();


        QuickSort_reg_num(BOOKS->getfront(),BOOKS->getback());



        refresh_table();
        metodStandart();




}
//Node* search(Library* item_search) {
//    if (!is_empty()) {
//        Node* p = Head;
//        while (p && p->item != item_search) {
//            p = p->next;
//        }
//        return (p && p->item == item_search) ? p : nullptr;
//    }

//    return nullptr;
//}

void MainWindow::on_pushButton_7_clicked()//фамилия
{
    if(vosh){

        on_pushButton_9_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }

    QString from_line_sername = ui->lineEdit_3->text();

    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_line_sername==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(

           from_line_sername!=BOOKS->getitem(i)->item->get_ser_name()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}


void MainWindow::on_pushButton_9_clicked()//шоу
{
    for(int i=0;i<rSize;i++){
        ui->tableView->showRow(i);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(vosh){

        on_pushButton_9_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }

    QString from_line_reg_num = ui->lineEdit_4->text();

    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_line_reg_num==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(

           from_line_reg_num!=BOOKS->getitem(i)->item->get_reg_num()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}


void MainWindow::on_pushButton_6_clicked()
{
    if(vosh){

        on_pushButton_9_clicked();

    }
    if(str==""){
        QMessageBox::critical(this,"Error","Файл не открыт");
        return;
    }
    QString from_book_title = ui->lineEdit->text();
    QString from_y_publishing = ui->lineEdit_2->text();

    int count =0;
    for(int i=0;i<rSize;i++){

        if(from_book_title==""||from_y_publishing==""||str==""){


                QMessageBox::critical(this,"Error","Заполните форму");
                return;




        }
        else if(
           from_book_title!=BOOKS->getitem(i)->item->get_book_title()
           &&
                from_y_publishing!=BOOKS->getitem(i)->item->get_y_publish()){

            ui->tableView->hideRow(i);
            count++;
            if(count==rSize){
                QMessageBox::warning(0,"Warning","Нет совпадений");
            }
        }
    }

    vosh = true;
}

