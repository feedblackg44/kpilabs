#include <iostream>
#include <locale>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    
    string strIn,
           strOut = "",
           strTemp;
    
    getline(cin, strIn);

    while (strIn.empty())
    {
        strTemp = ExtractFirstWordOfString(&strIn);
        strOut += strTemp;
        if (strTemp.empty())
        {
            strOut += "\n";
        }
    }

    cout << strOut << endl;

    system("pause");
    return 0;   
}