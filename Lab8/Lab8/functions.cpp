#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"
#include "functions.h"

using namespace std;

bool IsSqare(int num)
{
    if (pow(pow(double(num), 0.5), 2.0) == pow(double(int(pow(double(num), 0.5))), 2.0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int FillDiagonal(int** matrix, int size, int diagNum, int firstNum, bool up)
{
    int num = firstNum;
    if (up)
    {
        for (int i = size-1; i >= 0; i--)
        {
            for (int j = size-1; j >= 0; j--)
            {
                if (i + j + 1 == diagNum)
                {
                    matrix[i][j] = num--;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i + j + 1 == diagNum)
                {
                    matrix[i][j] = num--;
                }
            }
        }
    }

    return num;
}

void OutputMatrix(const char matrixName[], int** matrix, int size)
{
    cout << matrixName << ":" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] < 10)
                cout << "  ";
            else if (matrix[i][j] >= 10 && matrix[i][j] < 100)
                cout << " ";
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}