#include "concurrent.h"



std::vector<TaskRange> Concurrent::BuildTaskRanges(std::vector<std::string> collection)
{
    size_t threadsCount = std::min(thread_count, collection.size());
    std::vector<size_t> borders(threadsCount + 1, 0);

    for (size_t i = 0; i <= threadsCount; ++i) {
        borders[i] = collection.size() *i / threadsCount;
    }

    std::vector<TaskRange> result(threadsCount, collection);

    for (size_t i = 0; i < threadsCount; ++i) {
        result[i].begin = borders[i];
        result[i+1].begin = borders[i+1];
    }
    return result;
}
void Concurrent::FunctionInRange(std::function<void(const std::string &)> mapFunc, TaskRange range)
{
    for (size_t i = range.begin; i < range.end; ++i) {
        mapFunc(range.array[i]);
    }
    return;
}

void Concurrent::Mapped(std::vector<std::string> vs, std::function<void(std::string &)> mapFunc)
{
    auto taskRanges = BuildTaskRanges(vs);
    std::vector<std::thread> threads(thread_count);
    for (size_t i = 0; i < threads.size(); ++i) {
        threads.push_back(std::thread(FunctionInRange(mapFunc, taskRanges[i])));

    }
}