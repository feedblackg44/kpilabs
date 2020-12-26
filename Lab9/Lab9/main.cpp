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
    
    string strIn,                      // Строка для хранения ввода пользователя
           strMax,                     // Самое длинное слово
           strOut;                     // Строка для вывода

    GetInputString(&strIn);

    SplitStrings(strIn, &strOut, &strMax);

    ProgramOutput(strOut, strMax);

    SystemPause();
    return 0;
}