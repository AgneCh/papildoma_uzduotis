#include "WordCount.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <map>

std::map<std::string, int> countWordsFromFile(const std::string& inputFile) {
    std::ifstream in(inputFile);
    std::map<std::string, int> wordCounts;
    std::string rawWord;

    while (in >> rawWord) {
        std::string word = normalize(rawWord);
        if (!word.empty()) {
            wordCounts[word]++;
        }
    }
    return wordCounts;
}

void runWordCount(const std::string& inputFile,
                  const std::string& outputFile) {

    std::ofstream out(outputFile);

    for (const auto& [word, count] : countWordsFromFile(inputFile)) {
        if (count > 1) {
            out << word << " " << count << "\n";
        }
    }
}