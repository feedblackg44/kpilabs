#pragma once

#include <string>

int** matrixCreate(int p, int q);

void fillMatrix(int** matrix, int upper, int lower, int p, int q);

void printMatrix(int** matrix, int p, int q);

int* findLocaleMax(int** matrix, int p, int q);