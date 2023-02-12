#include <cassert>
#include <vector>
#include <functional>
#include <cmath>

long long minimumFuelCost(const std::vector<std::vector<int>> &roads, int seats) {
    std::function<long long(int node, int parent, const std::vector<std::vector<int>> &graph, long long &fuel)> f;
    f = [&](int node, int parent, const std::vector<std::vector<int>> &graph, long long &fuel) -> long long {
        long long representatives = 1;
        for (const auto &next : graph[node]) {
            if (next == parent) {
                continue;
            }

            representatives += f(next, node, graph, fuel);
        }

        if (node != 0) {
            fuel += std::ceil(representatives / static_cast<double>(seats));
        }

        return representatives;
    };

    int len = roads.size() + 1;
    std::vector<std::vector<int>> graph(len);
    for (const auto &road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    long long fuel = 0;
    (void)f(0, -1, graph, fuel);
    return fuel;
}

int main() {
    {
        std::vector<std::vector<int>> roads{{0, 1}, {0, 2}, {0, 3}};
        auto ret = minimumFuelCost(roads, 5);
        assert(ret == 3);
    }
    {
        std::vector<std::vector<int>> roads{{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
        auto ret = minimumFuelCost(roads, 2);
        assert(ret == 7);
    }
    {
        std::vector<std::vector<int>> roads;
        auto ret = minimumFuelCost(roads, 1);
        assert(ret == 0);
    }
    return 0;
}
