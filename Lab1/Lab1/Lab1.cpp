#include <iostream>
#include <math.h>
#include <locale.h>
#include <limits>

using namespace std;

float GetSideFromAngle(float AngleDeg, float R)
{
    double PI = acos(-1.0);

    float AngleRad = AngleDeg * PI / 180;
    float Side = 2 * R * sin(AngleRad);
    return Side;
}

float InputPosFloat(const char PromptName[], const char MessageFail1[])
{
    float f_Positive = 0.0;

    while (true)
    {
        cout << PromptName << "\n";
        cin >> f_Positive;
    
        if (!cin.fail())
        {
            if (f_Positive > 0)
            {
                return f_Positive;
            }
            else
            {
                cout << MessageFail1 << "\n";
            }
        }
        else
        {
            cout << MessageFail1 << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }     
}

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");

    float a = 1.0;
    float b = 1.0;
    float c = 1.0;
    float R = 0.0;
    float A, B, C;

    float AnglesSum = 180.0;

    while (a + b + c != AnglesSum)
    {
        a = InputPosFloat("Введите значение угла напротив стороны А:", "Угол введён неправильно!");

        b = InputPosFloat("Введите значение угла напротив стороны B:", "Угол введён неправильно!");
        
        c = InputPosFloat("Введите значение угла напротив стороны C:", "Угол введён неправильно!");
        
        if (a + b + c != AnglesSum)
        {
            cout << "Сумма углов должна быть равна 180!\n\n";
            continue;
        }
    }

    R = InputPosFloat("Введите значение радиуса R:", "Радиус введён неправильно!");

    A = GetSideFromAngle(a, R);
    B = GetSideFromAngle(b, R);
    C = GetSideFromAngle(c, R);

    cout << "Сторона А = " << A << "\nСторона B = " << B << "\nСторона C = " << C << endl;

    system("pause");
    return 0;
}