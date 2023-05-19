#include <cassert>
#include <vector>

bool isBipartite(const std::vector<std::vector<int>> &graph) {
    int len = graph.size();
    std::vector<int> colors(len, 0);

    for (int i = 0; i < len; ++i) {
        if (colors[i] != 0) {
            continue;
        }

        colors[i] = 1;

        std::vector<int> q{i};
        while (!q.empty()) {
            int node = q.back();
            q.pop_back();

            for (int next : graph[node]) {
                if (colors[next] == 0) {
                    colors[next] = colors[node] == 1 ? -1 : 1;
                    q.push_back(next);
                } else if (colors[next] == colors[node]) {
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
