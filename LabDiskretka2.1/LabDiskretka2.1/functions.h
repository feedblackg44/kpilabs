#pragma once

#define FileIN "./Graph_Weak.txt"
#define FileOUT "./Output.txt"
#define ORIENTED true
#define NON_ORIENTED false

int* GetGraph(int* apex, int* edge);

void PrintGraph(int* Graph, int size);

int** MatrixOfDistance(int* Graph, int apex, int size, bool mode, bool oriented);

void OutputMatrix(const char matrixName[], int** matrix, int apex, bool mode);

int** MatrixMult(int** matrix, int apex, int power);

bool IsThereZero(int** matrix, int apex);

int** MatrixReach(int** matrix, int apex, bool mode);

void ConnectivityType(int* Graph, int apex, int size, bool mode);