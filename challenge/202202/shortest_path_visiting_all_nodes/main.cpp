#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

int shortestPathLength(const std::vector<std::vector<int>> &graph) {
    struct Data {
        int node;
        unsigned int mask;
    };

    int len = graph.size();
    unsigned int goal_mask = (1u << len) - 1;

    std::vector<Data> candidates;
    std::vector<std::set<unsigned int>> checked(len);
    for (int i = 0; i < len; ++i) {
        unsigned int mask = 1u << i;
        candidates.push_back({i, 1u << i});
        checked[i].insert(mask);
    }

    int step = 1;
    while (true) {
        std::vector<Data> next_candidates;
        for (const Data &d : candidates) {
            if (d.mask == goal_mask) {
                return step - 1;
            }

            for (const auto &node : graph[d.node]) {
                unsigned int new_mask = d.mask | (1u << node);
                if (checked[node].find(new_mask) == checked[node].end()) {
                    next_candidates.push_back({node, new_mask});
                    checked[node].insert(new_mask);
                }
            }
        }

        candidates = std::move(next_candidates);
        ++step;
    }

    assert(!"never reach here");
    return -1;
}

int main() {
    {
        std::vector<std::vector<int>> graph{
            {1, 2, 3},
            {0},
            {0},
            {0},
        };
        assert(shortestPathLength(graph) == 4);
    }
    {
        std::vector<std::vector<int>> graph{
            {1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2},
        };
        assert(shortestPathLength(graph) == 4);
    }
    return 0;
}
