#include <cassert>
#include <vector>
#include <cstdio>

class NumArray {
  public:
    NumArray(std::vector<int> &nums) {
        sums_.resize(nums.size());
        int limit = static_cast<int>(nums.size());
        int sum = 0;
        for (int i = 0; i < limit; ++i) {
            sum += nums[i];
            sums_[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sums_[j];
        }

        return sums_[j] - sums_[i - 1];
    }

    std::vector<int> sums_;
};

int main() {
    {
        std::vector<int> input{-2, 0, 3, -5, 2, -1};
        NumArray n(input);
        assert(n.sumRange(0, 2) == 1);
        assert(n.sumRange(2, 5) == -1);
        assert(n.sumRange(0, 5) == -3);
        assert(n.sumRange(0, 0) == -2);
    }
    {
        std::vector<int> input{-1};
        NumArray n(input);
        assert(n.sumRange(0, 0) == -1);
    }
    {
        std::vector<int> input{-4, -5};
        NumArray n(input);
        assert(n.sumRange(0, 0) == -4);
        assert(n.sumRange(1, 1) == -5);
        assert(n.sumRange(0, 1) == -9);
        assert(n.sumRange(1, 1) == -5);
        assert(n.sumRange(0, 0) == -4);
    }
    return 0;
}
