#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

string ExtractFisrtWordOfString(string* strIn)
{
    string strTemp,         // Временная строка
           outWord;         // Слово на вывод

    bool found = false;
    for (int i = 0; i < (*strIn).length(); i++)
    {
        if(found)
        {
            strTemp += (*strIn)[i];
        }
        else if (!MatchPattern(DELIMITERS, (*strIn)[i]))
        {
            outWord += (*strIn)[i];
        }
        else if (i > 0 && !MatchPattern(DELIMITERS, (*strIn)[i - 1]))
        {
            found = true;
        }
    }

    (*strIn) = strTemp;
    
    return outWord;
}

bool MatchPattern(const char* symbols, char symbol)
{
    for (int i = 0; i < strlen(symbols); i++)
    {
        if (symbol == symbols[i])
        {
            return true;
        }
    }
    return false;
}

string makeOutString(string strIn)
{
    string curWord,         // Текущее слово
           lastWord,        // Последнее слово
           strOut;          // Строка на вывод

    bool canDelete = false;
    bool firstWord = true;
    while (!strIn.empty())
    {
        curWord = ExtractFisrtWordOfString(&strIn);

        if (MatchPattern("(", curWord[0]))
        {
            canDelete = true;
        }
        if (!canDelete && firstWord)
        {
            if (int(curWord[0]) >= 97 && int(curWord[0]) <= 122)
                curWord[0] = char(int(curWord[0]) - 32);
            lastWord = curWord;
            curWord = "";
            firstWord = false;
        }
        else if (MatchPattern(")", curWord[curWord.length() - 1]) && canDelete)
        {
            curWord = ")";
            canDelete = false;
        }

        strOut += curWord + " ";
    }
    strOut += lastWord + "\n";
    lastWord = "";

    return strOut;
}