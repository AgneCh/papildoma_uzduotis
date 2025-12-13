#include "WordCount.h"
#include "CrossReference.h"

#include <iostream>

int main()
{
    int choice;

    do
    {
        std::cout << "1. Word count\n";
        std::cout << "2. Cross-reference table\n";
        std::cout << "3. URL search\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            runWordCount("test.txt", "words.txt");
            break;
        case 2:
            runCrossReference("test.txt");
            break;
        }

    } while (choice != 4);
}
