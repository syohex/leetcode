#include <cassert>
#include <vector>
#include <cstdio>

std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>> &nums, int r, int c) {
    if (nums.empty()) {
        return nums;
    }

    if (static_cast<size_t>(r * c) != nums.size() * nums[0].size()) {
        return nums;
    }

    std::vector<int> n;
    for (const auto &v : nums) {
        for (const auto num : v) {
            n.push_back(num);
        }
    }

    std::vector<std::vector<int>> ret(r);
    size_t index = 0;
    for (int i = 0; i < r; ++i) {
        ret[i].resize(c);
        for (int j = 0; j < c; ++j) {
            ret[i][j] = n[index++];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {1, 2},
            {3, 4},
        };
        auto ret = matrixReshape(input, 1, 4);

        std::vector<std::vector<int>> expected{
            {1, 2, 3, 4},
        };
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 2},
            {3, 4},
        };
        auto ret = matrixReshape(input, 4, 1);

        std::vector<std::vector<int>> expected{
            {1},
            {2},
            {3},
            {4},
        };
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> input{
            {1, 2},
            {3, 4},
        };
        auto ret = matrixReshape(input, 2, 4);
        assert(ret == input);
    }
    return 0;
}
