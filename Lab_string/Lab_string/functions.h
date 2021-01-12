#pragma once

#include <string>

#define DELIMITERS " ,.:;\'\""

std::string ExtractFisrtWordOfString(std::string* strIn);

bool MatchPattern(const char* symbols, char symbol);

std::string makeOutString(std::string strIn);