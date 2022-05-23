#include "Mass.h"
#include <QDebug>
Mass::Mass()
{

}

Mass::Mass(double a, double b, double c, double d, double e, double result, QString name):a(a),b(b),c(c),d(d),e(e),result(result),name(name)
{

}

Mass::~Mass()
{

}

Mass::Mass(QString strin):all_str(strin)
{

}

void Mass::set_Name(QString name){
    this->name = name;

}
void Mass::set_a(QString a){

    this->a = a.toDouble();

}
void Mass::set_b(QString b){
    this->b = b.toDouble();
}
void Mass::set_c(QString c){
    this->c = c.toDouble();
}
void Mass::set_d(QString d){
    this->d = d.toDouble();
}
void Mass::set_e(QString e){
    this->e = e.toDouble();
}
void Mass::set_result(QString result){
    this->result = result.toDouble();
}





QString Mass::get_Name(){

    return (QString)name;
}
QString Mass::get_a(){

    return QString::number(a,'g',6);
}
QString Mass::get_b(){

     return QString::number(b,'g',6);
}
QString Mass::get_c(){

    return QString::number(c,'g',6);
}
QString Mass::get_d(){

    return QString::number(d,'g',6);
}
QString Mass::get_e(){

    return QString::number(e,'g',6);
}
QString Mass::get_result(){

    return QString::number(result,'g',6);
}
