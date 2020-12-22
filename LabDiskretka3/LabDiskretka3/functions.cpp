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

int** MatrixSmezh(int* Graph, int apex, int size, bool oriented)
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
        if (!oriented)
            GraphSmezh[GraphSecondNumbers[i] - 1][GraphFirstNumbers[i] - 1] = 1;
    }

    return GraphSmezh;
}

void OutputMatrix(const char matrixName[], int** matrix, int apex)
{
    cout << matrixName << ":" << endl;
    for (int i = -2; i < apex; i++)
    {
        if (i == -2)
        {
            cout << "     | ";
            for (int k = 1; k <= apex; k++)
            {
                if (k < 10)
                    cout << " u0" << k;
                else
                    cout << " u" << k;
            }
        }
        else if (i == -1)
        {
            cout << "-------";
        }
        else
        {
            if (i < 9)
                cout << " u0" << i + 1 << " |   ";
            else
                cout << " u" << i + 1 << " |   ";
        }
        for (int j = -2; j <= apex + 1; j++)
        {
            if (i == -1 && j >= 0 && j < apex)
            {
                cout << "----";
            }
            else if (i >= 0 && j >= 0 && i < apex && j < apex)
            {
                cout << matrix[i][j];
                if (j + 1 != apex)
                    cout << "   ";
            }
        }
        if (i >= 0 && i < apex - 1)
        {
            cout << endl;
            cout << "     |";
        }
        cout << endl;
    }
    cout << endl;
}

void ObhodVShir(int** matrix, int apex)
{
    int u;
    while (true)
    {
        u = GetInt("Введите вершину для начала поиска вширь:", "Вершина введена неправильно!");
        if (u <= apex && u >= 1)
        {
            break;
        }
        else
        {
            system(ClearScreen);
            cout << "Вершина введена неправильно!";
        }
    }

    int* BFS = new int[apex];
    for (int i = 0; i < apex; i++)
        BFS[i] = 0;
    vector<int> Q = {u};

    cout << "| Вершина | BFS-номер | Содержимое очереди |" << endl;
    cout << "|---------|-----------|--------------------|" << endl;
    int k = 1;
    while (Q.size() > 0)
    {
        int v = Q[0]-1;
        for (int i = 1; i <= apex; i++)
        {
            if (k == 1)
            {
                BFS[u - 1] = k;
                cout << "|    " << u << "    |     " << k << "     |";
                for (int j = 0; j < Q.size(); j++)
                    cout << Q[j];
                for (int j = 0; j < (20 - Q.size()); j++)
                    cout << " ";
                cout << "|" << endl;
                k++;
            }
            if (!BFS[i-1] && matrix[v][i-1])
            {
                BFS[i-1] = k;
                Q.push_back(i);

                cout << "|    " << i << "    |     " << k << "     |";
                for (int j = 0; j < Q.size(); j++)
                    cout << Q[j];
                for (int j = 0; j < (20 - Q.size()); j++)
                    cout << " ";
                cout << "|" << endl;
                k++;
            }
        }
        Q.erase(Q.begin());
        cout << "|    " << "-" << "    |     " << "-" << "     |";
        for (int j = 0; j < Q.size(); j++)
            cout << Q[j];
        for (int j = 0; j < (20 - Q.size()); j++)
            cout << " ";
        cout << "|" << endl;
    }
}

void ObhodVGlub(int** matrix, int apex)
{
    int u;
    while (true)
    {
        u = GetInt("Введите вершину для начала поиска вглубь:", "Вершина введена неправильно!");
        if (u <= apex && u >= 1)
        {
            break;
        }
        else
        {
            system(ClearScreen);
            cout << "Вершина введена неправильно!";
        }
    }

    int* DFS = new int[apex];
    for (int i = 0; i < apex; i++)
        DFS[i] = 0;
    vector<int> S = { u };

    cout << "| Вершина | DFS-номер | Содержимое стека |" << endl;
    cout << "|---------|-----------|------------------|" << endl;

    int k = 1;
    DFS[u - 1] = k;
    cout << "|    " << u << "    |     " << k << "     |";
    for (int j = 0; j < S.size(); j++)
        cout << S[j];
    for (int j = 0; j < (18 - S.size()); j++)
        cout << " ";
    cout << "|" << endl;
    k++;
    bool done = false;
    while (S.size() > 0)
    {
        int v = S.back() - 1;
        int current = v;
        if (IsTherePossibleEdge(matrix, DFS, apex, &current))
        {
            DFS[current-1] = k;
            S.push_back(current);

            cout << "|    " << current << "    |     " << k << "     |";
            for (int j = 0; j < S.size(); j++)
                cout << S[j];
            for (int j = 0; j < (18 - S.size()); j++)
                cout << " ";
            cout << "|" << endl;
            k++;
        }
        else
        {
            S.pop_back();
            cout << "|    " << "-" << "    |     " << "-" << "     |";
            for (int j = 0; j < S.size(); j++)
                cout << S[j];
            for (int j = 0; j < (18 - S.size()); j++)
                cout << " ";
            cout << "|" << endl;
        }
    }
}

bool IsTherePossibleEdge(int** matrix, int DFS[], int apex, int *from)
{
    bool result = false;
    for (int i = 0; i < apex; i++)
    {
        if (matrix[*from][i] && !DFS[i])
        {
            result = true;
            *from = i+1;
            break;
        }
    }
    return result;
}
