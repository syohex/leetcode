#include <cassert>
#include <vector>

class NumArray {
  public:
    NumArray(const std::vector<int> &nums) : tree_(nums.size() * 2, 0), len_(nums.size()) {
        int limit = len_ * 2;
        for (int i = len_; i < limit; ++i) {
            tree_[i] = nums[i - len_];
        }

        for (int i = len_ - 1; i >= 0; --i) {
            tree_[i] = tree_[2 * i] + tree_[2 * i + 1];
        }
    }

    void update(int index, int val) {
        index += len_;
        tree_[index] = val;

        while (index > 0) {
            int left = index;
            int right = index;
            if (index % 2 == 0) {
                right += 1;
            } else {
                left -= 1;
            }

            int parent = index / 2;
            tree_[parent] = tree_[left] + tree_[right];
            index = parent;
        }
    }

    int sumRange(int left, int right) {
        left += len_;
        right += len_;

        int ret = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                ret += tree_[left];
                left += 1;
            }
            if (right % 2 == 0) {
                ret += tree_[right];
                right -= 1;
            }

            left /= 2;
            right /= 2;
        }

        return ret;
    }

    std::vector<int> tree_;
    int len_;
};

int main() {
    {
        NumArray na(std::vector<int>{1, 3, 5});
        assert(na.sumRange(0, 2) == 9);
        na.update(1, 2);
        assert(na.sumRange(0, 2) == 8);
    }
    {
        NumArray na(std::vector<int>{7, 2, 7, 2, 0});
        na.update(4, 6);
        na.update(0, 2);
        na.update(0, 9);
        assert(na.sumRange(4, 4) == 6);
        na.update(3, 8);
        assert(na.sumRange(0, 4) == 32);
        na.update(4, 1);
        assert(na.sumRange(0, 3) == 26);
        assert(na.sumRange(0, 4) == 27);
    }
    return 0;
}
