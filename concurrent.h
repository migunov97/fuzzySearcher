#ifndef FUZZY_SEARCHER_CONCURRENT
#define FUZZY_SEARCHER_CONCURRENT

#include <functional>
#include <vector>
#include <string>
#include <thread>

namespace fuzzySearcher{
struct TaskRange
{
    const std::vector<std::string> &array;
    size_t begin;
    size_t end;
    
    TaskRange(const std::vector<std::string> &array, size_t begin = 0, size_t end = 0): 
        array(array), begin(begin), end(end) {}
};

class Concurrent
{
  public:  
    Concurrent();

    void Mapped(std::vector<std::string> vs, std::function<void(const std::string &)> mapFunc);

  private:
    std::vector<TaskRange> BuildTaskRanges(std::vector<std::string> vs);
    void FunctionInRange(std::function<void(const std::string &)> mapFunc, TaskRange range);
    
    size_t thread_count;    
};
}
#endif