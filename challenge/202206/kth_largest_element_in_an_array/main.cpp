#include <cassert>
#include <queue>
#include <vector>

int findKthLargest(const std::vector<int> &nums, int k) {
    std::priority_queue<int> q;
    for (int num : nums) {
        q.push(num);
    }

    int ret = -1;
    for (int i = 0; i < k; ++i) {
        ret = q.top();
        q.pop();
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 2, 1, 5, 6, 4};
        int ret = findKthLargest(nums, 2);
        assert(ret == 5);
    }
    {
        std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
        int ret = findKthLargest(nums, 4);
        assert(ret == 4);
    }
    return 0;
}
