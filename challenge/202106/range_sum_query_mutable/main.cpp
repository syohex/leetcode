#include <cassert>
#include <vector>

class NumArray {
  public:
    NumArray(std::vector<int> &nums) : nums_(nums) {
        acc_.resize(nums_.size() + 1);
        acc_[0] = 0;

        for (size_t i = 1; i <= nums_.size(); ++i) {
            acc_[i] = acc_[i - 1] + nums[i - 1];
        }
    }

    void update(int index, int val) {
        int diff = val - nums_[index];
        for (size_t i = index + 1; i < acc_.size(); ++i) {
            acc_[i] += diff;
        }
        nums_[index] = val;
    }

    int sumRange(int left, int right) {
        return acc_[right + 1] - acc_[left];
    }

    std::vector<int> nums_;
    std::vector<int> acc_;
};

int main() {
    {
        std::vector<int> nums{1, 3, 5};
        NumArray n(nums);
        assert(n.sumRange(0, 2) == 9);
        n.update(1, 2);
        assert(n.sumRange(0, 2) == 8);
    }
    {
        std::vector<int> nums{-1};
        NumArray n(nums);
        assert(n.sumRange(0, 0) == -1);
        n.update(0, 1);
        assert(n.sumRange(0, 0) == 1);
    }
    {
        std::vector<int> nums{7, 2, 7, 2, 0};
        NumArray n(nums);
        n.update(4, 6);
        n.update(0, 2);
        n.update(0, 9);
        assert(n.sumRange(4, 4) == 6);
        n.update(3, 8);
        assert(n.sumRange(0, 4) == 32);
        n.update(4, 1);
        assert(n.sumRange(0, 3) == 26);
        assert(n.sumRange(0, 4) == 27);
        n.update(0, 4);
    }
    return 0;
}
