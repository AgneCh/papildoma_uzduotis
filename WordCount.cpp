#include "WordCount.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <map>

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