#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>

int minimumDeviation(const std::vector<int> &nums) {
    std::priority_queue<int> q;
    int min = 1'000'000'000;
    for (int num : nums) {
        if (num % 2 == 0) {
            q.push(num);
            min = std::min(min, num);
        } else {
            q.push(num * 2);
            min = std::min(min, num * 2);
        }
    }

    int ret = 1'000'000'000;
    while (!q.empty()) {
        int num = q.top();
        q.pop();

        ret = std::min(ret, num - min);
        if (num % 2 == 1) {
            break;
        }

        q.push(num / 2);
        min = std::min(min, num / 2);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = minimumDeviation(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{4, 1, 5, 20, 3};
        int ret = minimumDeviation(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{2, 10, 8};
        int ret = minimumDeviation(nums);
        assert(ret == 3);
    }
    return 0;
}
