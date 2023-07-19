#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int eraseOverlapItervals(std::vector<std::vector<int>> &intervals) {
    const auto cmp = [](const std::vector<int> &a, const std::vector<int> &b) -> bool { return a[1] < b[1]; };

    std::sort(intervals.begin(), intervals.end(), cmp);

    int ret = 0;
    int end = -1'000'000;
    for (const auto &interval : intervals) {
        if (interval[0] >= end) {
            end = interval[1];
        } else {
            ret += 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
        int ret = eraseOverlapItervals(intervals);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<int>> intervals{{1, 2}, {1, 2}, {1, 2}};
        int ret = eraseOverlapItervals(intervals);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}};
        int ret = eraseOverlapItervals(intervals);
        assert(ret == 0);
    }
    return 0;
}
