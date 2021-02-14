#include <cassert>
#include <vector>
#include <stack>
#include <cstdio>

bool isBipartite(const std::vector<std::vector<int>> &graph) {
    enum Color {
        kNone,
        kRed,
        kBlue,
    };

    std::vector<Color> colors(graph.size(), Color::kNone);
    int len = graph.size();
    for (int i = 0; i < len; ++i) {
        if (colors[i] != Color::kNone) {
            continue;
        }

        std::stack<int> stack;
        stack.push(i);
        colors[i] = Color::kRed;

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            for (int n : graph[node]) {
                if (colors[n] == Color::kNone) {
                    colors[n] = colors[node] == Color::kRed ? Color::kBlue : Color::kRed;
                    stack.push(n);
                } else if (colors[n] == colors[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> graph {
            {1, 3},
            {0, 2},
            {1, 3},
            {0, 2},
        };
        // clang-format on
        assert(isBipartite(graph));
    }
    {
        // clang-format off
        std::vector<std::vector<int>> graph {
            {1, 2, 3},
            {0, 2},
            {0, 1, 3},
            {0, 2},
        };
        // clang-format on
        assert(!isBipartite(graph));
    }
    {
        // clang-format off
        std::vector<std::vector<int>> graph {
            {},
            {3},
            {},
            {1},
            {},
        };
        // clang-format on
        assert(isBipartite(graph));
    }
    {
        // clang-format off
        std::vector<std::vector<int>> graph {
            {1},
            {0, 3},
            {3},
            {1, 2},
        };
        // clang-format on
        assert(isBipartite(graph));
    }
    {
        // clang-format off
        std::vector<std::vector<int>> graph {
            {4, 1},
            {0, 2},
            {1, 3},
            {2, 4},
            {3, 0},
        };
        // clang-format on
        assert(!isBipartite(graph));
    }
    {
        // clang-format off
        std::vector<std::vector<int>> graph {
            {3},
            {2, 4},
            {1},
            {0, 4},
            {1, 3},
        };
        // clang-format on
        assert(isBipartite(graph));
    }

    return 0;
}
