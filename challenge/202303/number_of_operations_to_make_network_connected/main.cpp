#include <cassert>
#include <vector>
#include <queue>
#include <cstddef>
#include <functional>
#include <cstdio>

int makeConnected(int n, const std::vector<std::vector<int>> &connections) {
    if (static_cast<int>(connections.size()) < n - 1) {
        return -1;
    }

    std::vector<std::vector<int>> graph(n);
    for (const auto &connection : connections) {
        graph[connection[0]].push_back(connection[1]);
        graph[connection[1]].push_back(connection[0]);
    }

    std::function<void(int n, std::vector<bool> &visited)> f;
    f = [&](int node, std::vector<bool> &visited) {
        std::queue<int> q;
        q.emplace(node);

        while (!q.empty()) {
            size_t len = q.size();

            for (size_t i = 0; i < len; ++i) {
                auto node = q.front();
                q.pop();

                for (int next : graph[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    };

    std::vector<bool> visited(n);
    int islands = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++islands;
            visited[i] = true;
            f(i, visited);
        }
    }

    return islands - 1;
}

int main() {
    {
        int n = 4;
        std::vector<std::vector<int>> connections{{0, 1}, {0, 2}, {1, 2}};
        int ret = makeConnected(n, connections);
        assert(ret == 1);
    }
    {
        int n = 6;
        std::vector<std::vector<int>> connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
        int ret = makeConnected(n, connections);
        assert(ret == 2);
    }
    {
        int n = 6;
        std::vector<std::vector<int>> connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}};
        int ret = makeConnected(n, connections);
        assert(ret == -1);
    }
    return 0;
}
