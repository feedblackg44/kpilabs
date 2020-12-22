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

    const char* str_menu =  "Добро пожаловать в программу работы с графом:"
                            "\n1 - Вывод матрицы смежности"
                            "\n2 - Обход графа поиском вширь"
                            "\n3 - Обход графа поиском вглубь"
                            "\n0 - Выйти из программы";

    while (true)
    {
        system(ClearScreen);

        int choice = GetInt(str_menu, "");

        system(ClearScreen);

        int** matrix = MatrixSmezh(Graph, apex, edge, NON_ORIENTED);

        switch (choice)
        {
        case 1:
            OutputMatrix("Матрица смежности", matrix, apex);
            SystemPause();
            break;
        case 2:
            ObhodVShir(matrix, apex);
            SystemPause();
            break;
        case 3:
            ObhodVGlub(matrix, apex);
            SystemPause();
            break;
        case 0:
            exit(0);
        }
    }
}