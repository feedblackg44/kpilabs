#pragma once

// Round double Number to a specific decimal place
double RoundTo(double Number, int DecimalPlace);

// Get double Number from user in console using PromptMessage for asking and FailMessage if input is incorrect
float GetDouble(const char PromptMessage[], const char FailMessage[]);

// Get integer Number from user in console using PromptMessage for asking and FailMessage if input is incorrect
// If number is not integer you will get it rounded
int GetInt(const char PromptMessage[], const char FailMessage[]);

// Return minimum Number of two numbers
double Minimum(double Number1, double Number2);