#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

std::vector<int> maxSubsequence(const std::vector<int> &nums, int k) {
    int last = nums.size() - 1;
    auto data = nums;
    std::sort(data.begin(), data.end());
    std::map<int, int> m;

    for (int i = 0; i < k; ++i) {
        int n = data[last - i];
        ++m[n];
    }

    std::vector<int> ret;
    for (int n : nums) {
        if (m.find(n) != m.end() && m[n] > 0) {
            ret.push_back(n);
            if (ret.size() == static_cast<size_t>(k)) {
                break;
            }
            --m[n];
        }
    }

    return ret;
}

void check(const std::vector<int> &got, const std::vector<int> &expected) {
    assert(got.size() == expected.size());

    std::set<int> gs(got.begin(), got.end());
    std::set<int> es(expected.begin(), expected.end());
    assert(gs == es);
}

int main() {
    {
        std::vector<int> nums{2, 1, 3, 3};
        std::vector<int> expected{3, 3};
        auto ret = maxSubsequence(nums, 2);
        check(ret, expected);
    }
    {
        std::vector<int> nums{-1, -2, 3, 4};
        std::vector<int> expected{-1, 3, 4};
        auto ret = maxSubsequence(nums, 3);
        check(ret, expected);
    }
    {
        std::vector<int> nums{3, 4, 3, 3};
        std::vector<int> expected{3, 4};
        auto ret = maxSubsequence(nums, 2);
        check(ret, expected);
    }
    return 0;
}
