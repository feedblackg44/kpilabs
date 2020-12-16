#pragma once

#define FileIN "./Graph.txt"
#define FileOUT "./Output.txt"

int* GetGraph(int* apex, int* edge);

void PrintGraph(int* Graph, int size);

int** MatrixOfDistance(int* Graph, int apex, int size, bool mode);

void OutputMatrix(const char matrixName[], int** matrix, int apex, bool mode);

int** MatrixMult(int** matrix, int apex, int power);

bool IsThereZero(int** matrix, int apex);

void MatrixDosyag(int** matrix, int apex, bool mode);

void GraphDiam(int** matrix, int apex, bool mode);

void GraphCentreNRad(int** matrix, int apex, bool mode, bool centre);

void GraphYarus(int** matrix, int apex, bool mode);