#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();
    LabHeader(9);

    string strTemp;
    string* words;
    stringstream strStream;

    getline(cin, strTemp);
    const char* strIn = strTemp.c_str();

    strStream << strTemp;
    int amount = 1;
    for (int i = 0; i < signed(strlen(strIn)); i++)
    {
        if (strIn[i] == ' ') 
        {
            amount++;
        }
    }

    words = new string[amount];
    for (int i = 0; i < amount; i++)
    {
        strStream >> words[i];
    }

    for (int i = 0; i < amount; i++)
    {
        string temp;
        if (words[i][strlen(words[i].c_str()) - 1] == ',')
        {
            for (int j = 0; j < strlen(words[i].c_str()) - 1; j++)
            {
                temp += words[i][j]; 
            }
            words[i] = temp;
        }
    }

    int max = strlen(words[1].c_str());
    string strMax = words[1];
    for (int i = 0; i < amount; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            if (strlen(words[i].c_str()) > max)
            {
                max = strlen(words[i].c_str());
                strMax = words[i];
            }
            cout << words[i];
            cout << " ";
        }
    }
    cout << endl;
    
    cout << strMax << endl;

    SystemPause();
    return 0;
}