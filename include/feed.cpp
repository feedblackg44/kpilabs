#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"

using namespace std;

double RoundTo(double Number, int DecimalPlace)
{
	double D = round(Number * pow(10, DecimalPlace)) / pow(10, DecimalPlace);
	return D;
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
			return round(f_Number);
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