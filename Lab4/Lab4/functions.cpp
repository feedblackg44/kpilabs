#include <iostream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include "feed.h"
#include "functions.h"

using namespace std;

bool GetMode(const char promptMessage[], const char failMessage[])
{
	int i_Number;

	while (true)
	{
		cout << promptMessage << "\n";
		cin >> i_Number;

		if (cin.fail())
		{
			cout << failMessage << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (i_Number == 1)
		{
			return true;
		}
		else if (i_Number == 2)
		{
			return false;
		}
		else
		{
			cout << failMessage << "\n";
		}
	}
}