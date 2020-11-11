#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <cstring>
#include "feed.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#undef max

using namespace std;

void SetDefaults()
{
	setlocale(LC_ALL, "ru-RU.UTF-8");
}

double RoundTo(double number, int decimalPlace)
{
	double D = round(number * pow(10, decimalPlace)) / pow(10, decimalPlace);
	return D;
}

double GetDouble(const char promptMessage[], const char failMessage[])
{
	double d_Number;

	while (true)
	{
		cout << promptMessage << "\n";
		cin >> d_Number;

		if (cin.fail())
		{
			cout << failMessage << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			return d_Number;
		}
	}
}

int GetInt(const char promptMessage[], const char failMessage[])
{
	float f_Number;

	while (true)
	{
		cout << promptMessage << "\n";
		cin >> f_Number;

		if (cin.fail())
		{
			cout << failMessage << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			if (round(f_Number) == f_Number)
				return round(f_Number);
			else
				cout << failMessage << "\n";
		}
	}
}

double Minimum(double number1, double number2)
{
	if (number1 < number2)
		return number1;
	else
		return number2;
}


void PrintFormatted(const char name[], double number, int width, int precision, bool align)
{
	cout << name << " = ";

	if (align)
		cout << fixed;
	else
		cout << defaultfloat;
	if (width > 0)
		cout << setw(width);
	if (precision > 0)
		cout << setprecision(precision);

	cout << number << endl;
}

void PrintSlow(const char str[], int delay, bool endline)
{
	int count = strlen(str);

	for (int i = 0; i < count; i++)
	{
		cout << str[i];
		SleepFor(delay);
	}
	if (endline)
		cout << endl;
}

void CoutReset()
{
	cout << defaultfloat;
}

void SleepFor(int milliseconds)
{
#ifdef _WIN32
	Sleep(milliseconds);
#else
	Usleep(milliseconds);
#endif
}