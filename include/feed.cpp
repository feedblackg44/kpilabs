#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"

using namespace std;

void EventProgramLoad()
{
	setlocale(LC_ALL, "ru-RU.UTF-8");
}

double RoundTo(double Number, int DecimalPlace)
{
	double D = round(Number * pow(10, DecimalPlace)) / pow(10, DecimalPlace);
	return D;
}

void PrintFormated(const char NumberName[], double Number, int weight, int precision, bool Fixed)
{
	cout << NumberName << " = ";
	
	if (Fixed)
		cout << fixed;
	else
		cout << defaultfloat;
	if (weight > 0)
		cout << setw(weight);
	if (precision > 0)
		cout << setprecision(precision);
	
	cout << Number << endl;
}

void CoutReset()
{
	cout << defaultfloat;
}

float GetDouble(const char PromptMessage[], const char FailMessage[])
{
	float d_Number;

	while (true)
	{
		cout << PromptMessage << "\n";
		cin >> d_Number;

		if (cin.fail())
		{
			cout << FailMessage << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			return d_Number;
		}
	}
}

int GetInt(const char PromptMessage[], const char FailMessage[])
{
	float f_Number;

	while (true)
	{
		cout << PromptMessage << "\n";
		cin >> f_Number;

		if (cin.fail())
		{
			cout << FailMessage << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			if (round(f_Number) == f_Number)
				return round(f_Number);
			else
				cout << FailMessage << "\n";
		}
	}
}

double Minimum(double Number1, double Number2)
{
	if (Number1 < Number2)
		return Number1;
	else
		return Number2;
}