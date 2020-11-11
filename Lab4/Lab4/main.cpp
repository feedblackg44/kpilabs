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
	SetDefaults();
	
	int n, a, b, t;
	int sum = 0;

	string x;

	do
	{
		n = GetInt("Введите натуральное число:", "Число введено неправильно!");
	} while (n <= 0);

	cout << "Посчитаем:" << endl;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			a = i;
			b = i * i;
		}
		else
		{
			a = i / 2;
			b = i + 7;
		}

		t = (a - b) * (a - b);

		sum += t;

		x = i != 1 ? "+\n" : "";

		cout << x << t << "\n";

		if (i == n)
			cout << "=\n" << sum << endl;
	}

	cout << "\nСумма ряда равна " << sum << endl;

	system("pause");
	return 0;
}