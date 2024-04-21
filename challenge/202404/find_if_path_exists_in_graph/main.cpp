#include <cassert>
#include <vector>

bool validPath(int n, const std::vector<std::vector<int>> &edges, int source, int destination) {
    std::vector<std::vector<int>> graph(n, std::vector<int>{});
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::vector<int> q;
    q.push_back(source);

    std::vector<bool> checked(n, false);
    while (!q.empty()) {
        int node = q.back();
        q.pop_back();
        if (node == destination) {
            return true;
        }

        checked[node] = true;

        for (int next : graph[node]) {
            if (!checked[next]) {
                q.push_back(next);
            }
        }
    }
    return false;
}

int main() {
    {
        std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};
        bool ret = validPath(3, edges, 0, 2);
        assert(ret);
    }
    {
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
        bool ret = validPath(6, edges, 0, 5);
        assert(!ret);
    }
    return 0;
}
