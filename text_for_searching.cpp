#include "text_for_searching.h"

#include <fstream>
#include "concurrent.h"
TextForSearching::TextForSearching(std::ifstream &file)
{
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            Add(line);
        }
    }
}

void TextForSearching::Add(const std::string &str)
{
    if (strings_with_length.size() < str.size())
        strings_with_length.reserve(str.size());

    strings_with_length[str.size()].emplace_back(str);
    return;    
}

bool TextForSearching::ThereAreStringsWithLength(size_t length)
{
    if (length <= strings_with_length.size())
        return !strings_with_length[length].empty();
    else 
        return false;    
}

std::list<std::string> TextForSearching::FuzzySearch(std::string &sample)
{
    FuzzySearcher searcher(sample);
    Concurrent concurrent;
    size_t length = sample.size();
    if (ThereAreStringsWithLength(sample.size()))
        concurrent.Mapped(strings_with_length[length - 1])

}