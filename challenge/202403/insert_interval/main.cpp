#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> insert(const std::vector<std::vector<int>> &intervals, const std::vector<int> &newInterval) {
    int len = intervals.size();
    int i = 0;

    std::vector<std::vector<int>> ret;
    while (i < len && intervals[i][1] < newInterval[0]) {
        ret.push_back(intervals[i]);
        ++i;
    }

    int start = newInterval[0];
    int end = newInterval[1];
    while (i < len && newInterval[1] >= intervals[i][0]) {
        start = std::min(start, intervals[i][0]);
        end = std::max(end, intervals[i][1]);
        ++i;
    }

    ret.push_back({start, end});

    while (i < len) {
        ret.push_back(intervals[i]);
        ++i;
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> intervals{{1, 3}, {6, 9}};
        std::vector<int> newInterval{2, 5};
        std::vector<std::vector<int>> expected{{1, 5}, {6, 9}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        std::vector<int> newInterval{4, 8};
        std::vector<std::vector<int>> expected{{1, 2}, {3, 10}, {12, 16}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    return 0;
}
