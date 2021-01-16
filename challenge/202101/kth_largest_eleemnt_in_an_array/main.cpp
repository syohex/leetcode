#include <cassert>
#include <vector>
#include <queue>

int findKthLargest(const std::vector<int> &nums, int k) {
    std::priority_queue<int> q;
    for (int num : nums) {
        q.push(num);
    }

    for (int i = 0; i < k - 1; ++i) {
        q.pop();
    }
    return q.top();
}

int main() {
    assert((findKthLargest(std::vector<int>{3, 2, 1, 5, 6, 4}, 2)));
    assert((findKthLargest(std::vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4)));
    return 0;
}
