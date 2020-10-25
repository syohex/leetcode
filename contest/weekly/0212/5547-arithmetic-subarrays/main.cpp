#include <cassert>
#include <vector>
#include <cstdio>
#include <algorithm>

std::vector<bool> checkArithmeticSubarrays(const std::vector<int> &nums, const std::vector<int> &l, const std::vector<int> &r) {
    if (l.empty()) {
        return std::vector<bool>{};
    }

    std::vector<bool> ret;
    for (size_t i = 0; i < l.size(); ++i) {
        auto v = std::vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
        if (v.size() == 2) {
            ret.push_back(true);
        } else if (v.size() <= 1) {
            ret.push_back(false);
        } else {
            std::sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            int ok = true;
            for (size_t i = 2; i < v.size(); ++i) {
                if (v[i] - v[i - 1] != diff) {
                    ok = false;
                    ret.push_back(false);
                    break;
                }
            }

            if (ok) {
                ret.push_back(true);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 6, 5, 9, 3, 7};
        std::vector<int> l{0, 0, 2};
        std::vector<int> r{2, 3, 5};
        auto ret = checkArithmeticSubarrays(nums, l, r);
        assert((ret == std::vector<bool>{true, false, true}));
    }
    {
        std::vector<int> nums{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
        std::vector<int> l{0, 1, 6, 4, 8, 7};
        std::vector<int> r{4, 4, 9, 7, 9, 10};
        auto ret = checkArithmeticSubarrays(nums, l, r);
        assert((ret == std::vector<bool>{false, true, false, false, true, true}));
    }
    return 0;
}
