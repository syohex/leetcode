#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

std::vector<int> intersect(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::map<int, int> a, b;
    for (int n : nums1) {
        ++a[n];
    }

    for (int n : nums2) {
        ++b[n];
    }

    std::map<int, int> diff;
    for (auto &it : a) {
        if (b.find(it.first) != b.end()) {
            diff[it.first] = std::min(a[it.first], b[it.first]);
        }
    }

    std::vector<int> ret;
    for (auto &it : diff) {
        for (int i = 0; i < it.second; ++i) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

void check(const std::vector<int> &got, const std::vector<int> &expected) {
    assert(got.size() == expected.size());

    std::set<int> a(got.begin(), got.end());
    std::set<int> b(expected.begin(), expected.end());
    assert(a == b);
}

int main() {
    {
        std::vector<int> num1{1, 2, 2, 1};
        std::vector<int> num2{2, 2};
        std::vector<int> expected{2, 2};
        auto ret = intersect(num1, num2);
        check(ret, expected);
    }
    {
        std::vector<int> num1{4, 9, 5};
        std::vector<int> num2{9, 4, 9, 8, 4};
        std::vector<int> expected{4, 9};
        auto ret = intersect(num1, num2);
        check(ret, expected);
    }
    return 0;
}