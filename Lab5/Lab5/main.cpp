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
    
    float a,                           // Нижняя (левая) граница промежутка
          b;                           // Верхняя (правая) граница промежутка
    int   n0,                          // Первое натуральное число, которое мы рассматриваем
          n1,                          // Последнее натуральное число, которое мы рассматриваем
          amount,                      // Количество делителей текущего натурального числа
          sum;                         // Сумма делителей текущего натурального числа

    a = GetDouble("Введите нижнюю границу промеужтка [a;b]:", "Граница введена некорректно!");
    b = GetDouble("Введите верхнюю границу промеужтка [a;b]:", "Граница введена некорректно!");

    a = RoundTo(a, 8);
    b = RoundTo(b, 8);

    n0 = ceil(a);
    n1 = floor(b);

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
        if (amount % 10 <= 4 && (amount % 100 < 11 || amount % 100 > 14))
            divider = " делителя";
        else
            divider = " делителей";

        cout << "Для числа " << i << " существует " << amount << divider << ", а их сумма равна " << sum << "." << endl;
    }

    SystemPause();
    return 0;
}