#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

class SparseVector {
  public:
    SparseVector(std::vector<int> &nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                vals_[i] = nums[i];
            }
        }
    }

    int dotProduct(SparseVector &vec) {
        int ret = 0;
        for (const auto &it : vals_) {
            auto it2 = vec.vals_.find(it.first);
            if (it2 != vec.vals_.end()) {
                ret += it.second * it2->second;
            }
        }

        return ret;
    }

    std::map<size_t, int> vals_;
};

class SparseVector2 {
  public:
    SparseVector2(std::vector<int> &nums) : nums_(nums) {
        for (size_t i = 0; i < nums_.size(); ++i) {
            if (nums_[i] != 0) {
                s_.insert(i);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector2 &vec) {
        std::set<size_t> idxs;
        std::set_intersection(s_.begin(), s_.end(), vec.s_.begin(), vec.s_.end(), std::inserter(idxs, idxs.begin()));
        int ret = 0;
        for (size_t idx : idxs) {
            ret += nums_[idx] * vec.nums_[idx];
        }

        return ret;
    }

    std::vector<int> nums_;
    std::set<size_t> s_;
};

int main() {
    {
        std::vector<int> t1{1, 0, 0, 2, 3};
        std::vector<int> t2{0, 3, 0, 4, 0};
        SparseVector v1(t1);
        SparseVector v2(t2);
        assert(v1.dotProduct(v2) == 8);
    }
    {
        std::vector<int> t1{0, 1, 0, 0, 0};
        std::vector<int> t2{0, 0, 0, 0, 2};
        SparseVector v1(t1);
        SparseVector v2(t2);
        assert(v1.dotProduct(v2) == 0);
    }
    {
        std::vector<int> t1{0, 1, 0, 0, 2, 0, 0};
        std::vector<int> t2{1, 0, 0, 0, 3, 0, 4};
        SparseVector v1(t1);
        SparseVector v2(t2);
        assert(v1.dotProduct(v2) == 6);
    }
    return 0;
}
