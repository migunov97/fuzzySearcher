#ifndef FUZZY_SEARCHER_CONCURRENT
#define FUZZY_SEARCHER_CONCURRENT

#include <functional>
#include <vector>
#include <string>
#include <thread>
namespace FuzzySearcher{
    struct TaskRange
    {
        size_t begin;
        size_t end;

        TaskRange(size_t begin = 0, size_t end = 0): begin(begin), end(end) {}
    };
};
class Concurrent
{
  public:  
    Concurrent();

    void mapped(std::vector<std::string> vs, std::function<void(std::string &)> mapFunc);

  private:
    std::vector<TaskRange> BuildTaskRanges(std::vector<std::string> vs);

    size_t thread_count;    
};

#endif