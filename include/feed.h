#pragma once

double RoundTo(double Number, int DecimalPlace);
/*
	Round double Number to a specific decimal place
*/

float GetDouble(const char PromptMessage[], const char FailMessage[]);
/*
	Get double Number from user in console using PromptMessage for asking and FailMessage if input is incorrect
*/

int GetInt(const char PromptMessage[], const char FailMessage[]);
/*	
*	Get integer Number from user in console using PromptMessage for asking and FailMessage if input is incorrect
*/

double Minimum(double Number1, double Number2);
/*
*	Return minimum Number of two numbers
*/

void EventProgramLoad();
/*
*	Everything that need to be done at the start of the program
*/

void PrintFormated(const char NumberName[], double Number, int weight, int precision, bool Fixed);
/* 
*	Formatted printing.
* 
*	NumberName - name of the number that you want to show
*	Number - the number excactly
*	weight - parameter for setw() func. Setting it to 0 disables it
*	precision - parameter for setprecision() func. Setting it to 0 disables it
*	Fixed - if true, Number will be with fixed decimal place on the screen, if false, it will be not
*/

void CoutReset();
/*
*	Reset current output stream flags
*/