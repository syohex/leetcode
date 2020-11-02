#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> frequencySort(std::vector<int> &nums) {
    struct Element {
        int num = 0;
        int count = 0;
    };

    std::vector<Element> v;
    for (const auto i : nums) {
        bool found = false;
        for (auto &e : v) {
            if (e.num == i) {
                ++e.count;
                found = true;
                break;
            }
        }

        if (!found) {
            v.emplace_back(Element{i, 1});
        }
    }

    std::sort(v.begin(), v.end(), [](const Element &a, const Element &b) {
        if (a.count != b.count) {
            return a.count < b.count;
        }

        return a.num > b.num;
    });

    size_t i = 0;
    for (const auto &e : v) {
        for (size_t j = 0; j < e.count; ++j) {
            nums[i++] = e.num;
        }
    }

    return nums;
}

int main() {
    {
        std::vector<int> nums{1, 1, 2, 2, 2, 3};
        auto ret = frequencySort(nums);
        assert((ret == std::vector<int>{3, 1, 1, 2, 2, 2}));
    }
    {
        std::vector<int> nums{2, 3, 1, 3, 2};
        auto ret = frequencySort(nums);
        assert((ret == std::vector<int>{1, 3, 3, 2, 2}));
    }
    {
        std::vector<int> nums{-1, 1, -6, 4, 5, -6, 1, 4, 1};
        auto ret = frequencySort(nums);
        assert((ret == std::vector<int>{5, -1, 4, 4, -6, -6, 1, 1, 1}));
    }
    return 0;
}
