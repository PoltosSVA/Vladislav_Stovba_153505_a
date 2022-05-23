#ifndef MASS_H
#define MASS_H

#include <QString>
class Mass
{
public:
    Mass();
    Mass(double a,double b,double c,double d,double e,double result,QString name);
    ~Mass();
    Mass(QString strin);

public:
    void set_Name(QString name);
    void set_a(QString a);
    void set_b(QString b);
    void set_c(QString c);
    void set_d(QString d);
    void set_e(QString e);
    void set_result(QString result);





    QString get_Name();
    QString get_a();
    QString get_b();
    QString get_c();
    QString get_d();
    QString get_e();
    QString get_result();

public:
    double a,b,c,d,e;
    double result;
    QString all_str;
    QString name;
};

#endif // MASS_H
