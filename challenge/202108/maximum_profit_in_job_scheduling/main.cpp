#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

int jobScheduling(std::vector<int> &startTime, const std::vector<int> &endTime, const std::vector<int> &profit) {
    struct Job {
        int start;
        int end;
        int profit;
    };

    const auto cmp = [](const Job &a, const Job &b) -> bool { return a.start < b.start; };

    std::vector<Job> jobs;
    size_t len = startTime.size();
    for (size_t i = 0; i < len; ++i) {
        jobs.push_back(Job{startTime[i], endTime[i], profit[i]});
    }

    std::sort(jobs.begin(), jobs.end(), cmp);
    std::sort(startTime.begin(), startTime.end());

    std::map<size_t, int> cache;
    std::function<int(size_t pos)> f;
    f = [&](size_t pos) -> int {
        if (pos >= len) {
            return 0;
        }

        if (cache.find(pos) != cache.end()) {
            return cache[pos];
        }

        auto it = std::lower_bound(startTime.begin(), startTime.end(), jobs[pos].end);
        size_t next_job_index = it - startTime.begin();

        int accepted = jobs[pos].profit + f(next_job_index);
        int skipped = f(pos + 1);

        cache[pos] = std::max(accepted, skipped);
        return cache[pos];
    };

    return f(0);
}

int main() {
    {
        std::vector<int> startTime{1, 2, 3, 4, 6};
        std::vector<int> endTime{3, 5, 10, 6, 9};
        std::vector<int> profit{20, 20, 100, 70, 60};
        assert(jobScheduling(startTime, endTime, profit) == 150);
    }
    {
        std::vector<int> startTime{1, 1, 1};
        std::vector<int> endTime{2, 3, 4};
        std::vector<int> profit{5, 6, 4};
        assert(jobScheduling(startTime, endTime, profit) == 6);
    }
    {
        std::vector<int> startTime{4, 2, 4, 8, 2};
        std::vector<int> endTime{5, 5, 5, 10, 8};
        std::vector<int> profit{1, 2, 8, 10, 4};
        assert(jobScheduling(startTime, endTime, profit) == 18);
    }
    return 0;
}