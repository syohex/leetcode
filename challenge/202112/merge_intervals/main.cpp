#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> ret;
    int len = intervals.size();
    std::vector<bool> merged(len, false);
    for (int i = 0; i < len; ++i) {
        if (merged[i]) {
            continue;
        }

        std::vector<int> base = intervals[i];
        for (int j = i + 1; j < len; ++j) {
            int start1 = base[0];
            int end1 = base[1];
            int start2 = intervals[j][0];
            int end2 = intervals[j][1];

            if (end1 < start2) {
                break;
            }

            if (start1 <= start2 && start2 <= end1) {
                if (end1 < end2) {
                    base[1] = end2;
                }
                merged[j] = true;
            }
        }
        merged[i] = true;
        ret.push_back(base);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        std::vector<std::vector<int>> expected{{1, 6}, {8, 10}, {15, 18}};
        auto ret = merge(intervals);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals{{1, 4}, {4, 5}};
        std::vector<std::vector<int>> expected{{1, 5}};
        auto ret = merge(intervals);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> intervals{{1, 4}, {2, 3}};
        std::vector<std::vector<int>> expected{{1, 4}};
        auto ret = merge(intervals);
        assert(ret == expected);
    }
    return 0;
}