#include "WordCount.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

std::map<std::string, int> countWordsFromFile(const std::string &inputFile)
{
    std::ifstream in(inputFile);
    if (!in)
    {
        std::cerr << "Error: cannot open file " << inputFile << "\n";
        return {};
    }

    std::map<std::string, int> wordCounts;
    std::string rawWord;

    while (in >> rawWord)
    {
        std::string word = normalize(rawWord);
        if (!word.empty())
        {
            wordCounts[word]++;
        }
    }
    return wordCounts;
}

void runWordCount(const std::string &inputFile,
                  const std::string &outputFile)
{
    auto counts = countWordsFromFile(inputFile);
    if (counts.empty())
    {
        return;
    }

    std::ofstream out(outputFile);

    // header
    out << std::left << std::setw(15) << "Word"
        << "Count\n";
    out << std::string(15, '-') << ""
        << std::string(10, '-') << "\n";

    for (const auto &[word, count] : counts)
    {
        if (count > 1)
        {
            out << std::left
                << std::setw(15) << word
                << std::setw(10) << count << "\n";
        }
    }
}