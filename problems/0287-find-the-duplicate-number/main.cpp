#include <cassert>
#include <vector>
#include <algorithm>

int findDuplicate(const std::vector<int> &nums) {
    std::vector<int> v(nums.size(), 0);

    for (int num : nums) {
        v[num - 1] += num;
    }

    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        if (v[i] != 0 && v[i] != i + 1) {
            return static_cast<int>(i + 1);
        }
    }

    assert(!"never reach here");
    return 0;
}

int main() {
    {
        std::vector<int> nums{1, 3, 4, 2, 2};
        assert(findDuplicate(nums) == 2);
    }
    {
        std::vector<int> nums{3, 1, 3, 4, 2};
        assert(findDuplicate(nums) == 3);
    }
    {
        std::vector<int> nums{1, 1};
        assert(findDuplicate(nums) == 1);
    }
    {
        std::vector<int> nums{1, 1, 2};
        assert(findDuplicate(nums) == 1);
    }
    {
        std::vector<int> nums{2, 2, 2, 2, 2};
        assert(findDuplicate(nums) == 2);
    }
    return 0;
}
