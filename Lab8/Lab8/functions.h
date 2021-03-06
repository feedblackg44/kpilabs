#pragma once

bool IsSqare(int num);

int FillDiagonal(int** matrix, int size, int diagNum, int firstNum, bool up);

void OutputMatrix(const char matrixName[], int** matrix, int size);

void GetMatrixSize(int* num, int* size);

int** MatrixInit(int size);

void BuildMatrix(int** Matrix, int n, int size);