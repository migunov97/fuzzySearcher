
#include <iostream>

#include "text_for_searching.h"
#include <fstream>

int main(char argc, char **argv)
{
    using namespace fuzzySearcher;


    std::string preliminaryFileName{""};
    if (argc > 1) 
        preliminaryFileName = argv[1];

    TextForSearching text(preliminaryFileName);
    
    std::string searching;

    while (true) {
        std::cin >> searching;
        text.FuzzySearch(searching);
    }
    
    std::cout<<"\nooo\n";
    return 0;
}


