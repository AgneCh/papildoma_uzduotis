#include "CrossReference.h"
#include "WordCount.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

void runCrossReference(const std::string &inputFile, const std::string &outputFile)
{
    auto wordCounts = countWordsFromFile(inputFile);
    std::map<std::string, std::set<int>> wordLines;

    std::ifstream in(inputFile);
    if (!in)
    {
        std::cerr << "Error: cannot open file " << inputFile << "\n";
        return;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(in, line))
    {
        lineNumber++;

        std::istringstream iss(line);
        std::string rawWord;

        while (iss >> rawWord)
        {
            std::string word = normalize(rawWord);
            if (!word.empty() && wordCounts[word] > 1)
            {
                wordLines[word].insert(lineNumber);
            }
        }
    }

    std::ofstream out(outputFile);
    if (!out)
    {
        std::cerr << "Error: cannot open output file: " << outputFile << "\n";
        return;
    }

    // header
    out << std::left << std::setw(15) << "Word"
        << "Line numbers\n";
    out << std::string(20, '-') << ""
        << std::string(70, '-') << "\n";

    // rows
    for (const auto &[word, lines] : wordLines)
    {
        out << std::left << std::setw(15) << word;
        bool first = true;
        for (int lineNum : lines)
        {
            if (!first)
                out << ", ";
            out << lineNum;
            first = false;
        }
        out << "\n";
    }
}
