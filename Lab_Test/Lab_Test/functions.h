#pragma once

#include <string>

#define DELIMITERS " ,./&!@#$%^*()-+=�;:?{}[]\\|/~`<>_\""

std::string ExtractFirstWordOfString(std::string* strIn);

bool MatchPattern(const char* symbols, char symbolCur);