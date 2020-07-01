#include <cassert>
#include <vector>
#include <map>

std::vector<int> intersect(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::map<int, int> a, b;
    for (const auto i : nums1) {
        ++a[i];
    }
    for (const auto i : nums2) {
        ++b[i];
    }

    std::vector<int> ret;
    for (const auto &it : a) {
        if (b.find(it.first) != b.end()) {
            int limit = it.second > b[it.first] ? b[it.first] : it.second;
            for (int i = 0; i < limit; ++i) {
                ret.push_back(it.first);
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> input1{1, 2, 2, 1};
        std::vector<int> input2{2, 2};
        auto ret = intersect(input1, input2);
        assert((ret == std::vector<int>{2, 2}));
    }
    {
        std::vector<int> input1{4, 9, 5};
        std::vector<int> input2{9, 4, 9, 8, 4};
        auto ret = intersect(input1, input2);
        assert((ret == std::vector<int>{4, 9}));
    }
    return 0;
}
