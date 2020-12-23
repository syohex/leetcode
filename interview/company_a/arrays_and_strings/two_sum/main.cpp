#include <cassert>
#include <vector>
#include <map>

std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::vector<int> ret(2);
    std::map<int, std::vector<int>> m;
    for (size_t i = 0; i < nums.size(); ++i) {
        m[nums[i]].push_back(i);
    }

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int v = target - nums[i];
        if (m.find(v) != m.end()) {
            for (auto j : m[v]) {
                if (j != i) {
                    return std::vector<int>{i, j};
                }
            }
        }
    }

    return std::vector<int>{-1, -1};
}

int main() {
    {
        std::vector<int> nums{2, 7, 11, 15};
        auto ret = twoSum(nums, 9);
        assert((ret == std::vector<int>{0, 1}) || (ret == std::vector<int>{1, 0}));
    }
    {
        std::vector<int> nums{3, 2, 4};
        auto ret = twoSum(nums, 6);
        assert((ret == std::vector<int>{1, 2}) || (ret == std::vector<int>{2, 1}));
    }
    {
        std::vector<int> nums{3, 3};
        auto ret = twoSum(nums, 6);
        assert((ret == std::vector<int>{0, 1}) || (ret == std::vector<int>{1, 0}));
    }
    return 0;
}
