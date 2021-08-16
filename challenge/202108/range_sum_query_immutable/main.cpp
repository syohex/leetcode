#include <cassert>
#include <vector>

class NumArray {
  public:
    NumArray(std::vector<int> &nums) {
        int sum = 0;
        acc_.push_back(0);
        for (int num : nums) {
            sum += num;
            acc_.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        return acc_[right + 1] - acc_[left];
    }

    std::vector<int> acc_;
};

int main() {
    {
        std::vector<int> nums{-2, 0, 3, -5, 2, -1};
        NumArray n(nums);
        assert(n.sumRange(0, 2) == 1);
        assert(n.sumRange(2, 5) == -1);
        assert(n.sumRange(0, 5) == -3);
    }
    return 0;
}
