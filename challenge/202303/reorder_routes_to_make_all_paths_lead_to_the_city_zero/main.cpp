#include <cassert>
#include <vector>
#include <functional>
#include <queue>

int minReorder(int n, const std::vector<std::vector<int>> &connections) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (const auto &connection : connections) {
        graph[connection[0]].emplace_back(connection[1], 1);
        graph[connection[1]].emplace_back(connection[0], 0);
    }

    std::queue<int> q;
    q.push(0);

    std::vector<bool> visited(n);
    int ret = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        visited[node] = true;
        for (const auto &[next, direction] : graph[node]) {
            if (visited[next]) {
                continue;
            }

            ret += direction;
            q.push(next);
        }
    }

    return ret;
}

int main() {
    {
        int n = 6;
        std::vector<std::vector<int>> connection{{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
        int ret = minReorder(n, connection);
        assert(ret == 3);
    }
    {
        int n = 5;
        std::vector<std::vector<int>> connection{{1, 0}, {1, 2}, {3, 2}, {3, 4}};
        int ret = minReorder(n, connection);
        assert(ret == 2);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> connection{{1, 0}, {2, 0}};
        int ret = minReorder(n, connection);
        assert(ret == 0);
    }
    return 0;
}
