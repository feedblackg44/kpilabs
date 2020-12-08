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

int main()
{
    SetDefaults();
    
    ifstream inFile;
    ofstream outFile;
    inFile.open("./Graph.txt");
    outFile.open("./Output.txt");
    
    if (!inFile.is_open())
    {
        cerr << "Error: Could not open the file!" << endl;
        SystemPause();
        exit(1);
    }

    string str_temp;
    int length = 0;
    vector<int> GraphNumbers;

    getline(inFile, str_temp);
    while (getline(inFile, str_temp))
    {
        length++;
        istringstream iss3;
        int temp1, temp2;
        iss3.str(str_temp);
        iss3 >> temp1;
        iss3 >> temp2;

        GraphNumbers.push_back(temp1);
        GraphNumbers.push_back(temp2);
    }

    inFile.close();
    inFile.open("./Graph.txt");

    string str;
    istringstream iss;
    int apex, edge;
    
    getline(inFile, str);
    iss.str(str);
    iss >> apex;
    iss >> edge;

    for (int i = 0; i < sizeof(GraphNumbers); i++)
    {
        if (GraphNumbers[i] > apex)
        {
            cerr << "Error: one of apexes is invalid!" << endl;
            SystemPause();
            exit(1);
        }
    }

    if (length != edge)
    {
        cerr << "Error: amount of edges is invalid!" << endl;
        SystemPause();
        exit(1);
    }

    vector<vector<int>> GraphSumis(apex, vector<int>(edge));
    vector<vector<int>> GraphSmezh(apex, vector<int>(apex));

    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            GraphSumis[i][j] = 0;
        }
    }
    
    for (int i = 0; i < apex; i++)
    {
        for (int j = 0; j < apex; j++)
        {
            GraphSmezh[i][j] = 0;
        }
    }

    int k = 0;
    while (getline(inFile, str))
    {
        istringstream iss2;
        int temp1, temp2;
        iss2.str(str);
        iss2 >> temp1;
        iss2 >> temp2;

        GraphSmezh[temp1 - 1][temp2 - 1] = 1;

        if (temp1 == temp2)
            GraphSumis[temp1 - 1][k] = 2;
        else
        {
            GraphSumis[temp1 - 1][k] = -1;
            GraphSumis[temp2 - 1][k] = 1;
        }
        k++;
    }

    int mode;
    while (true)
    {
        mode = GetInt("Input in file (1), in console (2) or both (3)?", "Invalid mode!");
        if (mode < 1 || mode > 3)
            cout << "Invalid mode!" << endl;
        else
            break;
    }

    if ((mode == 1) || (mode == 3))
    {
        outFile << "Incidence matrix:" << endl;
        for (int i = -2; i < apex; i++)
        {
            if (i == -2)
            {
                outFile << "     | ";
                for (int k = 1; k <= edge; k++)
                {
                    if (k < 10)
                        outFile << " e0" << k;
                    else
                        outFile << " e" << k;
                }
            }
            else if (i == -1)
            {
                outFile << "-------";
            }
            else
            {
                if (i < 9)
                    outFile << " u0" << i + 1 << " |";
                else
                    outFile << " u" << i + 1 << " |";
            }
            for (int j = -2; j <= edge + 1; j++)
            {
                if (i == -1 && j >= 0 && j < edge)
                {
                    outFile << "----";
                }
                else if (i >= 0 && j >= 0 && i < apex && j < edge)
                {
                    if (GraphSumis[i][j] >= 0)
                        outFile << "   ";
                    else
                        outFile << "  ";
                    outFile << GraphSumis[i][j];
                }
            }
            if (i >= 0 && i < apex - 1)
            {
                outFile << endl;
                outFile << "     |";
            }
            outFile << endl;
        }
        outFile << endl;

        outFile << "Adjacency matrix:" << endl;
        for (int i = -2; i < apex; i++)
        {
            if (i == -2)
            {
                outFile << "     | ";
                for (int k = 1; k <= apex; k++)
                {
                    if (k < 10)
                        outFile << " u0" << k;
                    else
                        outFile << " u" << k;
                }
            }
            else if (i == -1)
            {
                outFile << "-------";
            }
            else
            {
                if (i < 9)
                    outFile << " u0" << i + 1 << " |   ";
                else
                    outFile << " u" << i + 1 << " |   ";
            }
            for (int j = -2; j <= apex + 1; j++)
            {
                if (i == -1 && j >= 0 && j < apex)
                {
                    outFile << "----";
                }
                else if (i >= 0 && j >= 0 && i < apex && j < apex)
                {
                    outFile << GraphSmezh[i][j];
                    if (j + 1 != apex)
                        outFile << "   ";
                }
            }
            if (i >= 0 && i < apex - 1)
            {
                outFile << endl;
                outFile << "     |";
            }
            outFile << endl;
        }
        outFile << endl;
    }

    if ((mode == 2) || (mode == 3))
    {
        cout << "Incidence matrix:" << endl;
        for (int i = -2; i < apex; i++)
        {
            if (i == -2)
            {
                cout << "     | ";
                for (int k = 1; k <= edge; k++)
                {
                    if (k < 10)
                        cout << " e0" << k;
                    else
                        cout << " e" << k;
                }
            }
            else if (i == -1)
            {
                cout << "-------";
            }
            else
            {
                if (i < 9)
                    cout << " u0" << i + 1 << " |";
                else
                    cout << " u" << i + 1 << " |";
            }
            for (int j = -2; j <= edge + 1; j++)
            {
                if (i == -1 && j >= 0 && j < edge)
                {
                    cout << "----";
                }
                else if (i >= 0 && j >= 0 && i < apex && j < edge)
                {
                    if (GraphSumis[i][j] >= 0)
                        cout << "   ";
                    else
                        cout << "  ";
                    cout << GraphSumis[i][j];

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

        cout << "Adjacency matrix:" << endl;
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
                    cout << GraphSmezh[i][j];
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

    inFile.close();
    outFile.close();
    
    SystemPause();
    return 0;
}