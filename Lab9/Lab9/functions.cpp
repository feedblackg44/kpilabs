#include <iostream>
#include <sstream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include "feed.h"
#include "functions.h"

using namespace std;

void SplitStrings(string strIn, string* strOut, string* strMax)
{
    string strCur;                          // Текущая строка
    stringstream strStream;                 // Пустой поток строк
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