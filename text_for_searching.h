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
    TextForSearching(std::ifstream &file);

    std::list<std::string> FuzzySearch(std::string &sample);

  private:
    void Add(const std::string &line);
    bool ThereAreStringsWithLength(size_t length);

    Text m_strings_with_length_;    
};


}

#endif