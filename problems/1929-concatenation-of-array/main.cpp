#include <cassert>
#include <vector>

std::vector<int> getConcateenation(const std::vector<int> &nums) {
    size_t len = nums.size();
    std::vector<int> ret(len * 2);

    for (size_t i = 0; i < len; ++i) {
        ret[i] = ret[i + len] = nums[i];
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 1};
        std::vector<int> expected{1, 2, 1, 1, 2, 1};
        assert(getConcateenation(nums) == expected);
    }
    {
        std::vector<int> nums{1, 3, 2, 1};
        std::vector<int> expected{1, 3, 2, 1, 1, 3, 2, 1};
        assert(getConcateenation(nums) == expected);
    }
    return 0;
}