#include "CrossReference.h"
#include "WordCount.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

void runCrossReference(const std::string &inputFile, const std::string &outputFile)
{
    auto wordCounts = countWordsFromFile(inputFile);
    std::map<std::string, std::set<int>> wordLines;

    std::ifstream in(inputFile);
    if (!in)
    {
        std::cerr << "Failed to open: " << inputFile << "\n";
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
    for (const auto &[word, lines] : wordLines)
    {
        if (lines.size() > 1)
        {
            out << word << ": ";
            for (int ln : lines)
            {
                out << ln << " ";
            }
            out << "\n";
        }
    }
}
