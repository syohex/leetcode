#include <cassert>
#include <vector>
#include <map>

int mostFrequentEvent(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (int num : nums) {
        if (num % 2 == 0) {
            ++m[num];
        }
    }

    int ret = -1;
    int min = -1;
    for (const auto &it : m) {
        if (it.second > min) {
            ret = it.first;
            min = it.second;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 1, 2, 2, 4, 4, 1};
        int ret = mostFrequentEvent(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{4, 4, 4, 9, 2, 4};
        int ret = mostFrequentEvent(nums);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{29, 47, 21, 41, 13, 37, 25, 7};
        int ret = mostFrequentEvent(nums);
        assert(ret == -1);
    }
    return 0;
}