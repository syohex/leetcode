#include <cassert>
#include <vector>
#include <algorithm>

int findLHS(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int ret = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        int count = 1;
        bool has_one_plus = false;
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] == nums[j]) {
                ++count;
            } else if (nums[i] + 1 == nums[j]) {
                ++count;
                has_one_plus = true;
            } else {
                break;
            }
        }

        if (has_one_plus) {
            ret = std::max(ret, count);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 3, 2, 2, 5, 2, 3, 7};
        assert(findLHS(input) == 5);
    }
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(findLHS(input) == 2);
    }
    {
        std::vector<int> input{1, 1, 1, 1};
        assert(findLHS(input) == 0);
    }
    {
        std::vector<int> input{1, 2, 2, 1};
        assert(findLHS(input) == 4);
    }
    {
        std::vector<int> input{-3, -1, -1, -1, -3, -2};
        assert(findLHS(input) == 4);
    }
    {
        std::vector<int> input{2, 2, 2, 2, 2, 2, 2, 3, 1, 0, 0, 0, 3, 1, -1, 0, 1, 1, 0, 0, 1, 1, 2, 2, 2, 0, 1, 2, 2, 3, 2};
        assert(findLHS(input) == 20);
    }
    return 0;
}
