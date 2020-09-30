#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

int firstMissingPositive(const std::vector<int> &nums) {
    std::set<int> s;
    for (const auto n : nums) {
        s.insert(n);
    }

    for (int i = 1; i <= static_cast<int>(nums.size()); ++i) {
        if (s.find(i) == s.end()) {
            return i;
        }
    }

    return static_cast<int>(nums.size()) + 1;
}

int main() {
    {
        std::vector<int> input{1, 2, 0};
        assert(firstMissingPositive(input) == 3);
    }
    {
        std::vector<int> input{3, 4, -1, 1};
        assert(firstMissingPositive(input) == 2);
    }
    {
        std::vector<int> input{7, 8, 9, 11, 12};
        assert(firstMissingPositive(input) == 1);
    }
    return 0;
}
