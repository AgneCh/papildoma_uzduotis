#include "UrlFinder.h"
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <regex>
#include <unordered_set>
#include <algorithm>
#include <cctype>

static std::unordered_set<std::string> loadTlds(const std::string &tldList)
{
    std::ifstream tldIn(tldList);
    if (!tldIn)
    {
        std::cerr << "Error: cannot open TLD list file " << tldList << "\n";
        return {};
    }

    std::unordered_set<std::string> tldSet;
    std::string tld;

    while (std::getline(tldIn, tld))
    {
        if (tld.empty())
            continue;
        tldSet.insert(tld);
    }

    return tldSet;
}

static std::string getTldFromMatch(const std::string &s)
{
    size_t hostStart = 0;
    size_t schemePos = s.find("://");
    if (schemePos != std::string::npos)
        hostStart = schemePos + 3;

    size_t hostEnd = s.find_first_of("/?#", hostStart);
    if (hostEnd == std::string::npos)
        hostEnd = s.size();

    // skip "www." if in the host
    if (hostEnd >= hostStart + 4 && s.compare(hostStart, 4, "www.") == 0)
        hostStart += 4;

    // find last dot within host
    size_t dot = s.rfind('.', hostEnd - 1);
    if (dot == std::string::npos || dot < hostStart || dot + 1 >= hostEnd)
        return "";

    // return TLD after last dot until hostEnd
    return s.substr(dot + 1, hostEnd - (dot + 1));
}

static std::string toLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return (char)std::tolower(c); });
    return s;
}

void runUrlFinder(const std::string &inputFile,
                  const std::string &outputFile)
{
    auto tlds = loadTlds("tldList.txt");
    if (tlds.empty())
        return;

    std::ifstream in(inputFile);
    if (!in)
    {
        std::cerr << "Error: cannot open text file " << inputFile << "\n";
        return;
    }

    const std::regex urlPattern(R"(\b(?:https?:\/\/|www\.)?(?:[A-Za-z0-9-]+\.)+[A-Za-z]{2,}(?:[^\s'"}\]\)]*[^\s.,'"}\]\)])?)");

    std::set<std::string> urls;
    std::string line;

    while (std::getline(in, line))
    {
        for (std::sregex_iterator it(line.begin(), line.end(), urlPattern);
             it != std::sregex_iterator();
             ++it)
        {
            std::string match = it->str();
            std::string tld = toLower(getTldFromMatch(match));

            if (!tld.empty() && tlds.find(tld) != tlds.end())
            {
                urls.insert(match);
            }
        }
    }

    std::ofstream out(outputFile);
    if (!out)
    {
        std::cerr << "Failed to open output file: " << outputFile << "\n";
        return;
    }

    // header
    out << "URLs:\n";
    out << "-----------\n";

    for (const auto &url : urls)
    {
        out << url << "\n";
    }
}