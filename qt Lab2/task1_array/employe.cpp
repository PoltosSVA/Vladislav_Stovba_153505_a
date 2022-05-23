#include "employe.h"

Employe::Employe()
{

}

Employe::Employe(QString strin):all_str(strin)
{

}

Employe::~Employe()
{

}

Employe::Employe(QString name, QString ser_name, QString second_name, QString country, QString team, QString reg_num, QString Rost, QString ves, QString age) :
    name(name),ser_name(ser_name),second_name(second_name),country(country),team(team),age(age),Rost(Rost),ves(ves),reg_num(reg_num)
{

}
