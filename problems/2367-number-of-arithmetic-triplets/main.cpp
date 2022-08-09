#include <cassert>
#include <vector>
#include <set>

int arithmeticTriplets(const std::vector<int> &nums, int diff) {
    std::set<int> s;
    for (int num : nums) {
        s.insert(num);
    }

    int ret = 0;
    for (int num : nums) {
        int second = num + diff;
        if (s.find(second) != s.end()) {
            int third = second + diff;
            if (s.find(third) != s.end()) {
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 1, 4, 6, 7, 10};
        int ret = arithmeticTriplets(nums, 3);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{4, 5, 6, 7, 8, 9};
        int ret = arithmeticTriplets(nums, 2);
        assert(ret == 2);
    }
    return 0;
}