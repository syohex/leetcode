#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>

int smallestDivisor(std::vector<int> &nums, int threshold) {
    if (nums.size() == 1) {
        return static_cast<int>(std::ceil(nums[0] / static_cast<double>(threshold)));
    }

    const auto f = [](const std::vector<int> &v, int divisor) {
        int sum = 0;
        for (const auto i : v) {
            sum += std::ceil(static_cast<double>(i) / divisor);
        }

        return sum;
    };

    std::sort(nums.begin(), nums.end());

    int low = 1;
    int high = nums.back();
    while (low <= high) {
        int mid = low + ((high - low) / 2);
        int sum = f(nums, mid);
        if (sum > threshold) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    {
        std::vector<int> nums{1, 2, 5, 9};
        assert(smallestDivisor(nums, 6) == 5);
    }
    {
        std::vector<int> nums{2, 3, 5, 7, 11};
        assert(smallestDivisor(nums, 11) == 3);
    }
    {
        std::vector<int> nums{19};
        assert(smallestDivisor(nums, 5) == 4);
    }
    {
        std::vector<int> nums{1, 2, 3};
        assert(smallestDivisor(nums, 6) == 1);
    }
    {
        std::vector<int> nums{91, 41, 78, 86, 8};
        assert(smallestDivisor(nums, 114) == 3);
    }
    return 0;
}
