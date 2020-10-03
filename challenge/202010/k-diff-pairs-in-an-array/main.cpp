#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

int findPairs(const std::vector<int> &nums, int k) {
    std::map<int, std::vector<int>> m;
    int i = 0;
    for (const auto num : nums) {
        m[num].push_back(i);
        ++i;
    }

    int ret = 0;
    for (const auto &it : m) {
        int key = it.first + k;
        if (m.find(key) == m.end()) {
            continue;
        }

        if (k == 0 && m[key].size() == 1) {
            continue;
        }

        ++ret;
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{3, 1, 4, 1, 5};
        int k = 2;
        assert(findPairs(input, k) == 2);
    }
    {
        std::vector<int> input{1, 2, 3, 4, 5};
        int k = 1;
        assert(findPairs(input, k) == 4);
    }
    {
        std::vector<int> input{1, 3, 1, 5, 4};
        int k = 0;
        assert(findPairs(input, k) == 1);
    }
    {
        std::vector<int> input{1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
        int k = 3;
        assert(findPairs(input, k) == 2);
    }
    {
        std::vector<int> input{-1, -2, -3};
        int k = 1;
        assert(findPairs(input, k) == 2);
    }
    return 0;
}
