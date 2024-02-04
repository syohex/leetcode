#include <cassert>
#include <vector>

int returnToBoundaryCount(const std::vector<int> &nums) {
    int pos = 0;
    int ret = 0;
    for (int num : nums) {
        pos += num;
        if (pos == 0) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 3, -5};
        int ret = returnToBoundaryCount(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{3, 2, -3, -4};
        int ret = returnToBoundaryCount(nums);
        assert(ret == 0);
    }
    return 0;
}
