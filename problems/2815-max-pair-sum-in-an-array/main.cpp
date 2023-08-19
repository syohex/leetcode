#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int maxSum(const std::vector<int> &nums) {
    std::vector<std::vector<int>> v(10, std::vector<int>{});

    for (int num : nums) {
        int n = num;
        int max_digit = 0;
        while (n > 0) {
            max_digit = std::max(max_digit, n % 10);
            n /= 10;
        }

        v[max_digit].push_back(num);
    }

    for (int i = 0; i < 10; ++i) {
        std::sort(v[i].begin(), v[i].end(), [](int a, int b) { return a > b; });
    }

    int ret = -1;
    for (int i = 0; i < 10; ++i) {
        if (v[i].size() >= 2) {
            ret = std::max(ret, v[i][0] + v[i][1]);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{51, 71, 17, 24, 42};
        int ret = maxSum(nums);
        assert(ret == 88);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = maxSum(nums);
        assert(ret == -1);
    }
    return 0;
}
