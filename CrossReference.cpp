#include "CrossReference.h"
#include "TextProcessing.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

void runCrossReference(const std::string &inputFile)
{
    std::ifstream in(inputFile);
    if (!in)
    {
        std::cerr << "Failed to open: " << inputFile << "\n";
        return;
    }

    std::map<std::string, std::set<int>> wordLines;

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
            if (!word.empty())
            {
                wordLines[word].insert(lineNumber);
            }
        }
    }

    for (const auto &[word, lines] : wordLines)
    {
        std::cout << word << ": ";
        for (int ln : lines)
        {
            std::cout << ln << " ";
        }
        std::cout << "\n";
    }
}
