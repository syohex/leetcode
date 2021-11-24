#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> intervalIntersection(const std::vector<std::vector<int>> &firstList,
                                                   const std::vector<std::vector<int>> &secondList) {
    std::vector<std::vector<int>> ret;
    if (firstList.empty() || secondList.empty()) {
        return ret;
    }

    for (const auto &a : firstList) {
        int start1 = a[0];
        int end1 = a[1];
        int len1 = end1 - start1;
        for (const auto &b : secondList) {
            int start2 = b[0];
            int end2 = b[1];
            int len2 = end2 - start2;

            if (start2 > end1) {
                break;
            }

            int p1 = std::min(start1, start2);
            int p2 = std::max(end1, end2);
            int len = p2 - p1;

            if (len > len1 + len2) {
                continue;
            }
            if (len == len1 + len2) {
                if (end1 == start2) {
                    ret.push_back({end1, end1});
                } else { // end2 == start1
                    ret.push_back({end2, end2});
                }
            } else {
                int max_start = std::max(start1, start2);
                int min_end = std::min(end1, end2);
                ret.push_back({max_start, min_end});
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> a{
            {0, 2},
            {5, 10},
            {13, 23},
            {24, 25},
        };
        std::vector<std::vector<int>> b{
            {1, 5},
            {8, 12},
            {15, 24},
            {25, 26},
        };
        std::vector<std::vector<int>> expected{
            {1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25},
        };

        auto ret = intervalIntersection(a, b);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> a{
            {1, 3},
            {5, 9},
        };
        std::vector<std::vector<int>> b{};

        auto ret = intervalIntersection(a, b);
        assert(ret.empty());
    }
    {
        std::vector<std::vector<int>> a{};
        std::vector<std::vector<int>> b{
            {4, 8},
            {10, 12},
        };

        auto ret = intervalIntersection(a, b);
        assert(ret.empty());
    }
    {
        std::vector<std::vector<int>> a{{1, 7}};
        std::vector<std::vector<int>> b{
            {3, 10},
        };
        std::vector<std::vector<int>> expected{
            {3, 7},
        };

        auto ret = intervalIntersection(a, b);
        assert(ret == expected);
    }
    return 0;
}