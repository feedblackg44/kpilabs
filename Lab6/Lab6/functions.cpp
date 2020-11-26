#include <iostream>
#include <cmath>
#include <limits>
#include <locale>
#include <iomanip>
#include "feed.h"
#include "functions.h"

using namespace std;

double Integral(double bottomBorder, double upperBorder, int number, bool firstFunc)
{
    double h = (upperBorder - bottomBorder) / number;
    double x;
    double result = 0;

    for (int i = 1; i <= number; i++)
    {
        x = bottomBorder + i * h - h / 2;
        
        result += firstFunc ? log(2 + sin(x)) : atan(x) * atan(x);
    }

    result *= h;

    return result;
}