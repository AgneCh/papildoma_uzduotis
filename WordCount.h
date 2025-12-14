#pragma once
#include <string>
#include <map>

void runWordCount(const std::string &inoutFile, const std::string &outputFile);
std::map<std::string, int> countWordsFromFile(const std::string& inputFile);
