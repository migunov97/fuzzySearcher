#ifndef FUZZY_SEARCHER_FUZZY_SEARCHER
#define FUZZY_SEARCHER_FUZZY_SEARCHER

#include <string>
#include <list>

using SuitableStrings = std::list<std::string>;

class FuzzySearcher
{
  public:
    FuzzySearcher(const std::string &sample);

    void SaveIfFitWithMissing(const std::string &searching);
    void SaveIfFitWithChanging(const std::string &searching);
    void SaveIfFitWithAdding(const std::string &searching);
  
  private:
    bool FitWithMissing(const std::string &searching);
    bool FitWithMissing(const std::string &searching);
    bool FitWithMissing(const std::string &searching);

    void SafeSave(const std::string &fiting);
    
    SuitableStrings m_already_saved_;
};

#endif