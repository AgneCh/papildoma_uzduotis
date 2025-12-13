#include "CrossReference.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

void runCrossReference(const std::string& inputFile) {
    std::ifstream in(inputFile);
    if (!in) {
        std::cerr << "Failed to open: " << inputFile << "\n";
        return;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(in, line)) {
        lineNumber++;

        std::istringstream iss(line);
        std::string rawWord;

        while (iss >> rawWord) {
            std::string word = normalize(rawWord);
            if (!word.empty()) {
                std::cout << "LINE " << lineNumber << ": " << word << "\n";
            }
        }
    }
}
