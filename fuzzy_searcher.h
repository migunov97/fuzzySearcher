#ifndef FUZZY_SEARCHER_FUZZY_SEARCHER
#define FUZZY_SEARCHER_FUZZY_SEARCHER

#include <string>
#include <list>

namespace fuzzySearcher{

using SuitableStrings = std::list<std::string>;

class FuzzySearcher
{
  public:
    FuzzySearcher(const std::string &sample);
    
    SuitableStrings GetSaved();

    void SaveIfFitWithMissing(const std::string &searching);
    void SaveIfFitWithChanging(const std::string &searching);
    void SaveIfFitWithAdding(const std::string &searching);
  
  private:
    bool FitWithMissing(const std::string &searching);
    bool FitWithChanging(const std::string &searching);
    bool FitWithAdding(const std::string &searching);

    void SaveThreadSafely(const std::string &fiting);
    
    std::string m_sample_;
    SuitableStrings m_already_saved_;
};

}
#endif