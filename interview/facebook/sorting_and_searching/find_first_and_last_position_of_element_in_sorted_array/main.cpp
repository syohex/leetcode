#include <cassert>
#include <vector>
#include <map>

std::vector<int> searchRange(const std::vector<int> &nums, int target) {
    int min = -1;
    int max = -1;

    int limit = static_cast<int>(nums.size());
    for (int i = 0; i < limit; ++i) {
        if (nums[i] == target) {
            min = i;
            break;
        }
    }

    if (min != -1) {
        for (int i = limit - 1; i >= min; --i) {
            if (nums[i] == target) {
                max = i;
                break;
            }
        }
    }

    return std::vector<int>{min, max};
}

int main() {
    {
        std::vector<int> nums{5, 7, 7, 8, 8, 10};
        auto ret = searchRange(nums, 8);
        assert((ret == std::vector<int>{3, 4}));
    }
    {
        std::vector<int> nums{5, 7, 7, 8, 8, 10};
        auto ret = searchRange(nums, 6);
        assert((ret == std::vector<int>{-1, -1}));
    }
    {
        std::vector<int> nums{};
        auto ret = searchRange(nums, 0);
        assert((ret == std::vector<int>{-1, -1}));
    }
    {
        std::vector<int> nums{1};
        auto ret = searchRange(nums, 1);
        assert((ret == std::vector<int>{0, 0}));
    }
    return 0;
}
