#include <cassert>
#include <vector>
#include <queue>

using namespace std;

long long continuousSubarrays(const vector<int> &nums) {
    const auto min_cmp = [&](int a, int b) { return nums[a] > nums[b]; };
    const auto max_cmp = [&](int a, int b) { return nums[a] < nums[b]; };

    priority_queue<int, vector<int>, decltype(min_cmp)> min_q(min_cmp);
    priority_queue<int, vector<int>, decltype(max_cmp)> max_q(max_cmp);

    int len = nums.size();
    int left = 0;
    long long ret = 0;
    for (int right = 0; right < len; ++right) {
        min_q.push(right);
        max_q.push(right);

        while (left < right && nums[max_q.top()] - nums[min_q.top()] > 2) {
            ++left;

            while (!min_q.empty() && min_q.top() < left) {
                min_q.pop();
            }
            while (!max_q.empty() && max_q.top() < left) {
                max_q.pop();
            }
        }

        ret += right - left + 1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{5, 4, 2, 4};
        int ret = continuousSubarrays(nums);
        assert(ret == 8);
    }
    {
        std::vector<int> nums{1, 2, 3};
        int ret = continuousSubarrays(nums);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{65, 66, 67, 66, 66, 65, 64, 65, 65, 64};
        int ret = continuousSubarrays(nums);
        assert(ret == 43);
    }
    {
        std::vector<int> nums{42, 41, 42, 41, 41, 40, 39, 38};
        int ret = continuousSubarrays(nums);
        assert(ret == 28);
    }
    {
        std::vector<int> nums{35, 35, 36, 37, 36, 37, 38, 37, 38};
        int ret = continuousSubarrays(nums);
        assert(ret == 39);
    }
    return 0;
}
