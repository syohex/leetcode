#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool isBoomerang(std::vector<std::vector<int>> &points) {
    std::set<std::vector<int>> s;
    for (auto point : points) {
        s.insert(point);
    }

    points.clear();
    for (const auto& point : s) {
        points.push_back(point);
    }

    if (points.size() <= 2) {
        return false;
    }

    std::map<int, int> m;
    bool straight = false;
    for (auto point : points) {
        if (!straight && m.find(point[0]) != m.end()) {
            straight = true;
        }

        ++m[point[0]];
    }

    if (straight) {
        return m.size() != 1;
    }

    std::sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }

        return a[1] < b[1];
    });

    double xDiff = static_cast<double>(points[1][0] - points[0][0]);
    double yDiff = static_cast<double>(points[1][1] - points[0][1]);
    double diff = yDiff / xDiff;
    for (size_t i = 1; i < points.size() - 1; ++i) {
        xDiff = static_cast<double>(points[i + 1][0] - points[i][0]);
        yDiff = static_cast<double>(points[i + 1][1] - points[i][1]);
        if (yDiff / xDiff != diff) {
            return true;
        }
    }
    return false;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 1},
            {2, 3},
            {3, 2},
        };
        assert(isBoomerang(input));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1},
            {2, 2},
            {3, 3},
        };
        assert(!isBoomerang(input));
    }
    {
        std::vector<std::vector<int>> input{
            {1, 1},
            {3, 3},
        };
        assert(!isBoomerang(input));
    }
    {
        std::vector<std::vector<int>> input{
            {0, 1},
            {0, 3},
            {0, 2},
        };
        assert(!isBoomerang(input));
    }
    {
        std::vector<std::vector<int>> input{
            {0, 1},
            {0, 3},
            {1, 2},
        };
        assert(isBoomerang(input));
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0},
            {1, 1},
            {1, 1},
        };
        assert(!isBoomerang(input));
    }
    return 0;
}
