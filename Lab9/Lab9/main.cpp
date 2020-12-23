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

int main()
{
    SetDefaults();
    LabHeader(9);

    string  strIn,                      // Строка для хранения ввода пользователя
            strMax,                     // Самое длинное слово
            strOut;                     // Строка для вывода
    getline(cin, strIn);

    SplitStrings(strIn, &strOut, &strMax);

    cout << strOut << endl;
    cout << strMax << endl;

    SystemPause();
    return 0;
}