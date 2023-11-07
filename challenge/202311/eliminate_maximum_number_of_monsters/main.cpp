#include <cassert>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

int eliminateMaximum(const std::vector<int> &dist, const std::vector<int> &speed) {
    std::vector<double> arrival_times;
    for (size_t i = 0; i < dist.size(); ++i) {
        arrival_times.push_back(static_cast<double>(dist[i]) / speed[i]);
    }

    std::sort(arrival_times.begin(), arrival_times.end());

    int ret = 0;
    for (size_t i = 0; i < dist.size(); ++i) {
        if (arrival_times[i] <= i) {
            break;
        }
        ++ret;
    }
    return ret;
}

int main() {
    {
        std::vector<int> dist{1, 3, 4};
        std::vector<int> speed{1, 1, 1};
        int ret = eliminateMaximum(dist, speed);
        assert(ret == 3);
    }
    {
        std::vector<int> dist{1, 1, 2, 3};
        std::vector<int> speed{1, 1, 1, 1};
        int ret = eliminateMaximum(dist, speed);
        assert(ret == 1);
    }
    {
        std::vector<int> dist{3, 2, 4};
        std::vector<int> speed{5, 3, 2};
        int ret = eliminateMaximum(dist, speed);
        assert(ret == 1);
    }
    {
        std::vector<int> dist{4, 2};
        std::vector<int> speed{5, 1};
        int ret = eliminateMaximum(dist, speed);
        assert(ret == 2);
    }
    return 0;
}
