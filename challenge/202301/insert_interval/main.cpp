#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <limits>

std::vector<std::vector<int>> insert(const std::vector<std::vector<int>> &intervals, const std::vector<int> &newInterval) {
    std::vector<std::vector<int>> ret;
    if (intervals.empty()) {
        ret.push_back(newInterval);
        return ret;
    }

    bool overlapped = false;
    int overlapped_start = std::numeric_limits<int>::max();
    int overlapped_end = std::numeric_limits<int>::min();
    int len = intervals.size();

    for (int i = 0; i < len; ++i) {
        if (i == 0) {
            if (newInterval[1] < intervals[i][0]) {
                ret.push_back({newInterval[0], newInterval[1]});
            }
        }

        int start = std::max(intervals[i][0], newInterval[0]);
        int end = std::min(intervals[i][1], newInterval[1]);
        if (start <= end) {
            overlapped = true;
            overlapped_start = std::min({overlapped_start, intervals[i][0], newInterval[0]});
            overlapped_end = std::max({overlapped_end, intervals[i][1], newInterval[1]});
        } else {
            if (overlapped) {
                overlapped = false;
                ret.push_back({overlapped_start, overlapped_end});
            } else if (i >= 1) {
                if (intervals[i - 1][1] < newInterval[0] && newInterval[1] < intervals[i][0]) {
                    ret.push_back({newInterval[0], newInterval[1]});
                }
            }

            ret.push_back({intervals[i][0], intervals[i][1]});

            if (i == len - 1) {
                if (newInterval[0] > intervals[i][1]) {
                    ret.push_back({newInterval[0], newInterval[1]});
                }
            }
        }
    }

    if (overlapped) {
        ret.push_back({overlapped_start, overlapped_end});
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
    {
        std::vector<std::vector<int>> intervals{{1, 3}, {6, 9}};
        std::vector<int> newInterval{1, 10};
        std::vector<std::vector<int>> expected{{1, 10}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals;
        std::vector<int> newInterval{5, 7};
        std::vector<std::vector<int>> expected{{5, 7}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals{{3, 5}, {6, 9}};
        std::vector<int> newInterval{1, 2};
        std::vector<std::vector<int>> expected{{1, 2}, {3, 5}, {6, 9}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals{{3, 5}, {6, 9}};
        std::vector<int> newInterval{10, 20};
        std::vector<std::vector<int>> expected{{3, 5}, {6, 9}, {10, 20}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals{{1, 3}, {6, 9}};
        std::vector<int> newInterval{4, 5};
        std::vector<std::vector<int>> expected{{1, 3}, {4, 5}, {6, 9}};
        auto ret = insert(intervals, newInterval);
        assert(ret == expected);
    }
    return 0;
}
