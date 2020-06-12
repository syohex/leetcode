#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> intersection(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::vector<int> ret;
    for (const auto i : nums1) {
        for (const auto j : nums2) {
            if (i == j) {
                if (std::find(ret.begin(), ret.end(), i) == ret.end()) {
                    ret.push_back(i);
                }
                break;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> num1{1, 2, 2, 1};
        std::vector<int> num2{2, 2};
        assert((intersection(num1, num2) == std::vector<int>{2}));
    }
    {
        std::vector<int> num1{4, 9, 5};
        std::vector<int> num2{9, 4, 9, 8, 4};
        assert((intersection(num1, num2) == std::vector<int>{4, 9}));
    }
    return 0;
}
