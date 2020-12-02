#include <iostream>
#include <cmath>
#include <limits>
#include <locale>
#include <iomanip>
#include <string>
#include <cstring>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();
    LabHeader(6);
    cout << "Программа считает cумму определённых интегралов от заданных функций методом прямоугольников для заданных промежутков и некоторого количества элементарных отрезков.\n" << endl;
    
    int     n;                  // Количество элементарных отрезков на которое будет разбит интервал интегрирования
    double  a,                  // Нижняя граница интеграла
            b,                  // Верхняя граница интеграла
            result;             // Результат вычислений

    a = GetDouble("Введите нижнюю границу интеграла:", "Граница введена неправильно!");
    b = GetDouble("Введите верхнюю границу интеграла:", "Граница введена неправильно!");
    n = GetInt("Введите количество элементарных отрезков на которое будет разбит интервал интегрирования:", "Количество введено неправильно!");

    result = Integral(0, M_PI, n, FIRST_FUNC) + Integral(a, b, n, SECOND_FUNC);

    string str = Declination("отрезка", "отрезок", "отрезков", n);

    cout << "Сумма определённых интегралов на промежутке от " << a << " до " << b << " с разбиением на " << n << " элементарных " << str << " равна " << result << endl;

    SystemPause();
    return 0;
}