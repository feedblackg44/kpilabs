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

void PrintArray(const char phrase[], const char name[], int arr[], int arr_size)
{
    cout << phrase << endl;
    cout << name << "[] = ";
    for (int i = 0; i < arr_size; i++)
    {
        if (i == 0)
            cout << "{";
        else
            cout << " ";

        cout << arr[i];

        if (i == arr_size - 1)
            cout << "}";
    }
    cout << endl;
}