#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int maxCount(int m, int n, const std::vector<std::vector<int>> &ops) {
    if (ops.empty()) {
        return m * n;
    }

    int minX = INT_MAX, minY = INT_MAX;
    for (const auto &op : ops) {
        minX = std::min(minX, op[0]);
        minY = std::min(minY, op[1]);
    }

    return minX * minY;
}

int main() {
    {
        std::vector<std::vector<int>> ops{
            {2, 2},
            {3, 3},
        };
        assert(maxCount(3, 3, ops) == 4);
    }
    {
        std::vector<std::vector<int>> ops;
        assert(maxCount(3, 3, ops) == 9);
    }
    return 0;
}
