#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

int findLHS(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (int n : nums) {
        ++m[n];
    }

    int ret = 0;
    for (const auto &it : m) {
        if (m.find(it.first + 1) != m.end()) {
            ret = std::max(ret, it.second + m[it.first + 1]);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 3, 2, 2, 5, 2, 3, 7};
        assert(findLHS(input) == 5);
    }
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(findLHS(input) == 2);
    }
    {
        std::vector<int> input{1, 1, 1, 1};
        assert(findLHS(input) == 0);
    }
    {
        std::vector<int> input{1, 2, 2, 1};
        assert(findLHS(input) == 4);
    }
    {
        std::vector<int> input{-3, -1, -1, -1, -3, -2};
        assert(findLHS(input) == 4);
    }
    {
        std::vector<int> input{2, 2, 2, 2, 2, 2, 2, 3, 1, 0, 0, 0, 3, 1, -1, 0, 1, 1, 0, 0, 1, 1, 2, 2, 2, 0, 1, 2, 2, 3, 2};
        assert(findLHS(input) == 20);
    }
    return 0;
}
