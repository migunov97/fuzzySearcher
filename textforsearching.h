
#include <iostream>
#include <list>
#include <vector>

using Text = std::vector<std::vector<std::string>>;

class TextForSearching
{
  public:
    TextForSearching(std::ifstream& file);

    std::list<std::string> FuzzySearch(std::string &sample);
  private:
    Text m_strings_by_length;    
};