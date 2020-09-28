#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

int findMaxLength(const std::vector<int> &nums) {
    std::map<int, int> m{{0, -1}};
    int max = 0;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        sum = sum + (nums[i] == 1 ? 1 : -1);
        if (m.find(sum) != m.end()) {
            max = std::max(max, static_cast<int>(i) - m[sum]);
        } else {
            m[sum] = i;
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> input{0, 1};
        assert(findMaxLength(input) == 2);
    }
    {
        std::vector<int> input{0, 1, 0};
        assert(findMaxLength(input) == 2);
    }
    return 0;
}
