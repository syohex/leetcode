#include <cassert>
#include <vector>
#include <queue>
#include <cstdio>

class KthLargest {
  public:
    KthLargest(int k, const std::vector<int> &nums) : k_(k) {
        for (int num : nums) {
            (void)add(num);
        }
    }

    int add(int val) {
        if (q_.size() < k_) {
            q_.push(val);
            return q_.top();
        }

        if (q_.top() > val) {
            return q_.top();
        }

        q_.pop();
        q_.push(val);

        return q_.top();
    }

    std::size_t k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q_;
};

int main() {
    {
        std::vector<int> nums{4, 5, 8, 2};
        KthLargest k(3, nums);
        assert(k.add(3) == 4);
        assert(k.add(5) == 5);
        assert(k.add(10) == 5);
        assert(k.add(9) == 8);
        assert(k.add(4) == 8);
    }
    return 0;
}
