#include <cassert>
#include <vector>
#include <algorithm>

int maxWidthOfVerticalArea(std::vector<std::vector<int>> &points) {
    std::sort(points.begin(), points.end());

    int ret = 0;
    for (size_t i = 1; i < points.size(); ++i) {
        ret = std::max(ret, points[i][0] - points[i - 1][0]);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> points{{8, 7}, {9, 9}, {7, 4}, {9, 7}};
        int ret = maxWidthOfVerticalArea(points);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<int>> points{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
        int ret = maxWidthOfVerticalArea(points);
        assert(ret == 3);
    }
    return 0;
}
