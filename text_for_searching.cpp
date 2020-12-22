

#include <fstream>

#include "concurrent.h"
#include "text_for_searching.h"

using namespace fuzzySearcher;
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
    if (m_strings_with_length_.size() < str.size())
        m_strings_with_length_.reserve(str.size());

    m_strings_with_length_[str.size()].emplace_back(str);
    return;    
}



std::list<std::string> TextForSearching::FuzzySearch(std::string &sample)
{
    FuzzySearcher searcher(sample);
    Concurrent concurrent;
    size_t length = sample.size();

    if (ThereAreStringsWithLength(length - 1))
        concurrent.Mapped(m_strings_with_length_[length - 1],
            [&concurrent, &searcher, &sample](const std::string &str)
            {
                searcher.SaveIfFitWithMissing(str);
            }
        ); 
    
    if (ThereAreStringsWithLength(length))
        concurrent.Mapped(m_strings_with_length_[length],
            [&concurrent, &searcher, &sample](const std::string &str)
            {
                searcher.SaveIfFitWithChanging(str);
            }
        ); 
 
    if (ThereAreStringsWithLength(length + 1))
        concurrent.Mapped(m_strings_with_length_[length + 1],
            [&concurrent, &searcher, &sample](const std::string &str)
            {
                searcher.SaveIfFitWithAdding(str);
            }
        ); 
    
    return searcher.GetSaved();
    
}

bool TextForSearching::ThereAreStringsWithLength(size_t length)
{
    if (length <= m_strings_with_length_.size())
        return !m_strings_with_length_[length].empty();
    else 
        return false;    
}