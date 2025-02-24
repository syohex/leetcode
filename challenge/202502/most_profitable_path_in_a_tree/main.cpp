#include <cassert>
#include <vector>
#include <functional>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <limits>

using namespace std;

int mostProfitablePath(const vector<vector<int>> &edges, int bob, const vector<int> &amount) {
    size_t len = edges.size() + 1;
    map<int, vector<int>> graph;
    for (const auto &e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    function<bool(int node, int steps, map<int, int> &m, vector<bool> &visited)> f;
    f = [&](int node, int steps, map<int, int> &m, vector<bool> &visited) -> bool {
        visited[node] = true;
        m[node] = steps;

        if (node == 0) {
            return true;
        }

        for (int next : graph[node]) {
            if (!visited[next]) {
                if (f(next, steps + 1, m, visited)) {
                    return true;
                }
            }
        }

        m.erase(node);
        return false;
    };

    map<int, int> bob_steps;
    vector<bool> visited(len, false);
    f(bob, 0, bob_steps, visited);

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    visited = vector<bool>(len, false);
    int ret = numeric_limits<int>::min();
    while (!q.empty()) {
        auto [node, steps, income] = q.front();
        q.pop();
        visited[node] = true;

        if (bob_steps.find(node) == bob_steps.end() || steps < bob_steps[node]) {
            income += amount[node];
        } else if (steps == bob_steps[node]) {
            income += amount[node] / 2;
        }

        if (graph[node].size() == 1 && node != 0) {
            ret = max(ret, income);
        }

        for (int next : graph[node]) {
            if (!visited[next]) {
                q.push({next, steps + 1, income});
            }
        }
    }
    return ret;
}

int main() {
    {
        vector<vector<int>> edges{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
        vector<int> amount{-2, 4, 2, -4, 6};
        int ret = mostProfitablePath(edges, 3, amount);
        assert(ret == 6);
    }
    {
        vector<vector<int>> edges{{0, 1}};
        vector<int> amount{-7280, 2350};
        int ret = mostProfitablePath(edges, 1, amount);
        assert(ret == -7280);
    }
    {
        vector<vector<int>> edges{
            {0, 2}, {0, 5}, {1, 3}, {1, 5}, {2, 4},
        };
        vector<int> amount{5018, 8388, 6224, 3466, 3808, 3456};
        int ret = mostProfitablePath(edges, 4, amount);
        assert(ret == 20328);
    }
    return 0;
}
