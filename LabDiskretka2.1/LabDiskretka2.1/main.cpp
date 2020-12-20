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
    SetDefaults();
    
    int edge,
        apex;
    int* Graph = GetGraph(&apex, &edge);
    bool mode = GetBool("Введите режим в котором будет работать программа:\n1 - вывод на экран\n0 - вывод в файл", "Режим введён неправильно!", true);

    string str_menu =    "Добро пожаловать в программу работы с графом:"
                        "\n1 - Вывод матрицы расстояний"
                        "\n2 - Вывод матрицы достижимости"
                        "\n3 - Вывод типа связанности графа"
                        "\n4 - Сменить режим вывода"
                        "\n0 - Выйти из программы";

    while (true)
    {
        system(ClearScreen);

        int choice = GetInt(str_menu.c_str(), "");

        system(ClearScreen);

        int** matrix = MatrixOfDistance(Graph, apex, edge, mode, ORIENTED);

        switch (choice)
        {
        case 1:
            OutputMatrix("Матрица расстояний", matrix, apex, mode);
            SystemPause();
            break;
        case 2:
            OutputMatrix("Матрица достижимости", MatrixReach(matrix, apex, mode), apex, mode);
            SystemPause();
            break;
        case 3:
            ConnectivityType(Graph, apex, edge, mode);
            SystemPause();
            break;
        case 4:
            mode = GetBool("Введите режим в котором будет работать программа:\n1 - вывод на экран\n0 - вывод в файл", "Режим введён неправильно!", true);
            break;
        case 0:
            exit(1);
        }
    }

    SystemPause();
    return 0;
}