#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

int nearestValidPoint(int x, int y, const std::vector<std::vector<int>> &points) {
    int min = INT_MAX;
    int ret = -1;
    for (size_t i = 0; i < points.size(); ++i) {
        if (!(points[i][0] == x || points[i][1] == y)) {
            continue;
        }

        int dist = std::abs(points[i][0] - x) + std::abs(points[i][1] - y);
        if (dist < min) {
            min = dist;
            ret = static_cast<int>(i);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> points{{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
        assert(nearestValidPoint(3, 4, points) == 2);
    }
    {
        std::vector<std::vector<int>> points{{3, 4}};
        assert(nearestValidPoint(3, 4, points) == 0);
    }
    {
        std::vector<std::vector<int>> points{{2, 3}};
        assert(nearestValidPoint(3, 4, points) == -1);
    }
    return 0;
}
