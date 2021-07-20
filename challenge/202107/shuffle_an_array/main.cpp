#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
  public:
    Solution(std::vector<int> &nums) : v_(nums), orig_(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        v_ = orig_;
        return v_;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        int len = v_.size();
        for (int i = 0; i < len - 1; ++i) {
            int j = i + rand() % (len - i);
            std::swap(v_[i], v_[j]);
        }

        return v_;
    }

    std::vector<int> v_;
    std::vector<int> orig_;
};

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        Solution s(nums);
        s.shuffle();
        auto ret = s.reset();
        assert(ret == nums);
        s.shuffle();
    }
    return 0;
}
