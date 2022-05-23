#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
class Employe
{
public:
    Employe();

    Employe (QString strin);
    ~Employe();
    Employe(QString name, QString ser_name, QString second_name, QString country, QString team, QString reg_num, QString Rost, QString ves, QString age);
public:

    QString all_str;

    QString name;
    QString ser_name;
    QString second_name;
    QString country;
    QString team;

    QString age;
    QString Rost;
    QString ves;
    QString reg_num;
};

#endif // EMPLOYE_H
