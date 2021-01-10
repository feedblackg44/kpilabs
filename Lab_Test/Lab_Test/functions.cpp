#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

string ExtractFirstWordOfString(string* strIn)
{
    string outWord = "",
           strTemp = "";

    bool found = false;
    for (int i = 0; unsigned(i) < (*strIn).length(); i++)
    {
        if (found)
        {
            strTemp += (*strIn)[i];
        }
        if(!MatchPattern(DELIMITERS, (*strIn)[i]))
        {
            outWord += (*strIn)[i];
        }
        else if (i > 0 && !MatchPattern(DELIMITERS, (*strIn)[i - 1]))
        {
            found = true;
            break;
        }
    }
    
    return outWord;
}

bool MatchPattern(const char* symbols, char symbolCur)
{
    bool out = false;
    for (int i = 0; unsigned(i) < strlen(symbols); i++)
    {
        if (symbolCur == symbols[i])
        {
            out = true;
            break;
        }
    }

    return out;
}