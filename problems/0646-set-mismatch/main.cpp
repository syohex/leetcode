#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

std::vector<int> findErrorNums(const std::vector<int> &nums) {
    std::set<int> s;
    for (int i = 1; i <= static_cast<int>(nums.size()); ++i) {
        s.insert(i);
    }

    std::set<int> ss;
    int dup = -1;
    for (const int n : nums) {
        if (ss.find(n) != ss.end()) {
            dup = n;
            continue;
        }

        if (s.find(n) != s.end()) {
            s.erase(n);
        }
        ss.insert(n);
    }

    return std::vector<int>{dup, *(s.begin())};
}

int main() {
    {
        std::vector<int> input{1, 2, 2, 4};
        auto ret = findErrorNums(input);
        assert((ret == std::vector<int>{2, 3}));
    }
    return 0;
}
