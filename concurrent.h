#include <functional>
#include <vector>
#include <string>
#include <thread>
namespace{
    struct TaskRange
    {
        size_t begin_;
        size_t end_;

        TaskRange(size_t begin = 0, size_t end = 0): begin_(begin), end_(end) {}
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