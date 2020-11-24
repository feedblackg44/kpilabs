#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include <cstring>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();
    
    int  n,                  // Количество чисел ряда
         a, b,               // Числа а и b для вычисления слагаемого t
         t;                  // Слагаемое, прибавляемое к сумме
    int  sum = 0;            // Сумма
    bool mode;               // Режим вывода суммы

    do
    {
        n = GetInt("Введите натуральное число:", "Число введено неправильно!");
        if (n <= 0)
            cout << "Число введено неправильно!" << endl;
    } while (n <= 0);

    SleepFor(1000);            // Система ждёт 1 секунду
    //ClearScr();
    cout << endl;

    PrintSlow("Есть два режима вывода суммы:\n1) Каждое действие проводится по очереди в отдельной строчке.\n2) Все слагаемые складываются в столбик.", DEFAULT_DELAY, true);

    mode = GetMode("Введите номер режима, в котором должна работать программа:", "Число режима введено неправильно!");

    SleepFor(1000);            // Система ждёт 1 секунду
    //ClearScr();
    cout << endl;

    PrintSlow("Посчитаем:", DEFAULT_DELAY, true);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            a = i;
            b = i * i;
        }
        else
        {
            a = i / 2;
            b = i + 7;
        }

        t = (a - b) * (a - b);

        SleepFor(150);
        
        if (mode)
        {
            string str = to_string(i) + ") " + to_string(sum);             // Перевод символов и чисел в одну строку
            const char* str_to_print = str.c_str();                        // Перевод string в const char* для использования фунцкии PrintSlow
            PrintSlow(str_to_print, DEFAULT_DELAY, false);

            sum += t;

            str = " + " + to_string(t) + " = " + to_string(sum);           // Перевод символов и чисел в одну строку
            str_to_print = str.c_str();                                    // Перевод string в const char* для использования фунцкии PrintSlow
            PrintSlow(str_to_print, DEFAULT_DELAY, true);
        }
        else
        {
            string x = i != 1 ? "+\n" : "";

            string str = x + to_string(t);                                 // Перевод символов и чисел в одну строку
            const char* str_to_print = str.c_str();                        // Перевод string в const char* для использования фунцкии PrintSlow
            PrintSlow(str_to_print, DEFAULT_DELAY, true);

            sum += t;

            if (i == n)
            {
                str = "=\n" + to_string(sum);                              // Перевод символов и чисел в одну строку
                str_to_print = str.c_str();                                // Перевод string в const char* для использования фунцкии PrintSlow
                PrintSlow(str_to_print, DEFAULT_DELAY, true);
                
                //cout << "=\n" << sum << endl;
            }
        }
    }

    string str = "\nСумма ряда равна " + to_string(sum);                   // Перевод символов и чисел в одну строку
    const char* str_to_print = str.c_str();                                // Перевод string в const char* для использования фунцкии PrintSlow
    PrintSlow(str_to_print, DEFAULT_DELAY, true);

    SystemPause();
    return 0;
}