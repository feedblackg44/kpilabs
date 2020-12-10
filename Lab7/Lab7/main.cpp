#include <iostream>
#include <limits>
#include <locale>
#include <iomanip>
#include <string>
#include <cstring>
#include <time.h>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();
    LabHeader(7);
    cout << "Программа считает сумму по заданной формуле: (Pmax - P[i])^2, для заданного массива целых чисел P[].\nВ конце все элементы на нечётных позициях уменьшаются на полученную сумму." << endl;

    int     arr_size,                   // Размер массива чисел, указываемыый пользователем
            Max,                        // Максимальный элемент массива
            sum = 0;                    // Сумма
    int*    P;                          // Указатель на динамический массив чисел, вводимых пользователем
    bool    auto_mode;                  // Режим работы программы (true - массив заполняется случайными числами из указанного промежутка, false - массив заполняется пользователем)

    arr_size = GetInt("Введите количество элементов массива:", "Число введено неправильно!");
    
    P = new int[arr_size];              // Создание динамического массива чисел, вводимых пользователем
    
    auto_mode = GetBool("Введите режим, в котором будет работать программа:\n1 - массив заполняется случайными числами из указанного промежутка\n0 - массив заполняется пользователем", "Число режима введено неправильно!");
    if (auto_mode)
    {
        srand(time(NULL));
        int bottom = GetInt("Введите нижнюю границу промежутка:", "Число введено неправильно!");
        int upper = GetInt("Введите верхнюю границу промежутка:", "Число введено неправильно!");
        for (int i = 0; i < arr_size; i++)
        {
            P[i] = rand() % (upper - bottom) + bottom;
        }
    }
    else
    {
        for (int i = 0; i < arr_size; i++)
        {
            P[i] = GetInt("Введите целое число для записи в массив:", "Число введено неправильно!");
        }
    }

    PrintArray("Массив полученных чисел:", "P", P, arr_size);
    
    Max = P[0];
    for (int i = 1; i < arr_size; i++)
    {
        if (Max < P[i])
            Max = P[i];
    }

    for (int i = 0; i < arr_size; i++)
    {
        sum += (Max - P[i]) * (Max - P[i]);
    }
    cout << "Сумма заданная формулой (Pmax - P[i])^2 равна "<< sum << endl;

    for (int i = 0; i < arr_size; i++)
        if ((i + 1) % 2 == 1)
            P[i] -= sum;

    PrintArray("Отнимаем от нечётных элементов массива полученную сумму:", "P", P, arr_size);

    SystemPause();
    return 0;
}