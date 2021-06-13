#include <cassert>
#include <vector>
#include <algorithm>

bool isCovered(const std::vector<std::vector<int>> &ranges, int left, int right) {
    std::vector<bool> table(right + 1);
    for (const auto &range : ranges) {
        for (int i = range[0]; i <= range[1]; ++i) {
            if (i > right) {
                break;
            }

            table[i] = true;
        }
    }

    for (int i = left; i <= right; ++i) {
        if (!table[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> ranges{{1, 2}, {3, 4}, {5, 6}};
        assert(isCovered(ranges, 2, 5));
    }
    {
        std::vector<std::vector<int>> ranges{{1, 10}, {10, 20}};
        assert(!isCovered(ranges, 21, 21));
    }
    return 0;
}