#include <cassert>
#include <vector>

int removeStones(const std::vector<std::vector<int>> &stones) {
    int len = stones.size();
    std::vector<std::vector<int>> graph(len, std::vector<int>{});

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    std::vector<bool> checked(len, false);
    int cycle_graphs = 0;
    for (int i = 0; i < len; ++i) {
        if (!checked[i]) {
            ++cycle_graphs;

            std::vector<int> q{i};
            while (!q.empty()) {
                int pos = q.back();
                q.pop_back();

                checked[pos] = true;

                for (int next : graph[pos]) {
                    if (!checked[next]) {
                        q.push_back(next);
                    }
                }
            }
        }
    }

    return len - cycle_graphs;
}

int main() {
    {
        std::vector<std::vector<int>> stones{{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
        int ret = removeStones(stones);
        assert(ret == 5);
    }
    {
        std::vector<std::vector<int>> stones{{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
        int ret = removeStones(stones);
        assert(ret == 3);
    }
    {
        std::vector<std::vector<int>> stones{{0, 0}};
        int ret = removeStones(stones);
        assert(ret == 0);
    }
    return 0;
}