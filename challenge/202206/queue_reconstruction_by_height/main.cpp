#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people) {
    std::sort(people.begin(), people.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }

        return a[0] > b[0];
    });

    std::vector<std::vector<int>> ret;
    for (const auto &p : people) {
        ret.insert(ret.begin() + p[1], p);
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> people{
            {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2},
        };
        std::vector<std::vector<int>> expected{
            {5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1},
        };

        auto ret = reconstructQueue(people);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> people{
            {6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4},
        };
        std::vector<std::vector<int>> expected{
            {4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0},
        };

        auto ret = reconstructQueue(people);
        assert(ret == expected);
    }
    return 0;
}