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

	bool mode;

	string x;

	do
	{
		n = GetInt("Введите натуральное число:", "Число введено неправильно!");
		if (n <= 0)
			cout << "Число введено неправильно!" << endl;
	} while (n <= 0);

	system("clclr");

	cout << "Есть два режима вывода суммы:\n1) Все слагаемые складываются в столбик.\n2) Каждое действие проводится по очереди в отдельной строчке." << endl;

	mode = GetBool("Введте номер режима, в котором должна работать программа:", "Число режима введено неправильно!");

	cout << "\nПосчитаем:" << endl;

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

		if (mode)
		{
			cout << i << ") " << sum;

			sum += t;

			cout << " + " << t << " = " << sum << endl;
		}
		else
		{
			x = i != 1 ? "+\n" : "";

			cout << x << t << "\n";

			sum += t;

			if (i == n)
				cout << "=\n" << sum << endl;
		}
	}

	cout << "\nСумма ряда равна " << sum << endl;

	system("pause");
	return 0;
}