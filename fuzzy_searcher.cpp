

#include "fuzzy_searcher.h"
#include <mutex>
using namespace fuzzySearcher;
FuzzySearcher::FuzzySearcher(const std::string &sample): m_sample_(sample)
{
}

SuitableStrings FuzzySearcher::GetSaved()
{
    return m_already_saved_;
}

void FuzzySearcher::SaveIfFitWithMissing(const std::string &searching)
{
    if (FitWithMissing(searching)) 
        SaveThreadSafely(searching);
}

void FuzzySearcher::SaveIfFitWithChanging(const std::string &searching)
{
    if (FitWithChanging(searching))
        SaveThreadSafely(searching);
}

void FuzzySearcher::SaveIfFitWithAdding(const std::string &searching)
{
    if (FitWithAdding(searching))
        SaveThreadSafely(searching);
}

void FuzzySearcher::SaveThreadSafely(const std::string &fiting)
{
    static std::mutex mutex;
    std::lock_guard<std::mutex> guard(mutex);

    m_already_saved_.emplace_back(fiting);   
}