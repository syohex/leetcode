#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

double minimumAverage(std::vector<int> &nums) {
    std::vector<double> average;
    int len = nums.size();

    for (int i = 0; i < len / 2; ++i) {
        std::sort(nums.begin(), nums.end());

        double min = nums[0];
        double max = nums[nums.size() - 1];
        nums.pop_back();
        std::swap(nums[0], nums.back());
        nums.pop_back();

        average.push_back((min + max) / 2);
    }

    return *std::min_element(average.begin(), average.end());
}

int main() {
    {
        std::vector<int> nums{7, 8, 3, 4, 15, 13, 4, 1};
        auto ret = minimumAverage(nums);
        assert(ret == 5.5);
    }
    {
        std::vector<int> nums{1, 9, 8, 3, 10, 5};
        auto ret = minimumAverage(nums);
        assert(ret == 5.5);
    }
    {
        std::vector<int> nums{1, 2, 3, 7, 8, 9};
        auto ret = minimumAverage(nums);
        assert(ret == 5.0);
    }
    return 0;
}
