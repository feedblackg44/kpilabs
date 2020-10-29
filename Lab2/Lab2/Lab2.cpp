#include <stdio.h>
#include <iostream>
#include <limits>
#include <locale.h>
#include <math.h>

using namespace std;

double RoundTo(double Number, int DecimalPlace)
{
	double Rounded = round(Number * pow(10, DecimalPlace)) / pow(10, DecimalPlace);
	return Rounded;
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

	cout << "��� ������ ������� � �������� " << Scale << ":\n";

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

int main()
{
	setlocale(LC_ALL, "Russian");
	
	/*int Borders = GetInt("������� ���� �������:", "������� ���� ������� ���������!");

	while (Borders <= 0)
	{
		if (Borders <= 0)
		{
			cout << "������� ���� ������� ���������!" << endl;
		}
		Borders = GetInt("������� ���� �������:", "������� ���� ������� ���������!");
	}*/
	
	cout << "������: ���������, ����������� �� ����� � �������, ������� ��������� ����.\n";

	int Borders = 2;
	
	double Scale = GetDouble("������� ������� ����������� ������� ���������� ������ (������������� �������: 0.1):", "������� ������� ����������� ������� ���������!");

	while (Scale > 1 || Scale <= 0)
	{
		if (Scale > 1 || Scale <= 0)
		{
			cout << "������� ������� ������� ���������!" << endl;
		}
		Scale = GetDouble("������� ������� ����������� ������� ���������� ������:", "������� ������� ����������� ������� ���������!");
	}

	CreateGraph(Borders, Scale);

	cout << "��������, ����������� �� ����� � ������ �������. ";

	double x = GetDouble("������� �������� ���������� x:", "�������� ������ �����������!");
	double y = GetDouble("������� �������� ���������� y:", "�������� ������ �����������!");

	if (IsCoordsInFunction(x, y))
		cout << "����� � ����� � ������ �������." << endl;
	else 
		cout << "����� � �� ����� � ������ �������." << endl;
	
	system("pause");
	return 0;
}