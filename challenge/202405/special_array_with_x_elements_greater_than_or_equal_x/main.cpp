#include <cassert>
#include <vector>
#include <algorithm>

int specialArray(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int len = nums.size();
    for (int i = 1; i <= len; ++i) {
        auto p = std::lower_bound(nums.begin(), nums.end(), i);
        int index = nums.end() - p;
        if (i == index) {
            return i;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> nums{3, 5};
        int ret = specialArray(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{0, 0};
        int ret = specialArray(nums);
        assert(ret == -1);
    }
    {
        std::vector<int> nums{0, 4, 3, 0, 4};
        int ret = specialArray(nums);
        assert(ret == 3);
    }
    return 0;
}
