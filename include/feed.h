#pragma once

#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>

static double RoundTo(double Number, int DecimalPlace)
{
	double D = round(Number * pow(10, DecimalPlace)) / pow(10, DecimalPlace);
	return D;
}

static float GetDouble(const char PromptMessage[], const char FailMessage[])
{
	float d_Number;

	while (true)
	{
		std::cout << PromptMessage << "\n";
		std::cin >> d_Number;

		if (std::cin.fail())
		{
			std::cout << FailMessage << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			return d_Number;
		}
	}
}

static int GetInt(const char PromptMessage[], const char FailMessage[])
{
	float f_Number;

	while (true)
	{
		std::cout << PromptMessage << "\n";
		std::cin >> f_Number;

		if (std::cin.fail())
		{
			std::cout << FailMessage << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			return round(f_Number);
		}
	}
}

static double Minimum(double Number1, double Number2)
{
	if (Number1 < Number2)
		return Number1;
	else
		return Number2;
}