#include <cassert>
#include <vector>
#include <queue>
#include <cstdio>

class KthLargest {
  public:
    KthLargest(int k, const std::vector<int> &nums) : k_(k) {
        for (int num : nums) {
            q_.push(num);
        }
    }

    int add(int val) {
        q_.push(val);

        std::vector<int> tmp;
        int ret = -1;
        for (int i = 0; i < k_; ++i) {
            ret = q_.top();
            q_.pop();
            tmp.push_back(ret);
        }

        for (int v : tmp) {
            q_.push(v);
        }

        return ret;
    }

    int k_;
    std::priority_queue<int, std::vector<int>> q_;
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
