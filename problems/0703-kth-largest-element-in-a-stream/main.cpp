#include <cassert>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

class KthLargest {
  public:
    KthLargest(int k, std::vector<int> &nums) {
        k_ = k;
        if (nums.empty()) {
            return;
        }

        std::sort(nums.begin(), nums.end(), std::greater<int>());

        size_t limit = std::min(static_cast<size_t>(k), nums.size());
        for (size_t i = 0; i < limit; ++i) {
            list_.push_back(nums[i]);
        }
    }

    int add(int val) {
        if (list_.empty()) {
            list_.push_back(val);
            return val;
        }

        if (list_.size() >= static_cast<size_t>(k_) && list_.back() >= val) {
            return list_.back();
        }

        bool found = false;
        for (auto it = list_.begin(); it != list_.end(); ++it) {
            if (val >= *it) {
                found = true;
                list_.insert(it, val);
                if (list_.size() > static_cast<size_t>(k_)) {
                    list_.pop_back();
                }
                break;
            }
        }

        if (!found && list_.size() < static_cast<size_t>(k_)) {
            list_.push_back(val);
        }

        return list_.back();
    }

    std::list<int> list_;
    int k_;
};

int main() {
    {
        std::vector<int> input{4, 5, 8, 2};
        auto kth = KthLargest(3, input);
        assert(kth.add(3) == 4);
        assert(kth.add(5) == 5);
        assert(kth.add(10) == 5);
        assert(kth.add(9) == 8);
        assert(kth.add(4) == 8);
    }
    {
        std::vector<int> input{};
        auto kth = KthLargest(1, input);
        assert(kth.add(-3) == -3);
        assert(kth.add(-4) == -3);
        assert(kth.add(0) == 0);
        assert(kth.add(4) == 4);
    }
    {
        std::vector<int> input{0};
        auto kth = KthLargest(2, input);
        assert(kth.add(-1) == -1);
        assert(kth.add(1) == 0);
        assert(kth.add(-2) == 0);
        assert(kth.add(-4) == 0);
        assert(kth.add(3) == 1);
    }
    {
        std::vector<int> input{5, -1};
        auto kth = KthLargest(3, input);
        assert(kth.add(2) == -1);
        assert(kth.add(1) == 1);
        assert(kth.add(-1) == 1);
        assert(kth.add(3) == 2);
        assert(kth.add(4) == 3);
    }
    return 0;
}
