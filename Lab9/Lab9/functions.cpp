#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include <cstring>
#include "feed.h"
#include "functions.h"

using namespace std;

void SplitWords(char** words, int* sizes, const char* strIn)
{
    int size = 0;
    int h = 0;
    for (int i = 0; i < strlen(strIn); i++)
    {
        if (strIn[i] != ' ')
        {
            size++;
        }
        else if (strIn[i] != '\n')
        {
            size++;
        }
        else
        {
            words[h] = new char [size];
            sizes[h++] = size;
            size = 0;
        }
    }

    int curSize = 0;
    int k = 0;
    for (int i = 0; i < strlen(strIn); i++)
    {
        if (strIn[i] != ' ')
        {
            words[k][i-curSize] = strIn[i];
        }
        else if (strIn[i] != '\n')
        {
            words[k][i-curSize] = strIn[i];
        }
        else
        {
            curSize += sizes[k] + 1;
            k++;
        }
    }
}