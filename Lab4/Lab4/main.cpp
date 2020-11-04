#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
	EventProgramLoad();
	
	double y0 = 1.0;
	double x0 = 1.0;
	double x1 = 0.0;
	double y1 = 0.0;

	int n = GetInt("Введите порядковый номер нужного элемента x(n):", "Порядковый номер введён неправильно!");

	for (int i = 1; i <= n; i++)
	{
		x1 = x0 + (y0 / pow(i, 2.0));
		y1 = y0 + (x0 / i);

		x0 = x1;
		y0 = y1;

		PrintFormated("x", x1, 12, 8, true);
		PrintFormated("y", y1, 12, 8, true);
	}

	PrintFormated("x(n)", x1, 0, 9, false);

	system("pause");
	return 0;
}