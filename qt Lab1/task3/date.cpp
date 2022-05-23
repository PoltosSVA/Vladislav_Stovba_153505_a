#include "date.h"


Date::Date()
{

}

Date::Date(int d,int m,int y):d(d),m(m),y(y){

}

Date::~Date()
{

}

Date Date::PreviousDay()
{
    Date date = *this;

    if(date.m == 1 && date.d == 1){
        date.y--;
        date.m = 12;
        date.d = 31;
    }
    else if(date.d == Date_mas[date.m] - (Date_mas[date.m] - 1)){
        date.m--;
        date.d = Date_mas[date.m];
    }
    else
        date.d--;

    return date;
}
int Date::WeekNumber()
{
    int Days = 0;

    for(int i = 1; i < this->m; i++){
        Days += Date_mas[i];
    }

    if (this->isLeap() && this->m > 2){
        Days++;
    }

    Days += this->d;
    int week = (Days / 7) + 1;

    return week;
}
QString Date::toStr()
{
    QString str;


    if(this->d<10)
        str = "0" + QString::number(this->d) + ".";
    else
        str = QString::number(this->d) + ".";

    if(this->m < 10)
        str += "0" + QString::number(this->m) + ".";
    else
        str += QString::number(this->m) + ".";

    str += QString::number(this->y);
    return str;

}

bool Date::isLeap(int y)
{
    return ((y%4==0 && y %100 !=0) || y%400==0);
}

bool Date::isLeap()
{
    return ((this->y%4==0 && this->y %100 !=0) || this->y%400==0);
}



int Date::DaysBetweenMonth(Date &Date_1,Date &Date_2){
    int days = 0;

    for(int i = Date_1.m+1 ; i < Date_2.m; i++){
        days += Date_mas[i];
    }
    days += (Date_mas[Date_1.m] - Date_1.d) + Date_2.d;//дней до др
    return days;
}

int Date::DaysTillBithday(Date Birth_Date)
{
    Date Current_Date(QDate::currentDate().day(),QDate::currentDate().month(),QDate::currentDate().year());

    if(Birth_Date.m > Current_Date.m){
        if(Current_Date.isLeap())
            return DaysBetweenMonth(Current_Date,Birth_Date) + 1;
        else
            return DaysBetweenMonth(Current_Date,Birth_Date);
    }

    if(Birth_Date.m == Current_Date.m){
        return DaysDiffInsideMonth(Current_Date,Birth_Date);
    }

    if(Birth_Date.m < Current_Date.m){
        return DaysBetweenYears(Birth_Date,Current_Date);
    }



    return 0;


}

Date Date::NextDay()
{
    Date date = *this;

    if(date.m == 12 && date.d == 31){
        date.y++;
        date.m = 1;
        date.d = 1;
    }
    else if(date.d == Date_mas[date.m]){
        date.m++;
        date.d = 1;
    }
    else
        date.d++;

    return date;
}

int Date::DaysBetweenYears(Date &Date_1,Date &Date_2){
    int days = 365 - DaysBetweenMonth(Date_1, Date_2);//минус вермя до др
    return days;
}

int Date::DaysDiffInsideMonth(Date &Date_1,Date &Date_2){
    int days = 0;

    if(Date_2.d > Date_1.d){
        days = Date_2.d - Date_1.d;
    }
    if(Date_2.d == Date_1.d){
        days = 0;
    }
    if(Date_2.d < Date_1.d){//после др
        days = 365 - (Date_1.d - Date_2.d);
    }
    return days;
}



int Date::Duration(Date CurrentDate)
{
    if(this->y > CurrentDate.y){
        return DaysBetweenYearsDuration(CurrentDate, *this);
    }
    if(this->y < CurrentDate.y){
        return DaysBetweenYearsDuration(*this, CurrentDate);
    }
    if(this->y == CurrentDate.y && this->m < CurrentDate.m){
        return DaysBetweenMonth(*this, CurrentDate);
    }
    if(this->y == CurrentDate.y && this->m > CurrentDate.m){
        return DaysBetweenMonth(CurrentDate, *this);
    }
    if(this->y == CurrentDate.y && this->m == CurrentDate.m &&
            this->d < CurrentDate.d){
        return DaysDiffInsideMonth(*this, CurrentDate);
    }
    if(this->y == CurrentDate.y && this->m == CurrentDate.m &&
            this->d > CurrentDate.d){
        return DaysDiffInsideMonth(CurrentDate, *this);
    }
    if(this->y == CurrentDate.y && this->m == CurrentDate.m &&
            this->d == CurrentDate.d)
        return 0;

}

int Date::DaysBetweenYearsDuration(Date &Date_1, Date &Date_2)
{
    int days = 0;

    for(int i = Date_1.y + 1; i < Date_2.y; i++){
        if(isLeap(i))
            days += 366;
        else
            days += 365;
    }

    days += Date_mas[m] - Date_1.d;

    for(int i = Date_1.m+1; i < 13; i++){
        days += Date_mas[i];
    }

    for(int i = 0; i < Date_2.m; i++){
        days += Date_mas[i];
    }

    days += Date_2.d;

    return days;
}
