#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include <cstring>
#include "feed.h"
#include "functions.h"

#define DEFAULT_DELAY 20

using namespace std;

int main()
{
	SetDefaults();
	
	int n, a, b, t;
	int sum = 0;
	bool mode;

	do
	{
		n = GetInt("Введите натуральное число:", "Число введено неправильно!");
		if (n <= 0)
			cout << "Число введено неправильно!" << endl;
	} while (n <= 0);

	SleepFor(1000);
	system("cls");

	PrintSlow("Есть два режима вывода суммы:\n1) Каждое действие проводится по очереди в отдельной строчке.\n2) Все слагаемые складываются в столбик.", DEFAULT_DELAY, true);

	mode = GetBool("Введите номер режима, в котором должна работать программа:", "Число режима введено неправильно!");

	SleepFor(1000);
	system("cls");

	PrintSlow("Посчитаем:", DEFAULT_DELAY, true);

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

		SleepFor(150);
		
		if (mode)
		{
			string str = to_string(i) + ") " + to_string(sum);
			const char* str_to_print = str.c_str();
			PrintSlow(str_to_print, DEFAULT_DELAY, false);

			sum += t;

			str = " + " + to_string(t) + " = " + to_string(sum);
			str_to_print = str.c_str();
			PrintSlow(str_to_print, DEFAULT_DELAY, true);
		}
		else
		{
			string x = i != 1 ? "+\n" : "";

			string str = x + to_string(t);
			const char* str_to_print = str.c_str();
			PrintSlow(str_to_print, DEFAULT_DELAY, true);

			//cout << x << t << "\n";

			sum += t;

			if (i == n)
			{
				str = "=\n" + to_string(sum);
				str_to_print = str.c_str();
				PrintSlow(str_to_print, DEFAULT_DELAY, true);
				
				//cout << "=\n" << sum << endl;
			}
		}
	}

	string str = "\nСумма ряда равна " + to_string(sum);
	const char* str_to_print = str.c_str();
	PrintSlow(str_to_print, DEFAULT_DELAY, true);

	system("pause");
	return 0;
}