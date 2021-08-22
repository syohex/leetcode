#include <cassert>
#include <vector>
#include <climits>
#include <algorithm>

int findGCD(const std::vector<int> &nums) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (int num : nums) {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    while (true) {
        int mod = max % min;
        if (mod == 0) {
            return min;
        }

        max = min;
        min = mod;
    }

    // never reach here
    return -1;
}

int main() {
    {
        std::vector<int> nums{2, 5, 6, 9, 10};
        assert(findGCD(nums) == 2);
    }
    {
        std::vector<int> nums{7, 5, 6, 8, 3};
        assert(findGCD(nums) == 1);
    }
    {
        std::vector<int> nums{3, 3};
        assert(findGCD(nums) == 3);
    }
    return 0;
}