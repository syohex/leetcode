#include <cassert>
#include <vector>
#include <algorithm>

int maxScore(const std::vector<int> &cardPoints, int k) {
    int sum = 0;
    int lens = cardPoints.size();
    for (int i = 1; i <= k; ++i) {
        sum += cardPoints[lens - i];
    }

    int ret = sum;
    for (int i = 0; i < k; ++i) {
        sum += cardPoints[i] - cardPoints[lens - k + i];
        ret = std::max(ret, sum);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{9, 7, 7, 9, 7, 7, 9};
        assert(maxScore(nums, 7) == 55);
    }
    {
        std::vector<int> nums{1, 1000, 1};
        assert(maxScore(nums, 1) == 1);
    }
    {
        std::vector<int> nums{1, 79, 80, 1, 1, 1, 200, 1};
        assert(maxScore(nums, 3) == 202);
    }
    return 0;
}
