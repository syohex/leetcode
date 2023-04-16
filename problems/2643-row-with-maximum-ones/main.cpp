#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> rowAndMaximumOnes(const std::vector<std::vector<int>> &mat) {
    int max_row = -1;
    int max_ones = -1;

    for (size_t i = 0; i < mat.size(); ++i) {
        int ones = 0;
        for (int v : mat[i]) {
            ones += v;
        }

        if (ones > max_ones) {
            max_row = i;
            max_ones = ones;
        }
    }

    return {max_row, max_ones};
}

int main() {
    {
        std::vector<std::vector<int>> mat{{0, 1}, {1, 0}};
        std::vector<int> expected{0, 1};
        auto ret = rowAndMaximumOnes(mat);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> mat{{0, 0, 0}, {0, 1, 1}};
        std::vector<int> expected{1, 2};
        auto ret = rowAndMaximumOnes(mat);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> mat{{0, 0}, {1, 1}, {0, 0}};
        std::vector<int> expected{1, 2};
        auto ret = rowAndMaximumOnes(mat);
        assert(ret == expected);
    }
    return 0;
}
