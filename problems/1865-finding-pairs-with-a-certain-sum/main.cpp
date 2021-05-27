#include <cassert>
#include <vector>
#include <map>

class FindSumPairs {
  public:
    FindSumPairs(std::vector<int> &nums1, std::vector<int> &nums2) : v1_(nums1), v2_(nums2) {
        for (int n : nums2) {
            ++m_[n];
        }
    }

    void add(int index, int val) {
        --m_[v2_[index]];
        v2_[index] += val;
        ++m_[v2_[index]];
    }

    int count(int tot) {
        int ret = 0;
        for (int n1 : v1_) {
            int target = tot - n1;
            ret += m_[target];
        }

        return ret;
    }

    std::vector<int> v1_;
    std::vector<int> v2_;
    std::map<int, int> m_;
};

int main() {
    {
        std::vector<int> num1{1, 1, 2, 2, 2, 3};
        std::vector<int> num2{1, 4, 5, 2, 5, 4};

        FindSumPairs f(num1, num2);
        assert(f.count(7) == 8);
        f.add(3, 2);
        assert(f.count(8) == 2);
        assert(f.count(4) == 1);
        f.add(0, 1);
        f.add(1, 1);
        assert(f.count(7) == 11);
    }
    return 0;
}
