#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <limits>
#include <locale.h>
#include <iomanip>
#include <string>
#include <vector>
#include "feed.h"
#include "functions.h"

using namespace std;

int main()
{
    SetDefaults();

    int edge,
        apex;
    int* Graph = GetGraph(&apex, &edge);
    bool mode = GetBool("Введите режим в котором будет работать программа:\n1 - вывод на экран\n0 - вывод в файл", "Режим введён неправильно!", true);

    const string str  = "Добро пожаловать в программу работы с графом:";
    const string str1 = "\n1 - Вывод матрицы расстояний";
    const string str2 = "\n2 - Вывод матрицы достижимости";
    const string str3 = "\n3 - Вывод диаметра графа";
    const string str4 = "\n4 - Вывод радиуса графа";
    const string str5 = "\n5 - Вывод центра графа";
    const string str6 = "\n6 - Вывод ярусов графа с перечислением вершин";
    const string str7 = "\n7 - Поменять режим вывода";
    const string str0 = "\n0 - Выйти из программы";
    string str_out = str + str1 + str2 + str3 + str4 + str5 + str6 + str7 + str0;



    while (true)
    {   
        system(ClearScreen);

        int choice = GetInt(str_out.c_str(), "Повторите ввод!");
        
        system(ClearScreen);

        switch (choice)
        {
        case 1:
            OutputMatrix("Матрица расстояний", MatrixOfDistance(Graph, apex, edge, mode), apex, mode);
            SystemPause();
            break;
        case 2:
            MatrixDosyag(MatrixOfDistance(Graph, apex, edge, mode), apex, mode);
            SystemPause();
            break;
        case 3:
            GraphDiam(MatrixOfDistance(Graph, apex, edge, mode), apex, mode);
            SystemPause();
            break;
        case 4:
            GraphCentreNRad(MatrixOfDistance(Graph, apex, edge, mode), apex, mode, false);
            SystemPause();
            break;
        case 5:
            GraphCentreNRad(MatrixOfDistance(Graph, apex, edge, mode), apex, mode, true);
            SystemPause();
            break;
        case 6:
            GraphYarus(MatrixOfDistance(Graph, apex, edge, mode), apex, mode);
            SystemPause();
            break;
        case 7:
            mode = GetBool("Введите режим в котором будет работать программа:\n1 - вывод на экран\n0 - вывод в файл", "Режим введён неправильно!", true);
            break;
        case 0:
            exit(1);
        }
    }

    SystemPause();
    return 0;
}