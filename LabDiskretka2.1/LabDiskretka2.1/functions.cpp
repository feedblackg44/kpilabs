#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include <vector>
#include "feed.h"
#include "functions.h"

using namespace std;

void PrintGraph(int* Graph, int size)
{
    vector<int> GraphFirstNumbers(size);
    vector<int> GraphSecondNumbers(size);

    for (int i = 0; i < size * 2; i++)
    {
        if (i % 2 == 0)
            GraphFirstNumbers[i / 2] = Graph[i];
        else
            GraphSecondNumbers[i / 2] = Graph[i];
    }

    cout << "Вот заданный граф:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << GraphFirstNumbers[i] << " " << GraphSecondNumbers[i] << endl;
    }
}

int* GetGraph(int* apex, int* edge)
{
    ifstream inFile;
    inFile.open(FileIN);

    if (!inFile.is_open())
    {
        cerr << "Error: Could not open the file!" << endl;
        SystemPause();
        exit(1);
    }

    string str;
    istringstream iss;

    getline(inFile, str);
    iss.str(str);
    iss >> *apex;
    iss >> *edge;

    vector<int> Graph;
    int length = 0;

    while (getline(inFile, str))
    {
        length++;
        int temp1, temp2;
        istringstream iss_temp;
        iss_temp.str(str);
        iss_temp >> temp1;
        iss_temp >> temp2;

        Graph.push_back(temp1);
        Graph.push_back(temp2);
    }

    for (int i = 0; i < Graph.size(); i++)
    {
        if (Graph[i] > *apex)
        {
            cerr << "Error: one of apexes is invalid!" << endl;
            SystemPause();
            exit(1);
        }
    }

    if (length != *edge)
    {
        cerr << "Error: amount of edges is invalid!" << endl;
        SystemPause();
        exit(1);
    }

    int* temp = new int[*edge * 2];

    for (int i = 0; i < *edge * 2; i++)
    {
        temp[i] = Graph[i];
    }

    inFile.close();
    return temp;
}

int** MatrixOfDistance(int* Graph, int apex, int size, bool mode, bool oriented)
{
    int** GraphSmezh = new int* [apex];

    for (int i = 0; i < apex; i++)
    {
        GraphSmezh[i] = new int[apex];
        for (int j = 0; j < apex; j++)
        {
            GraphSmezh[i][j] = 0;
        }
    }

    vector<int> GraphFirstNumbers(size);
    vector<int> GraphSecondNumbers(size);

    for (int i = 0; i < size * 2; i++)
    {
        if (i % 2 == 0)
            GraphFirstNumbers[i / 2] = Graph[i];
        else
            GraphSecondNumbers[i / 2] = Graph[i];
    }

    for (int i = 0; i < size; i++)
    {
        GraphSmezh[GraphFirstNumbers[i] - 1][GraphSecondNumbers[i] - 1] = 1;
        if(!oriented)
            GraphSmezh[GraphSecondNumbers[i] - 1][GraphFirstNumbers[i] - 1] = 1;
    }

    int h = 1;
    int** matrix_res = new int* [apex];
    for (int i = 0; i < apex; i++)
    {
        matrix_res[i] = new int[apex];
        for (int j = 0; j < apex; j++)
        {
            matrix_res[i][j] = 0;
        }
    }
    while (IsThereZero(matrix_res, apex) && h<=9)
    {
        int** temp_matrix = new int* [apex];
        for (int i = 0; i < apex; i++)
        {
            temp_matrix[i] = new int[apex];
            for (int j = 0; j < apex; j++)
            {
                temp_matrix[i][j] = 0;
            }
        }

        temp_matrix = MatrixMult(GraphSmezh, apex, h);

        for (int i = 0; i < apex; i++)
        {
            for (int j = 0; j < apex; j++)
            {
                if (temp_matrix[i][j] > 0 && matrix_res[i][j] == 0 && i != j)
                {
                    matrix_res[i][j] = h;
                }
            }
        }
        h++;
    }

    return matrix_res;
}

int** MatrixReach(int** matrix, int apex, bool mode)
{
    int** matrix_res = new int* [apex];
    for (int i = 0; i < apex; i++)
    {
        matrix_res[i] = new int[apex];
        for (int j = 0; j < apex; j++)
        {
            matrix_res[i][j] = 0;
        }
    }
    
    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < apex; j++)
        {
            if (i == j)
            {
                matrix_res[i][j] = 1;
            }
            else if (matrix[i][j] >= 1)
            {
                matrix_res[i][j] = 1;
            }
        }
    }
    
    return matrix_res;
}

void OutputMatrix(const char matrixName[], int** matrix, int apex, bool mode)
{
    ostream* fout;
    if (mode)
        fout = &cout;
    else
        fout = new ofstream(FileOUT);

    *fout << matrixName << ":" << endl;
    for (int i = -2; i < apex; i++)
    {
        if (i == -2)
        {
            *fout << "     | ";
            for (int k = 1; k <= apex; k++)
            {
                if (k < 10)
                    *fout << " u0" << k;
                else
                    *fout << " u" << k;
            }
        }
        else if (i == -1)
        {
            *fout << "-------";
        }
        else
        {
            if (i < 9)
                *fout << " u0" << i + 1 << " |   ";
            else
                *fout << " u" << i + 1 << " |   ";
        }
        for (int j = -2; j <= apex + 1; j++)
        {
            if (i == -1 && j >= 0 && j < apex)
            {
                *fout << "----";
            }
            else if (i >= 0 && j >= 0 && i < apex && j < apex)
            {
                *fout << matrix[i][j];
                if (j + 1 != apex)
                    *fout << "   ";
            }
        }
        if (i >= 0 && i < apex - 1)
        {
            *fout << endl;
            *fout << "     |";
        }
        *fout << endl;
    }
    *fout << endl;

    if (fout != &cout)
        delete fout;
}

int** MatrixMult(int** matrix, int apex, int power)
{
    int** outMatrix = new int* [apex];
    for (int i = 0; i < apex; i++)
    {
        outMatrix[i] = new int[apex];
        for (int j = 0; j < apex; j++)
        {
            outMatrix[i][j] = matrix[i][j];
        }
    }

    for (int b = 1; b < power; b++)
    {
        int** tempMatrix = new int* [apex];
        for (int i = 0; i < apex; i++)
        {
            tempMatrix[i] = new int[apex];
            for (int j = 0; j < apex; j++)
            {
                tempMatrix[i][j] = outMatrix[i][j];
            }
        }

        for (int i = 0; i < apex; i++)
        {
            for (int j = 0; j < apex; j++)
            {
                outMatrix[i][j] = 0;
                for (int k = 0; k < apex; k++)
                {
                    outMatrix[i][j] += tempMatrix[i][k] * matrix[k][j];
                }
            }
        }

        for (int i = 0; i < apex; i++)
        {
            delete tempMatrix[i];
        }
        delete[] tempMatrix;
    }

    return outMatrix;
}

bool IsThereZero(int** matrix, int apex)
{
    bool result = false;
    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < apex; j++)
        {
            if (!matrix[i][j] && i != j)
                result = true;
        }
    }

    return result;
}

void ConnectivityType(int* Graph, int apex, int size, bool mode)
{
    bool strong = true;
    bool one_sided = true;
    bool weak = true;
    
    int** matrix = MatrixReach(MatrixOfDistance(Graph, apex, size, mode, ORIENTED), apex, mode);
    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < apex; j++)
        {
            if ((matrix[i][j] != matrix[j][i]) || (!matrix[i][j] && !matrix[j][i]))
                strong = false;
        }
    }
    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < apex; j++)
        {
            if (!matrix[i][j] && !matrix[j][i])
            {
                one_sided = false;
            }
        }
    }

    int** matrix_non_or = MatrixReach(MatrixOfDistance(Graph, apex, size, mode, NON_ORIENTED), apex, mode);
    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < apex; j++)
        {
            if (!matrix_non_or[i][j])
                weak = false;
        }
    }

    if (strong)
        cout << "Граф сильносвязный" << endl;
    else if (one_sided)
        cout << "Граф одностороннесвязный" << endl;
    else if (weak)
        cout << "Граф слабосвязный" << endl;
    else
        cout << "Граф не связный" << endl;
}