#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

class NumArray {
  public:
    NumArray(std::vector<int> &nums) {
        int limit = static_cast<int>(nums.size());
        if (limit == 1) {
            m_[std::make_pair(0, 0)] = nums[0];
            return;
        }

        std::pair<int, int> p;
        for (int i = 0; i < limit; ++i) {
            int sum = 0;
            for (int j = i; j < limit; ++j) {
                sum += nums[j];
                p.first = i;
                p.second = j;
                m_[p] = sum;
            }
        }
    }

    int sumRange(int i, int j) {
        auto key = std::make_pair(i, j);
        return m_[key];
    }

    std::map<std::pair<int, int>, int> m_;
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
