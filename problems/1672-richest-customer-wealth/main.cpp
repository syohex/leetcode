#include <cassert>
#include <vector>
#include <algorithm>

int maximumWealth(const std::vector<std::vector<int>> &accounts) {
    int ret = 0;
    for (const auto &account : accounts) {
        int sum = 0;
        for (const int n : account) {
            sum += n;
        }

        ret = std::max(ret, sum);
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> accounts{
            {1, 2, 3},
            {3, 2, 1},

        };
        assert(maximumWealth(accounts) == 6);
    }
    {
        std::vector<std::vector<int>> accounts{
            {1, 5},
            {7, 3},
            {3, 5},

        };
        assert(maximumWealth(accounts) == 10);
    }
    {
        std::vector<std::vector<int>> accounts{
            {2, 8, 7},
            {7, 1, 3},
            {1, 9, 5},

        };
        assert(maximumWealth(accounts) == 17);
    }
    return 0;
}
