
#include <iostream>

#include "text_for_searching.h"
#include <fstream>
std::ifstream& getFile(const std::string &preliminary_file_name)
{
    std::ifstream file(preliminary_file_name);
    if (file.is_open())
        return file;
    else {
        
    }     
}
//placeholder x 2
//порядокаргументоввимени?
//одно действие

int main(char argc, char **argv)
{
    using namespace fuzzySearcher;
    std::string preliminaryFileName;
    if (argc > 1) 
        preliminaryFileName = argv[1];

    std::ifstream file = std::move(getFile(preliminaryFileName));
    TextForSearching text(file);
    std::string searching;

    while (true) {
        std::cin >> searching;
        text.FuzzySearch(searching);
    }
    
    std::cout<<"\nooo\n";
    return 0;
}


