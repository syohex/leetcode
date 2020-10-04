#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

int removeCoveredIntervals(const std::vector<std::vector<int>> &intervals) {
    std::map<int, int> m;
    for (const auto &interval : intervals) {
        if (m.find(interval[0]) == m.end()) {
            m[interval[0]] = interval[1];
        } else {
            if (m[interval[0]] < interval[1]) {
                m[interval[0]] = interval[1];
            }
        }
    }

    int removed = 0;
    for (const auto &interval : intervals) {
        for (const auto &it : m) {
            if (interval[0] < it.first) {
                break;
            }

            if (interval[0] == it.first && interval[1] == it.second) {
                continue;
            }

            if (interval[1] <= it.second) {
                ++removed;
                break;
            }
        }
    }

    return static_cast<int>(intervals.size()) - removed;
}

int main() {
    {
        std::vector<std::vector<int>> inputs{
            {1, 4},
            {3, 6},
            {2, 8},
        };
        assert(removeCoveredIntervals(inputs) == 2);
    }
    {
        std::vector<std::vector<int>> inputs{
            {1, 4},
            {2, 3},
        };
        assert(removeCoveredIntervals(inputs) == 1);
    }
    {
        std::vector<std::vector<int>> inputs{
            {0, 10},
            {5, 12},
        };
        assert(removeCoveredIntervals(inputs) == 2);
    }
    {
        std::vector<std::vector<int>> inputs{
            {3, 10},
            {4, 10},
            {5, 11},
        };
        assert(removeCoveredIntervals(inputs) == 2);
    }
    {
        std::vector<std::vector<int>> inputs{
            {1, 2},
            {1, 4},
            {3, 4},
        };
        assert(removeCoveredIntervals(inputs) == 1);
    }
    return 0;
}
