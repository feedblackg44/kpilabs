#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>
#include "functions.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string strIn,           // Строки вводимые пользователем
           strOut;          // Строка на вывод

    while (getline(cin, strIn))
    {
        if (strIn.empty())
        {
            break;
        }

        strOut += makeOutString(strIn);
    }

    cout << strOut << endl;

    system("pause");
    return 0;
}