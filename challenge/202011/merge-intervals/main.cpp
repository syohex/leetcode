#include <cassert>
#include <vector>
#include <algorithm>
#include <tuple>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.size() == 1) {
        return intervals;
    }

    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) { return std::tie(a[0], a[1]) < std::tie(b[0], b[1]); });

    std::vector<std::vector<int>> ret;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (end < intervals[i][0]) {
            ret.emplace_back(std::vector<int>{start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        } else if (end <= intervals[i][1]) {
            end = intervals[i][1];
        }

        if (i == intervals.size() - 1) {
            ret.emplace_back(std::vector<int>{start, end});
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> intervals{
            {1, 3},
            {2, 6},
            {8, 10},
            {15, 18},
        };

        auto ret = merge(intervals);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{1, 6}));
        assert((ret[1] == std::vector<int>{8, 10}));
        assert((ret[2] == std::vector<int>{15, 18}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {1, 4},
            {4, 5},
        };

        auto ret = merge(intervals);
        assert(ret.size() == 1);
        assert((ret[0] == std::vector<int>{1, 5}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {1, 3},
            {4, 5},
        };

        auto ret = merge(intervals);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{1, 3}));
        assert((ret[1] == std::vector<int>{4, 5}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {1, 2},
            {4, 5},
            {4, 8},
        };

        auto ret = merge(intervals);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{1, 2}));
        assert((ret[1] == std::vector<int>{4, 8}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {0, 0},
            {1, 1},
            {2, 2},
        };

        auto ret = merge(intervals);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{0, 0}));
        assert((ret[1] == std::vector<int>{1, 1}));
        assert((ret[2] == std::vector<int>{2, 2}));
    }
    return 0;
}
