#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

int distinctAverages(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::set<double> s;
    int len = nums.size();
    for (int i = 0; i < len / 2; ++i) {
        s.insert((nums[i] + nums[len - 1 - i]) / 2.0);
    }
    return s.size();
}

int main() {
    {
        std::vector<int> nums{4, 1, 4, 0, 3, 5};
        int ret = distinctAverages(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{1, 100};
        int ret = distinctAverages(nums);
        assert(ret == 1);
    }
    return 0;
}
