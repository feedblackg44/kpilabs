#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();
    
    double   a,                           // Нижняя (левая) граница промежутка
             b;                           // Верхняя (правая) граница промежутка
    long int n0,                          // Первое натуральное число, которое мы рассматриваем
             n1,                          // Последнее натуральное число, которое мы рассматриваем
             sum;                         // Сумма делителей текущего натурального числа
    int      amount;                      // Количество делителей текущего натурального числа

    while (true)
    {
        a = GetDouble("Введите нижнюю границу промежутка [a;b]:", "Граница введена некорректно!");
        b = GetDouble("Введите верхнюю границу промежутка [a;b]:", "Граница введена некорректно!");
        if (a > b)
            cout << "Нижняя граница должна быть меньше или равна верхней границе!" << endl;
        else
            break;
    } 

    a = RoundTo(a, 8);
    b = RoundTo(b, 8);

    n0 = a <= 0 ? 1 : ceil(a);

    n1 = floor(b);

    if (n0 <= n1)
    {
        for (int i = n0; i <= n1; i++)
        {
            amount = 0;
            sum = 0;

            for (int j = 1; j <= i; j++)
            {
                if (float(i) / float(j) == i / j)
                {
                    amount++;
                    sum += j;
                }
            }

            string divider;
            if (amount % 10 <= 4 && amount % 10 >= 2 && (amount % 100 < 12 || amount % 100 > 14))
                divider = " делителя";
            else if (amount % 10 == 1 && amount % 100 != 11)
                divider = " делитель";
            else
                divider = " делителей";

            cout << "Для числа " << i << " существует " << amount << divider << ", а их сумма равна " << sum << "." << endl;
        }
    }
    else
        cout << "В данном промежутке нет натуральных чисел" << endl;

    SystemPause();
    return 0;
}