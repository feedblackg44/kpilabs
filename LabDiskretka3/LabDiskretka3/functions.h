#pragma once

#define FileIN "./Graph.txt"
#define FileOUT "./Output.txt"
#define ORIENTED true
#define NON_ORIENTED false

int* GetGraph(int* apex, int* edge);

int** MatrixSmezh(int* Graph, int apex, int size, bool oriented);

void OutputMatrix(const char matrixName[], int** matrix, int apex);

void ObhodVShir(int** matrix, int apex);

void ObhodVGlub(int** matrix, int apex);

bool IsTherePossibleEdge(int** matrix, int DFS[], int apex, int* from);