#pragma once

#include <string>

void SplitStrings(std::string strIn, std::string* strOut, std::string* strMax);
/*
*   Функция разделяет строку на слова, удаляет из неё чётные слова и из оставшихся определяет самое длинное
*/

void GetInputString(std::string* strIn);
/*
*   Функция принимает из консоли строку введённую пользователем
*/

void ProgramOutput(std::string strOut, std::string strMax);
/*
*   Функция выводит результат выполнения программы
*/