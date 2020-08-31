#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

int dominantIndex(const std::vector<int> &nums) {
    if (nums.size() <= 1) {
        return 0;
    }

    std::map<int, size_t> m;
    for (size_t i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }

    auto it = m.rbegin();
    int largest = it->first;
    size_t largestIndex = it->second;
    ++it;
    int second = it->first;

    return largest >= 2 * second ? static_cast<int>(largestIndex) : -1;
}

int main() {
    {
        std::vector<int> input{3, 6, 1, 0};
        assert(dominantIndex(input) == 1);
    }
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(dominantIndex(input) == -1);
    }
    return 0;
}
