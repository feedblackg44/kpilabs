#include <iostream>
#include <string>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();
    LabHeader(9);
    cout << "Программа убирает из заданной строки слова на чётных местах\nСреди оставшихся находит и выводит самое длинное\n" << endl;

    string  strIn,                      // Строка для хранения ввода пользователя
            strMax,                     // Самое длинное слово
            strOut;                     // Строка для вывода
    
    cout << "Введите строку для обработки:" << endl;
    getline(cin, strIn);

    SplitStrings(strIn, &strOut, &strMax);

    cout << "Вот введённая строка без слов на чётных местах:" << endl;
    cout << strOut << endl;
    cout << "Вот самое длинное слово среди оставшихся:" << endl;
    cout << strMax << endl;

    SystemPause();
    return 0;
}