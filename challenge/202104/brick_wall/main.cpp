#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

int leastBricks(const std::vector<std::vector<int>> &wall) {
    std::map<int, int> m;
    int width = 0;
    for (const auto &row : wall) {
        int sum = 0;
        for (int width : row) {
            sum += width;

            ++m[sum];
        }

        width = sum;
    }

    int height = wall.size();
    int ret = height;
    for (const auto &it : m) {
        if (it.first != width) {
            ret = std::min(ret, height - it.second);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> bricks{
            {1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1},
        };
        assert(leastBricks(bricks) == 2);
    }
    return 0;
}
