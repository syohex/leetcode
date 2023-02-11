#include <cassert>
#include <vector>
#include <queue>
#include <cstdio>

std::vector<int> shortestAlternatingPaths(int n, const std::vector<std::vector<int>> &redEdges,
                                          const std::vector<std::vector<int>> &blueEdges) {

    std::vector<std::vector<int>> redGraph(n);
    std::vector<std::vector<int>> blueGraph(n);
    std::queue<std::pair<int, bool>> q;

    for (const auto &edge : redEdges) {
        redGraph[edge[0]].push_back(edge[1]);
        if (edge[0] == 0) {
            q.push({0, false});
        }
    }

    for (const auto &edge : blueEdges) {
        blueGraph[edge[0]].push_back(edge[1]);
        if (edge[0] == 0) {
            q.push({0, true});
        }
    }

    std::vector<int> ret(n, -1);
    ret[0] = 0;

    std::vector<std::pair<bool, bool>> visited(n, {false, false});
    int distance = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto [node, is_red] = q.front();
            q.pop();

            if (ret[node] == -1) {
                ret[node] = distance;
            }

            if (is_red) {
                for (const auto &next : blueGraph[node]) {
                    if (!visited[next].second) {
                        visited[next].second = true;
                        q.push({next, false});
                    }
                }
            } else {
                for (const auto &next : redGraph[node]) {
                    if (!visited[next].first) {
                        visited[next].first = true;
                        q.push({next, true});
                    }
                }
            }
        }

        distance += 1;
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> redEdges{{0, 1}, {1, 2}};
        std::vector<std::vector<int>> blueEdges;
        std::vector<int> expected{0, 1, -1};
        auto ret = shortestAlternatingPaths(3, redEdges, blueEdges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> redEdges{{0, 1}};
        std::vector<std::vector<int>> blueEdges{{2, 1}};
        std::vector<int> expected{0, 1, -1};
        auto ret = shortestAlternatingPaths(3, redEdges, blueEdges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> redEdges{{1, 0}};
        std::vector<std::vector<int>> blueEdges{{2, 1}};
        std::vector<int> expected{0, -1, -1};
        auto ret = shortestAlternatingPaths(3, redEdges, blueEdges);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> redEdges{{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        std::vector<std::vector<int>> blueEdges{{1, 2}, {2, 3}, {3, 1}};
        std::vector<int> expected{0, 1, 2, 3, 7};
        auto ret = shortestAlternatingPaths(5, redEdges, blueEdges);
        assert(ret == expected);
    }
    return 0;
}
