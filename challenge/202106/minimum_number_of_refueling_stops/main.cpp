#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>

int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>> &stations) {
    stations.push_back({target, 0});

    int ret = INT_MAX;
    std::function<void(size_t pos, int fuel, int count)> f;
    f = [&f, &stations, &ret](size_t pos, int fuel, int count) {
        if (count >= ret) {
            return;
        }
        if (pos == 0) {
            fuel -= stations[pos][0];
        } else {
            fuel -= stations[pos][0] - stations[pos - 1][0];
        }
        if (fuel < 0) {
            return;
        }

        if (pos == stations.size() - 1) {
            if (fuel >= 0) {
                ret = std::min(ret, count);
            }
            return;
        }

        f(pos + 1, fuel, count);
        f(pos + 1, fuel + stations[pos][1], count + 1);
    };

    f(0, startFuel, 0);
    return ret == INT_MAX ? -1 : ret;
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