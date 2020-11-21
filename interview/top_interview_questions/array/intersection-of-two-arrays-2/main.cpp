#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> intersect(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::map<int, int> m1, m2;
    for (const auto i : nums1) {
        ++m1[i];
    }
    for (const auto i : nums2) {
        ++m2[i];
    }

    std::map<int, int> m;
    for (const auto &it : m1) {
        if (m2.find(it.first) != m2.end()) {
            m[it.first] = std::min(it.second, m2[it.first]);
        }
    }

    std::vector<int> ret;
    for (const auto &it : m) {
        for (int i = 0; i < it.second; ++i) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> num1{1, 2, 2, 1};
        std::vector<int> num2{2, 2};
        auto ret = intersect(num1, num2);
        assert((ret == std::vector<int>{2, 2}));
    }
    {
        std::vector<int> num1{4, 9, 5};
        std::vector<int> num2{9, 4, 9, 8, 4};
        auto ret = intersect(num1, num2);
        assert((ret == std::vector<int>{4, 9}));
    }
    {
        std::vector<int> num1{};
        std::vector<int> num2{9, 4, 9, 8, 4};
        auto ret = intersect(num1, num2);
        assert(ret.empty());
    }
    return 0;
}
