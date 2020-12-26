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
    LabHeader(8);

    int n,                      // Количество чисел для заполнения матрицы
        size;                   // Размер матрицы
    int** Matrix;               // Указатель на матрицу

    GetMatrixSize(&n, &size);

    Matrix = MatrixInit(size);

    BuildMatrix(Matrix, n, size);

    OutputMatrix("Матрица", Matrix, size);

    SystemPause();
    return 0;
}