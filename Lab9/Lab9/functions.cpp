#include <iostream>
#include <sstream>
#include <string>
#include "feed.h"
#include "functions.h"

using namespace std;

void SplitStrings(string strIn, string* strOut, string* strMax)
{
    string strCur;                          // Текущая строка
    stringstream strStream;                 // Поток строк для разделения входной строки по пробелам
    strStream << strIn;

    bool out = true;
    while (strStream >> strCur)
    {
        if (out)
        {
            (*strOut) += strCur + " ";
            if (strCur.length() > (*strMax).length())
                (*strMax) = strCur;
        }
        out = !out;
    }
}