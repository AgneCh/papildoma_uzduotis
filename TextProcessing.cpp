#include "TextProcessing.h"
#include<cctype>

std::string normalize(const std::string& rawWord) {
    std::string normalizedWord;

    for (unsigned char ch : rawWord) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            normalizedWord.push_back(
                static_cast<char>(std::tolower(static_cast<unsigned char>(ch)))
            );
        }
    }
    return normalizedWord;
}