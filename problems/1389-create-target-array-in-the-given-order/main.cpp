#include <cassert>
#include <vector>
#include <cstdio>

void print(const std::vector<int> &v, size_t n) {
    printf("[");
    for (size_t i = 0; i <= n; ++i) {
        printf(" %d ", v[i]);
    }
    printf("]\n");
}

std::vector<int> createTargetArray(const std::vector<int> &nums, const std::vector<int> &index) {
    if (nums.empty()) {
        return std::vector<int>{};
    }

    std::vector<int> ret;
    ret.resize(nums.size());
    ret[0] = nums[index[0]];
    for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
        if (index[i] < i) {
            for (int j = i; j > index[i]; --j) {
                ret[j] = ret[j - 1];
            }
        }

        ret[index[i]] = nums[i];
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 1, 2, 3, 4};
        std::vector<int> index{0, 1, 2, 2, 1};
        std::vector<int> expected{0, 4, 1, 3, 2};

        auto ret = createTargetArray(nums, index);
        assert(ret == expected);
    }
    {

        std::vector<int> nums{1, 2, 3, 4, 0};
        std::vector<int> index{0, 1, 2, 3, 0};
        std::vector<int> expected{0, 1, 2, 3, 4};

        auto ret = createTargetArray(nums, index);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1};
        std::vector<int> index{0};
        std::vector<int> expected{1};

        auto ret = createTargetArray(nums, index);
        assert(ret == expected);
    }
    return 0;
}
