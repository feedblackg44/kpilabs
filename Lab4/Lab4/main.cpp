#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include "feed.h"
#include "functions.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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

	Sleep(1000);
	system("cls");

	PrintSlow("Есть два режима вывода суммы:\n1) Все слагаемые складываются в столбик.\n2) Каждое действие проводится по очереди в отдельной строчке.", 20, true);

	mode = GetBool("Введте номер режима, в котором должна работать программа:", "Число режима введено неправильно!");

	Sleep(1000);
	system("cls");

	PrintSlow("Посчитаем:", 20, true);

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

		Sleep(150);
		
		if (mode)
		{
			string str = to_string(i) + ") " + to_string(sum);
			const char* str_to_print = str.c_str();
			PrintSlow(str_to_print, 20, false);

			sum += t;

			str = " + " + to_string(t) + " = " + to_string(sum);
			str_to_print = str.c_str();
			PrintSlow(str_to_print, 20, true);
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

	//Sleep(150);

	string str = "\nСумма ряда равна " + to_string(sum);
	const char* str_to_print = str.c_str();
	PrintSlow(str_to_print, 20, true);

	system("pause");
	return 0;
}