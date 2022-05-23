#include "tools.h"
#include <QChar>
#include <QDebug>
tools::tools()
{

}

bool tools::CheckStringToInt(QString string)
{
    for(int i = 0; i < string.size(); ++i) {
        if(string[i].toLatin1() < 48 || string[i].toLatin1() > 57) {
            return true;

        }
    }
    return false;
}
