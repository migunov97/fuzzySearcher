#ifndef FUZZY_SEARCHER_TEXT_FOR_SEARCHING
#define FUZZY_SEARCHER_TEXT_FOR_SEARCHING

#include <iostream>
#include <list>
#include <vector>

#include "fuzzy_searcher.h"

namespace fuzzySearcher
{

using Text = std::vector<std::vector<std::string>>;

class TextForSearching
{
  public:
    TextForSearching(const std::string &file_name);
    
    std::list<std::string> FuzzySearch(std::string &sample);

  private:
    std::ifstream& GetFile(std::string file_name);
    

    void Add(const std::string &line);
    bool ThereAreStringsWithLength(size_t length);

    Text m_strings_with_length_;    
};


}

#endif