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
    LabHeader(4);

    int n,                      // Количество чисел для заполнения матрицы
        size;                   // Размер матрицы
    int** Matrix;               // Указатель на матрицу

    while (true)
    {
        n = GetInt("Введите количество чисел для заполнения квадратной матрицы", "Число введено неправильно!");
        if (IsSqare(n))
        {
            break;
        }
        else
        {
            cout << "Так как матрица квадратная, число должно быть полным квадратом!" << endl;
        }
    }

    size = pow(double(n), 0.5);

    Matrix = new int* [size];
    for (int i = 0; i < size; i++)
    {
        Matrix[i] = new int[size];
    }

    for (int i = 2*size - 1; i >= 1; i--)
    {
        bool up = i % 2 ? false : true;

        n = FillDiagonal(Matrix, size, i, n, up);
    }

    OutputMatrix("Матрица", Matrix, size);

    SystemPause();
    return 0;
}