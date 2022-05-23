#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QDate>
#include <QMap>

class Date
{
public:
    Date();
    Date(int,int,int);
   ~Date();

    QString toStr();

    //Date NextDay();

    bool isLeap(int y);
    bool isLeap();

    int DaysBetweenMonth(Date &Date_1,Date &Date_2);
    int DaysTillBithday(Date Birth_Date);
    Date NextDay();
    int DaysBetweenYears(Date &Date_1,Date &Date_2);
    int DaysDiffInsideMonth(Date &Date_1,Date &Date_2);
    int Duration(Date CurrentDate);
    int DaysBetweenYearsDuration(Date &Date_1, Date &Date_2);
    int WeekNumber();
    Date PreviousDay();
private:
    int d,m,y;

    QMap <int, int> Date_mas = {
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
    };

};

#endif // DATE_H
