 #include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mass = new Mass[MaxSize];
    KAVO();
    table = new QStandardItemModel(rSize,7,this);//создание шаблона таблицы



    table->setHeaderData(0,Qt::Horizontal,"Выражение");//название столбцов
    table->setHeaderData(1,Qt::Horizontal,"a");
    table->setHeaderData(2,Qt::Horizontal,"b");
    table->setHeaderData(3,Qt::Horizontal,"c");
    table->setHeaderData(4,Qt::Horizontal,"d");
    table->setHeaderData(5,Qt::Horizontal,"e");
    table->setHeaderData(6,Qt::Horizontal,"Результат");



    ui->tableView->setModel(table);

    ui->Result->setReadOnly(true);
    ui->translate->setReadOnly(true);
    refresh_table();

}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::Res(QString str)
{
    Stack<double> stack;
    QChar s_ch;
    double num_1,num_2,res;

    double a_n = ui->AA->value();
    double b_n = ui->BB->value();
    double c_n = ui->CC->value();
    double d_n = ui->DD->value();
    double e_n = ui->EE->value();

    for(int i=0;i<str.length();i++){
          s_ch = str[i];
          if(s_ch=='a'){
              stack.push(a_n);
          }

          else if(s_ch=='b'){
              stack.push(b_n);
          }

          else if(s_ch=='c'){
              stack.push(c_n);
          }


          else if(s_ch=='d'){
              stack.push(d_n);
          }


          else if(s_ch=='e'){
              stack.push(e_n);
          }

          else if(s_ch=='-'||s_ch=='+'||s_ch=='*'||s_ch=='/'){
              num_2 = stack.pop();
              num_1 = stack.pop();

              if(s_ch=='-'){
                  res = num_1-num_2;
                  stack.push(res);
              }
              else if(s_ch=='+'){
                  res = num_1+num_2;
                  stack.push(res);
              }
              else if(s_ch=='*'){
                  res = num_1*num_2;
                  stack.push(res);
              }
              else if(s_ch=='/'){
                  res = num_1/num_2;
                  stack.push(res);
                  if(num_2==0){
                      QMessageBox::critical(0,"Error","Деление на ноль");
                      error++;
                      return error ;
                  }
              }

          }


    }
    return stack.pop();



}





void MainWindow::refresh_table(){

    table->setRowCount(rSize);


    for(int i=0;i<rSize;i++){
        table->setData( table->index(i,0), mass[i].get_Name());
        table->setData( table->index(i,1), mass[i].get_a());
        table->setData( table->index(i,2), mass[i].get_b());
        table->setData( table->index(i,3), mass[i].get_c());
        table->setData( table->index(i,4), mass[i].get_d());
        table->setData( table->index(i,5), mass[i].get_e());
        table->setData( table->index(i,6), mass[i].get_result());
    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);
}

void MainWindow::KAVO()
{



      mass[0].set_Name("a/(b–c)*(d+e)");
      mass[0].set_a("8.6");
      mass[0].set_b("2.4");
      mass[0].set_c("5.1");
      mass[0].set_d("0.3");
      mass[0].set_e("7.9");
      mass[0].set_result("-26.12");

      mass[1].set_Name("(a+b)*(c– d)/e");
      mass[1].set_a("7.4");
      mass[1].set_b("3.6");
      mass[1].set_c("2.8");
      mass[1].set_d("9.5");
      mass[1].set_e("0.9");
      mass[1].set_result("-81.89");

      mass[2].set_Name("a– (b+c*d)/e");
      mass[2].set_a("3.1");
      mass[2].set_b("5.4");
      mass[2].set_c("0.2");
      mass[2].set_d("9.6");
      mass[2].set_e("7.8");
      mass[2].set_result("2.16");

      mass[3].set_Name("a/b–((c+d)*e)");
      mass[3].set_a("1.2");
      mass[3].set_b("0.7");
      mass[3].set_c("9.3");
      mass[3].set_d("6.5");
      mass[3].set_e("8.4");
      mass[3].set_result("-131.006");

      mass[4].set_Name("a*(b– c+d)/e)");
      mass[4].set_a("9.7)");
      mass[4].set_b("8.2");
      mass[4].set_c("3.6");
      mass[4].set_d("4.1");
      mass[4].set_e("0.5");
      mass[4].set_result("168.78");

      mass[5].set_Name("(a+b)*(c– d)/e");
      mass[5].set_a("0.8");
      mass[5].set_b("4.1");
      mass[5].set_c("7.9");
      mass[5].set_d("6.2");
      mass[5].set_e("3.5");
      mass[5].set_result("2.38");


      mass[6].set_Name("a*(b– c)/(d+e)");
      mass[6].set_a("1.6");
      mass[6].set_b("4.9");
      mass[6].set_c("5.7");
      mass[6].set_d("0.8");
      mass[6].set_e("2.3");
      mass[6].set_result("-0.413");

      mass[7].set_Name("a/(b*(c+d))– e");
      mass[7].set_a("8.5");
      mass[7].set_b("0.3");
      mass[7].set_c("2.4");
      mass[7].set_d("7.9");
      mass[7].set_e("1.6");
      mass[7].set_result("1.151");

      mass[8].set_Name("(a+(b/c– d))*e");
      mass[8].set_a("5.6");
      mass[8].set_b("7.4");
      mass[8].set_c("8.9");
      mass[8].set_d("3.1");
      mass[8].set_e("0.2");
      mass[8].set_result("0.666");

      mass[9].set_Name("a*(b+c)/(d– e)");
      mass[9].set_a("0.4");
      mass[9].set_b("2.3");
      mass[9].set_c("6.7");
      mass[9].set_d("5.8");
      mass[9].set_e("9.1");
      mass[9].set_result("-1.091");

      mass[10].set_Name("a– (b/c*(d+e))");
      mass[10].set_a("5.6");
      mass[10].set_b("3.2");
      mass[10].set_c("0.9");
      mass[10].set_d("1.7");
      mass[10].set_e("4.8");
      mass[10].set_result("-17.51");

      mass[11].set_Name("(a– b)/(c+d)*e");
      mass[11].set_a("0.3");
      mass[11].set_b("6.7");
      mass[11].set_c("8.4");
      mass[11].set_d("9.5");
      mass[11].set_e("1.2");
      mass[11].set_result("-0.429");

      mass[12].set_Name("a/(b+c– d*e)");
      mass[12].set_a("7.6");
      mass[12].set_b("4.8");
      mass[12].set_c("3.5");
      mass[12].set_d("9.1");
      mass[12].set_e("0.2");
      mass[12].set_result("1.173");

      mass[13].set_Name("a*(b– c)/(d+e)");
      mass[13].set_a("0.5");
      mass[13].set_b("6.1");
      mass[13].set_c("8.9");
      mass[13].set_d("2.4");
      mass[13].set_e("7.3");
      mass[13].set_result("-0.144");

      mass[14].set_Name("(a+b*c)/(d– e)");
      mass[14].set_a("9.1");
      mass[14].set_b("0.6");
      mass[14].set_c("2.4");
      mass[14].set_d("3.7");
      mass[14].set_e("8.5");
      mass[14].set_result("-2.196");



}

QString MainWindow::check(QString str)
{
    int size = str.size();

    for(int i=0;i<size;i++){
        if(str[i]==','){
            str[i]='.';
        }
    }
    return str;
}



    int Prior(QChar a){
        if(a=='*'||a=='/'){
            return 3;
        }
        else if(a =='+'||a=='-'){
            return 2;
        }
        else if(a=='('){
            return 1;
        }
        return 0;
    }

void MainWindow::Translate(){
    Stack<QChar> stack;



    QString it_str,out_str;
    QChar s_ch;
    stack.root = NULL;
    it_str = ui->Name->text();

    int size = it_str.length();

    for(int i =0;i<size;i++){

        s_ch = it_str[i];




        if(s_ch == '('){
            stack.push(s_ch);
        }

        if(s_ch==')'){
            while(stack.top()!='('){

                out_str+=stack.pop();

            }
            stack.pop();
        }


        if(s_ch>='a'&&s_ch<='e'){
            out_str+=s_ch;
        }

        if(s_ch=='+'||s_ch=='-'||s_ch=='*'||s_ch=='/'){
            while(stack.root!=NULL && Prior(stack.top())>=Prior(s_ch)){
                out_str += stack.pop();
            }
            stack.push(s_ch);
        }
    }
        while(stack.root!=NULL){
            out_str+=stack.pop();
        }
        qDebug()<<"SHA";
        ui->translate->setText(out_str);



}


void MainWindow::on_pushButton_2_clicked()
{


    QString str_name = ui->Name->text();
    if(!isCorrect()){
        QMessageBox::critical(0,"Error","Ошибка");
        return;
    }
    Translate();
    QString str_a = ui->AA->text();

    QString str_b = ui->BB->text();

    QString str_c = ui->CC->text();

    QString str_d = ui->DD->text();

    QString str_e = ui->EE->text();



    str_a=check(str_a);
    str_b=check(str_b);
    str_c=check(str_c);
    str_d=check(str_d);
    str_e=check(str_e);


    QString str = ui->translate->text();
    double a =Res(str);

    if(error){
        error--;
        return;
    }

    qDebug()<<a;
    QString r = QString::number(a,'g',6);
    ui->Result->setText(r);

    QString str_result = ui->Result->text();
    str_result=check(str_result);

    mass[rSize].set_Name(str_name);
    mass[rSize].set_a(str_a);
    mass[rSize].set_b(str_b);
    mass[rSize].set_c(str_c);
    mass[rSize].set_d(str_d);
    mass[rSize].set_e(str_e);
    mass[rSize].set_result(str_result);
    rSize++;




    refresh_table();


}
bool MainWindow::isCorrect() {

QString infix = ui->Name->text();
QString expression = infix;

int bracket = 0;
for (int i = 0; i < expression.size(); i++){
    if (expression[i] == '(')
        bracket++;
    else if (expression[i] == ')')
        bracket--;
}
if (bracket != 0)
    return false;

if (expression.size() == 0)
    return false;


for (int i = 0; i < expression.size(); i++) {

    QChar c = expression[i];
    if (!(c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')' ||
    ('a' <= c && c <= 'e')))
        return false;

    if (i + 1 < expression.size()) {
        QChar next = expression[i + 1];
        if (c >= 'a' && c <= 'e' && ((next >= 'a' && next <= 'e') || next == '('))
            return false;
    }
}

if(expression[0]=='+'||expression[0]=='-'||expression[0]=='/'||expression[0]=='*')
    return false;

if(expression.size()>255)
    return false;



return true;
}
