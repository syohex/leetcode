#include <cassert>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

int minCost(const std::vector<int> &houses, const std::vector<std::vector<int>> &cost, int m, int n, int target) {
    constexpr int MAX_COST = 1'000'001;

    int cache[100][100][21];
    std::memset(cache, -1, sizeof(cache));

    std::function<int(int pos, int count, int prev)> f;
    f = [&](int pos, int count, int prev) -> int {
        if (pos >= m) {
            return count == target ? 0 : MAX_COST;
        }

        if (count > target) {
            return MAX_COST;
        }

        if (cache[pos][count][prev] != -1) {
            return cache[pos][count][prev];
        }

        int ret = MAX_COST;
        if (houses[pos] != 0) {
            int new_count = count;
            if (houses[pos] != prev) {
                ++new_count;
            }

            ret = f(pos + 1, new_count, houses[pos]);
        } else {
            for (int i = 1; i <= n; ++i) {
                int new_count = count;
                if (i != prev) {
                    ++new_count;
                }

                int new_cost = cost[pos][i - 1] + f(pos + 1, new_count, i);
                ret = std::min(ret, new_cost);
            }
        }

        cache[pos][count][prev] = ret;
        return ret;
    };

    int ret = f(0, 0, 0);
    return ret == MAX_COST ? -1 : ret;
}

int main() {
    {
        std::vector<int> houses{0, 0, 0, 0, 0};
        std::vector<std::vector<int>> cost{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
        int m = 5;
        int n = 2;
        int target = 3;
        int ret = minCost(houses, cost, m, n, target);
        assert(ret == 9);
    }
    {
        std::vector<int> houses{0, 2, 1, 2, 0};
        std::vector<std::vector<int>> cost{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
        int m = 5;
        int n = 2;
        int target = 3;
        int ret = minCost(houses, cost, m, n, target);
        assert(ret == 11);
    }
    {
        std::vector<int> houses{3, 1, 2, 3};
        std::vector<std::vector<int>> cost{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
        int m = 4;
        int n = 3;
        int target = 3;
        int ret = minCost(houses, cost, m, n, target);
        assert(ret == -1);
    }
    return 0;
}
