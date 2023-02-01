#include <cassert>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstdio>

int findCheapestPrice(int n, const std::vector<std::vector<int>> &flights, int src, int dst, int k) {
    std::map<int, std::vector<std::pair<int, int>>> graph;
    for (const auto &flight : flights) {
        graph[flight[0]].push_back({flight[1], flight[2]});
    }

    struct Data {
        int city;
        int costs;
    };

    std::deque<Data> q;
    q.push_back({src, 0});

    std::vector<int> min_costs(n, std::numeric_limits<int>::max());
    int ret = std::numeric_limits<int>::max();
    bool found = false;
    for (int stop = -1; stop <= k; ++stop) {
        if (q.empty()) {
            break;
        }

        size_t len = q.size();
        for (size_t i = 0; i < len; ++i) {
            auto d = q.front();
            q.pop_front();

            if (d.costs >= min_costs[d.city]) {
                continue;
            }
            min_costs[d.city] = d.costs;

            if (d.city == dst) {
                found = true;
                ret = std::min(ret, d.costs);
                continue;
            }

            for (const auto &[next_city, cost] : graph[d.city]) {
                q.push_back({next_city, d.costs + cost});
            }
        }
    }

    if (!found) {
        return -1;
    }

    return ret;
}

int main() {
    {
        int n = 4;
        std::vector<std::vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
        int src = 0;
        int dst = 3;
        int k = 1;
        int ret = findCheapestPrice(n, flights, src, dst, k);
        assert(ret == 700);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
        int src = 0;
        int dst = 2;
        int k = 1;
        int ret = findCheapestPrice(n, flights, src, dst, k);
        assert(ret == 200);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
        int src = 0;
        int dst = 2;
        int k = 0;
        int ret = findCheapestPrice(n, flights, src, dst, k);
        assert(ret == 500);
    }
    return 0;
}
