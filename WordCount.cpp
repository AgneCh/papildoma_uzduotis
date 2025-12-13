#include "WordCount.h"
#include <iostream>
#include <fstream>
#include <map>
#include<cctype>

static std::string normalize(const std::string& rawWord) {
    std::string noramlizedWord;
    for (unsigned char ch : rawWord) {
        if (std::isalnum(ch)) {
            noramlizedWord.push_back(std::tolower(ch));
        }
    }
    return noramlizedWord;
}

void runWordCount(const std::string& inputFile,
                  const std::string& outputFile) {
    std::ifstream in(inputFile);

    std::string rawWord;

    while (in >> rawWord) {
        std::string word = normalize(rawWord);
        if (!word.empty()) {
            std::cout << word << "\n";
        }
    }
}