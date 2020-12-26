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

void GetInputString(string* strIn)
{
    cout << "Введите строку для обработки:" << endl;
    getline(cin, *strIn);
}

void ProgramOutput(string strOut, string strMax)
{
    cout << "Вот введённая строка без слов на чётных местах:" << endl;
    cout << strOut << endl;
    cout << "Вот самое длинное слово среди оставшихся:" << endl;
    cout << strMax << endl;
}