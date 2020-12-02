#include <iostream>
#include <cmath>
#include <limits>
#include <locale>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>
#include "feed.h"

#pragma warning(disable : 4996)

#ifdef _WIN32
#include <Windows.h>
#define ClearScreen "cls"
#else
#include <unistd.h>
#define ClearScreen "clear"
#endif

#undef max

using namespace std;

void SetDefaults()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    BirthdayParty();
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
    milliseconds *= 1000;
    usleep(milliseconds);
#endif
}

void ClearScr()
{
    system(ClearScreen);
}

void SystemPause()
{
#ifdef _WIN32
    system("pause");
#else
    cout << "Press any key to continue . . .";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    cout << endl;
#endif
}

void BirthdayParty()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if ((timePtr->tm_mday == 3) && (timePtr->tm_mon + 1 == 12))
    {
        cout << "Давайте поздравим с Днём Рождения разработчика - Плостака Илью :)\n" << endl;
        SystemPause();
        ClearScr();
    }
}

void LabHeader(int index)
{
    cout << "Лабораторная работа №" << index << endl;
    cout << "Выполнил: Плостак Илья" << endl;
    cout << "Группа: ИС-02\n" << endl;
}

const char* Declination(const char pluralWord234[], const char singleWord[], const char pluralWord[], int amount)
{
    const char* resultWord;

    if (amount % 10 <= 4 && amount % 10 >= 2 && (amount % 100 < 12 || amount % 100 > 14))
        resultWord = pluralWord234;
    else if (amount % 10 == 1 && amount % 100 != 11)
        resultWord = singleWord;
    else
        resultWord = pluralWord;

    return resultWord;
}