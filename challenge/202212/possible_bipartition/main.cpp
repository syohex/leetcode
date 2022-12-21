#include <cassert>
#include <vector>
#include <set>
#include <cstdio>
#include <functional>

bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes) {
    std::vector<std::set<int>> graph(n + 1);
    for (const auto &dislike : dislikes) {
        graph[dislike[0]].insert(dislike[1]);
        graph[dislike[1]].insert(dislike[0]);
    }

    const auto f = [&](int start, std::vector<int> &colors) -> bool {
        std::vector<int> q{start};
        colors[start] = 0;

        while (!q.empty()) {
            int node = q.back();
            q.pop_back();

            for (int next : graph[node]) {
                if (colors[next] == colors[node]) {
                    return false;
                }

                if (colors[next] == -1) {
                    colors[next] = colors[node] == 0 ? 1 : 0;
                    q.push_back(next);
                }
            }
        }

        return true;
    };

    std::vector<int> colors(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            if (!f(i, colors)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> dislikes{{1, 2}, {1, 3}, {2, 4}};
        assert(possibleBipartition(4, dislikes));
    }
    {
        std::vector<std::vector<int>> dislikes{{1, 2}, {1, 3}, {2, 3}};
        assert(!possibleBipartition(3, dislikes));
    }
    {
        std::vector<std::vector<int>> dislikes{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
        assert(!possibleBipartition(5, dislikes));
    }
    return 0;
}
