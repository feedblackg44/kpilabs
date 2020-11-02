#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"
#include "functions.h"

using namespace std;

bool IsCoordsInFunction(double x, double y)
{
	x = RoundTo(x, 4);
	y = RoundTo(y, 4);

	bool c11 = x - y >= -2.0 ? true : false;
	bool c12 = y >= 0.0 ? true : false;
	bool c13 = x <= 0.0 ? true : false;

	bool c21 = x - y <= 2.0 ? true : false;
	bool c22 = y <= 0.0 ? true : false;
	bool c23 = x >= 0.0 ? true : false;

	bool c31 = pow(x, 2) + pow(y, 2) <= pow(2.0, 2) ? true : false;
	bool c32 = x + y >= 2.0 ? true : false;
	bool c33 = x + y <= -2.0 ? true : false;

	if ((c11 && c12 && c13) || (c21 && c22 && c23) || (c31 && (c32 || c33)))
		return true;
	else
		return false;
}

void CreateGraph(int Borders, double Scale)
{
	int Lenght = Borders / Scale;

	cout << "Вот график функции в масштабе " << Scale << ":\n";

	for (int i = -Lenght - 1; i <= Lenght + 1; i++)
	{
		if (i == 0)
		{
			printf("%d %s %d\n", -Borders, string(2 * Lenght + 1, '-').c_str(), Borders);
		}
		else
		{
			printf("   ");
			for (int j = -Lenght; j <= Lenght + 1; j++)
			{
				double CoordX = double(j) * Scale;
				double CoordY = -double(i) * Scale;

				if (j == 0)
				{
					if (i == -Lenght - 1)
						printf("%d", Borders);
					else if (i == Lenght + 1)
						printf("%d", -Borders);
					else
						printf("|");
				}
				else if (IsCoordsInFunction(CoordX, CoordY))
				{
					printf(".");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}