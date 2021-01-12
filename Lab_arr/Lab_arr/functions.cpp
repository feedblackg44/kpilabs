#include <iostream>
#include <string>
#include <ctime>
#include "functions.h"

using namespace std;

int** matrixCreate(int p, int q)
{
    int** Y = new int* [p];
    for (int i = 0; i < p; i++)
    {
        Y[i] = new int[q];
    }

    return Y;
}

void fillMatrix(int** matrix, int upper, int lower, int p, int q)
{
    srand(time(NULL));
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            matrix[i][j] = rand() % (upper - lower + 1) + lower;
        }
    }
}

void printMatrix(int** matrix, int p, int q)
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int* findLocaleMax(int** matrix, int p, int q)
{
    int* Max = new int[q];
    for (int i = 0; i < q; i++)
    {
        Max[i] = 100000;
        for (int j = 0; j < p; j++)
        {
            if (j == 0)
            {
                if (matrix[j][i] > matrix[j + 1][i])
                {
                    Max[i] = matrix[j][i];
                }
            }
            else if (j == p - 1)
            {
                if (matrix[j][i] > matrix[j - 1][i] && matrix[j][i] < Max[i])
                {
                    Max[i] = matrix[j][i];
                }
            }
            else
            {
                if (matrix[j][i] > matrix[j - 1][i] && matrix[j][i] > matrix[j + 1][i] && matrix[j][i] < Max[i])
                {
                    Max[i] = matrix[j][i];
                }
            }
        }
    }
    return Max;
}
