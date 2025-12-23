#include "WordCount.h"
#include "CrossReference.h"
#include "UrlFinder.h"

#include <iostream>
#include <limits>


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
        
        if(!(std::cin >> choice) || choice > 4){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number (1-4). \n";
            continue;
        }

        switch (choice)
        {
        case 1:
            runWordCount("How maths can help you wrap your presents better.txt", "countedWords.txt");
            break;
        case 2:
            runCrossReference("How maths can help you wrap your presents better.txt", "crossReference.txt");
            break;
        case 3:
            runUrlFinder("The man who turned The Beatles into superstars.txt", "URLlist.txt");
            break;
        }

    } while (choice != 4);
}
