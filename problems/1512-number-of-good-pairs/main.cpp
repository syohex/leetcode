#include <cassert>
#include <vector>

int numIndenticalPairs(const std::vector<int> &nums) {
    int ret = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] == nums[j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 1, 1, 3};
        assert(numIndenticalPairs(input) == 4);
    }
    {
        std::vector<int> input{1, 1, 1, 1};
        assert(numIndenticalPairs(input) == 6);
    }
    {
        std::vector<int> input{1, 2, 3};
        assert(numIndenticalPairs(input) == 0);
    }
    return 0;
}
