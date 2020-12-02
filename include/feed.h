#pragma once

#define DEFAULT_DELAY 20        // Default delay for PrintFormatted func

#ifndef M_PI
#define M_PI acos(-1.0)
#endif

double RoundTo(double number, int decimalPlace);
/*
*    Round the number to specified precision (number of digits after the decimal point)
*/

double GetDouble(const char promptMessage[], const char failMessage[]);
/*
*    Get double number from user in console using promptMessage and failMessage
*/

int GetInt(const char promptMessage[], const char failMessage[]);
/*
*    Get integer number from user in console using promptMessage and failMessage
*/

double Minimum(double number1, double number2);
/*
*    Return minimum number of two numbers
*/

void SetDefaults();
/*
*    Everything that need to be done at the start of the program
*/

void PrintFormatted(const char name[], double number, int width, int precision, bool align);
/*
*    Formatted printing.
*
*    name      - number's name to show
*    number    - number itself
*    width     - number of digits to show (0 to igonre)
*    precision - number of digits after decimal point (0 to igonre)
*    align     - whether to align numbers by a decimal point
*/

void PrintSlow(const char str[], int delay, bool endline);
/*
*    Slow animated-like printing.
* 
*    str     - string to print
*    delay   - delay between printing symbols (milliseconds)
*    endline - whether to print an endline symbol
*/

void CoutReset();
/*
*    Reset current output stream flags
*/

void SleepFor(int milliseconds);
/*
*    Program sleep time in milliseconds (same for Linux and Win)
*/

void ClearScr();
/*
*    Clear screen in milliseconds (same for Linux and Win)
*/

void SystemPause();
/*
*    Cross-platform system pause
*/

void BirthdayParty();
/*
*    :)
*/

void LabHeader(int index);
/*
*    Show index number of lab work, name and group
*/

const char* Declination(const char pluralWord234[], const char singleWord[], const char pluralWord[], int amount);
/*
*    Get correct word form in dependance of its amount
*/