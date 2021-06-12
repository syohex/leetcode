#include <cassert>
#include <vector>
#include <algorithm>

int minRefuelStops(int target, int startFuel, const std::vector<std::vector<int>> &stations) {
    int len = stations.size();
    std::vector<long> dp(len + 1, 0);
    dp[0] = startFuel;

    for (int i = 0; i < len; ++i) {
        for (int j = i; j >= 0; --j) {
            if (dp[j] >= stations[i][0]) {
                dp[j + 1] = std::max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }

    for (int i = 0; i < len + 1; ++i) {
        if (dp[i] >= target) {
            return i;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<std::vector<int>> stations{};
        assert(minRefuelStops(1, 1, stations) == 0);
    }
    {
        std::vector<std::vector<int>> stations{
            {10, 100},
        };
        assert(minRefuelStops(100, 1, stations) == -1);
    }
    {
        std::vector<std::vector<int>> stations{
            {10, 60},
            {20, 30},
            {30, 30},
            {60, 40},
        };
        assert(minRefuelStops(100, 10, stations) == 2);
    }
    return 0;
}