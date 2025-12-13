#include <iostream>
#include "WordCount.h"

int main() {
    int choice;

    do {
        std::cout << "1. Word count\n";
        std::cout << "2. Cross-reference table\n";
        std::cout << "3. URL search\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            runWordCount("How maths can help you wrap your presents better.txt", "words.txt");
            break;
        }
    } while (choice != 4);
}
