#include <cassert>
#include <vector>
#include <stack>

bool isBipartite(const std::vector<std::vector<int>> &graph) {
    int len = graph.size();
    std::vector<int> nodes(len, -1);

    for (int i = 0; i < len; ++i) {
        if (nodes[i] != -1) {
            continue;
        }

        nodes[i] = 1;

        std::stack<int> s;
        s.push(i);
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            for (int n : graph[node]) {
                if (nodes[n] == -1) {
                    nodes[n] = nodes[node] == 1 ? 2 : 1;
                    s.push(n);
                } else if (nodes[n] == nodes[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
        assert(!isBipartite(graph));
    }
    {
        std::vector<std::vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
        assert(isBipartite(graph));
    }
    return 0;
}
