#include <cassert>
#include <vector>
#include <algorithm>

int findMinArrowShots(std::vector<std::vector<int>> &points) {
    const auto cmp = [](const std::vector<int> &a, const std::vector<int> &b) -> bool { return a[0] < b[0]; };
    std::sort(points.begin(), points.end(), cmp);

    int end = points[0][1];

    int ret = 1;
    for (size_t i = 1; i < points.size(); ++i) {
        const auto &next = points[i];
        if (next[0] <= end) {
            end = std::min(end, next[1]);
        } else {
            ++ret;
            end = next[1];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        assert(findMinArrowShots(points) == 2);
    }
    {
        std::vector<std::vector<int>> points{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        assert(findMinArrowShots(points) == 4);
    }
    {
        std::vector<std::vector<int>> points{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
        assert(findMinArrowShots(points) == 2);
    }
    return 0;
}
