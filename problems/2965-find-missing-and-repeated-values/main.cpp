#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> findMissingAndRepeatedValues(const std::vector<std::vector<int>> &grid) {
    size_t size = grid.size() * grid.size();
    std::vector<int> v(size, 0);

    for (const auto &cols : grid) {
        for (int n : cols) {
            ++v[n - 1];
        }
    }

    int a = 0, b = 0;
    for (size_t i = 0; i < size; ++i) {
        if (v[i] == 2) {
            a = i + 1;
        } else if (v[i] == 0) {
            b = i + 1;
        }
    }
    return {a, b};
}

int main() {
    {
        std::vector<std::vector<int>> grid{{1, 3}, {2, 2}};
        std::vector<int> expected{2, 4};
        auto ret = findMissingAndRepeatedValues(grid);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> grid{{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
        std::vector<int> expected{9, 5};
        auto ret = findMissingAndRepeatedValues(grid);
        assert(ret == expected);
    }
    return 0;
}
