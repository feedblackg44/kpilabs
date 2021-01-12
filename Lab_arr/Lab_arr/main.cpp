#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>
#include "functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    
    int** Y;                        // Матрица
    int* Max;                       // Массив локальных максимумов
    int upper = 9999,               // Верхняя граница рандомных чисел
        lower = 1,                  // Нижняя границу рандомных чисел
        p,                          // Количество строк
        q;                          // Количество столбцов

    cout << "Введите колчиество строк p:" << endl;
    cin >> p;
    cout << "Введите колчиество столбцов q:" << endl;
    cin >> q;

    Y = matrixCreate(p, q);
    Max = new int[q];

    fillMatrix(Y, upper, lower, p, q);

    cout << "Полученная матрица: " << endl;
    printMatrix(Y, p, q);
    cout << endl;

    Max = findLocaleMax(Y, p, q);

    for (int i = 0; i < q; i++)
    {
        cout << "Наименьший локальний максимум для столбца " << i + 1 << " равен " << Max[i] << endl;
    }

    

    system("pause");
    return 0;
}