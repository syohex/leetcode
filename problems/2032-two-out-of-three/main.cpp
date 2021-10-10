#include <cassert>
#include <vector>
#include <set>

std::vector<int> twoOutOfThree(const std::vector<int> &nums1, const std::vector<int> &nums2, const std::vector<int> &nums3) {
    std::set<int> all;
    std::vector<std::set<int>> ss(3);

    for (int n : nums1) {
        all.insert(n);
        ss[0].insert(n);
    }
    for (int n : nums2) {
        all.insert(n);
        ss[1].insert(n);
    }
    for (int n : nums3) {
        all.insert(n);
        ss[2].insert(n);
    }

    std::vector<int> ret;
    for (int n : all) {
        int count = 0;
        for (const auto &s : ss) {
            if (s.find(n) != s.end()) {
                ++count;
            }
        }
        if (count >= 2) {
            ret.push_back(n);
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
        std::vector<int> nums1{1, 1, 3, 2};
        std::vector<int> nums2{
            2,
            3,
        };
        std::vector<int> nums3{3};
        std::vector<int> expected{3, 2};
        auto ret = twoOutOfThree(nums1, nums2, nums3);
        check(ret, expected);
    }
    {
        std::vector<int> nums1{3, 1};
        std::vector<int> nums2{2, 3};
        std::vector<int> nums3{1, 2};
        std::vector<int> expected{2, 3, 1};
        auto ret = twoOutOfThree(nums1, nums2, nums3);
        check(ret, expected);
    }
    {
        std::vector<int> nums1{1, 2, 2};
        std::vector<int> nums2{4, 3, 3};
        std::vector<int> nums3{5};
        std::vector<int> expected{};
        auto ret = twoOutOfThree(nums1, nums2, nums3);
        check(ret, expected);
    }
    return 0;
}