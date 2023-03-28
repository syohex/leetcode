#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>

int mincostTickets(const std::vector<int> &days, const std::vector<int> &costs) {
    std::set<int> travel_days;
    for (int day : days) {
        travel_days.insert(day);
    }

    std::map<int, int> cache;
    std::function<int(int day)> f;
    f = [&](int day) -> int {
        if (day > 365) {
            return 0;
        }

        if (cache.find(day) != cache.end()) {
            return cache[day];
        }

        int ret;
        if (travel_days.find(day) != travel_days.end()) {
            ret = std::min(f(day + 1) + costs[0], f(day + 7) + costs[1]);
            ret = std::min(ret, f(day + 30) + costs[2]);
        } else {
            ret = f(day + 1);
        }

        cache[day] = ret;
        return ret;
    };

    return f(1);
}

int main() {
    {
        std::vector<int> days{1, 4, 6, 7, 8, 20};
        std::vector<int> costs{2, 7, 15};
        int ret = mincostTickets(days, costs);
        assert(ret == 11);
    }
    {
        std::vector<int> days{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
        std::vector<int> costs{2, 7, 15};
        int ret = mincostTickets(days, costs);
        assert(ret == 17);
    }
    return 0;
}
