#include <cassert>
#include <vector>
#include <climits>
#include <cstdio>

double findMaxAverage(const std::vector<int> &nums, int k) {
    int size = static_cast<int>(nums.size());
    double sum = 0;
    if (size <= k) {
        for (auto n : nums) {
            sum += n;
        }

        return static_cast<double>(sum) / size;
    }

    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }

    double divisor = static_cast<double>(k);
    double max = sum / divisor;
    for (int i = k; i < size; ++i) {
        sum = sum - nums[i - k] + nums[i];
        double tmp = sum / divisor;
        if (max < tmp) {
            max = tmp;
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> input{1, 12, -5, -6, 50, 3};
        auto ret = findMaxAverage(input, 4);
        assert(ret == 12.75);
    }
    return 0;
}
