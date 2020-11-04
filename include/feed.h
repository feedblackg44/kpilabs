#pragma once

double RoundTo(double number, int decimalPlace);
/*
*	Round the number to specified precision (number of digits after the decimal point)
*/

float GetDouble(const char promptMessage[], const char failMessage[]);
/*
*	Get double number from user in console using promptMessage and failMessage
*/

int GetInt(const char promptMessage[], const char failMessage[]);
/*
*	Get integer number from user in console using promptMessage and failMessage
*/

double Minimum(double number1, double number2);
/*
*	Return minimum number of two numbers
*/

void SetDefaults();
/*
*	Everything that need to be done at the start of the program
*/

void PrintFormatted(const char name[], double number, int width, int precision, bool align);
/*
*	Formatted printing.
*
*	name      - number's name to show
*	number    - number itself
*	width     - number of digits to show (0 to igonre)
*	precision - number of digits after decimal point (0 to igonre)
*	align     - whether to align numbers by a decimal point
*/

void CoutReset();
/*
*	Reset current output stream flags
*/