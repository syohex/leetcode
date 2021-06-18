#include <cassert>
#include <vector>

class NumArray {
  public:
    NumArray(std::vector<int> &nums) {
        size_ = nums.size();
        tree_.resize(size_ * 2);

        build_segment_tree(nums);
    }

    void build_segment_tree(const std::vector<int> &nums) {
        for (int i = size_, j = 0; i < 2 * size_; ++i, ++j) {
            tree_[i] = nums[j];
        }

        for (int i = size_ - 1; i > 0; --i) {
            tree_[i] = tree_[i * 2] + tree_[i * 2 + 1];
        }
    }

    void update(int index, int val) {
        int tree_index = index + size_;
        tree_[tree_index] = val;

        while (tree_index > 0) {
            int left = tree_index;
            int right = tree_index;

            if (tree_index % 2 == 0) {
                right = tree_index + 1;
            } else {
                left = tree_index - 1;
            }

            int parent_index = tree_index / 2;
            tree_[parent_index] = tree_[left] + tree_[right];
            tree_index = parent_index;
        }
    }

    int sumRange(int left, int right) {
        int left_index = left + size_;
        int right_index = right + size_;

        int ret = 0;
        while (left_index <= right_index) {
            if (left_index % 2 == 1) {
                ret += tree_[left_index];
                ++left_index;
            }
            if (right_index % 2 == 0) {
                ret += tree_[right_index];
                --right_index;
            }

            left_index /= 2;
            right_index /= 2;
        }

        return ret;
    }

    std::vector<int> tree_;
    int size_;
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
