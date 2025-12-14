#include "UrlFinder.h"

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <regex>

void runUrlFinder(const std::string& inputFile,
                  const std::string& outputFile)
{
    std::ifstream in(inputFile);

    const std::regex urlPattern(R"(\bwww\.[a-zA-Z0-9]+(\.[a-zA-Z]+)\b)");

    std::set<std::string> urls;
    std::string line;

    while (std::getline(in, line)) {
        for (std::sregex_iterator it(line.begin(), line.end(), urlPattern);
             it != std::sregex_iterator();
             ++it)
        {
            urls.insert(it->str());
        }
    }

    std::ofstream out(outputFile);
    if (!out) {
        std::cerr << "Failed to open output file: " << outputFile << "\n";
        return;
    }

    // header
    std::cout << "URLs:\n";
    std::cout << "-----------\n";

    for (const auto& url : urls) {
        std::cout << url << "\n";
    }
}
