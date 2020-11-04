#pragma once

double RoundTo(double number, int decimalPlace);
/*
	Round double Number to a specific decimal place
*/

float GetDouble(const char promptMessage[], const char failMessage[]);
/*
	Get double Number from user in console using PromptMessage for asking and FailMessage if input is incorrect
*/

int GetInt(const char promptMessage[], const char failMessage[]);
/*	
*	Get integer Number from user in console using PromptMessage for asking and FailMessage if input is incorrect
*/

double Minimum(double number1, double number2);
/*
*	Return minimum Number of two numbers
*/

void SetDefaults();
/*
*	Everything that need to be done at the start of the program
*/

void PrintFormatted(const char name[], double number, int width, int precision, bool align);
/* 
*	Formatted printing.
* 
*	name - number's name to show
*	number - number itself
*	width - parameter for setw() func. Setting it to 0 disables it
*	precision - parameter for setprecision() func. Setting it to 0 disables it
*	align - if true, Number will be with fixed decimal place on the screen, if false, it will be not
*/

void CoutReset();
/*
*	Reset current output stream flags
*/