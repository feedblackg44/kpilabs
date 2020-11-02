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
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	/*int Borders = GetInt("Введите край графика:", "Введите край графика корректно!");

	while (Borders <= 0)
	{
		if (Borders <= 0)
		{
			cout << "Введите край графика корректно!" << endl;
		}
		Borders = GetInt("Введите край графика:", "Введите край графика корректно!");
	}*/
	
	cout << "Задача: Проверить, принадлежит ли точка А области, которая приведена ниже.\n";

	int Borders = 2;
	
	double Scale = GetDouble("Введите масштаб отображения области десятичной дробью (рекомендуемый масштаб: 0.1):", "Введите масштаб отображения области корректно!");

	while (Scale > 1 || Scale <= 0)
	{
		if (Scale > 1 || Scale <= 0)
		{
			cout << "Введите масштаб графика корректно!" << endl;
		}
		Scale = GetDouble("Введите масштаб отображения области десятичной дробью:", "Введите масштаб отображения области корректно!");
	}

	CreateGraph(Borders, Scale);

	cout << "Проверим, принадлежит ли точка А данной области. ";

	double x = GetDouble("Введите значение координаты x:", "Значение задано неправильно!");
	double y = GetDouble("Введите значение координаты y:", "Значение задано неправильно!");

	if (IsCoordsInFunction(x, y))
		cout << "Точка А лежит в данной области." << endl;
	else 
		cout << "Точка А не лежит в данной области." << endl;
	
	system("pause");
	return 0;
}