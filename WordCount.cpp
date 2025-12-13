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
    std::ofstream out(outputFile);

    std::map<std::string, int> wordCounts;
    std::string rawWord;

    while (in >> rawWord) {
        std::string word = normalize(rawWord);
        if (!word.empty()) {
            wordCounts[word]++;
        }
    }

    for (const auto& [word, count] : wordCounts) {
        if (count > 1) {
            out << word << " " << count << "\n";
        }
    }
}