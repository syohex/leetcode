#include <cassert>
#include <vector>
#include <stack>

bool validPath(int n, const std::vector<std::vector<int>> &edges, int start, int end) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::stack<int> stack;
    stack.push(start);

    std::vector<bool> checked(n, false);
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        if (current == end) {
            return true;
        }

        checked[current] = true;

        for (int p : graph[current]) {
            if (checked[p]) {
                continue;
            }

            stack.push(p);
        }
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};
        assert(validPath(3, edges, 0, 2));
    }
    {
        std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
        assert(!validPath(6, edges, 0, 5));
    }
    {
        std::vector<std::vector<int>> edges{{4, 3}, {1, 4}, {4, 8}, {1, 7}, {6, 4}, {4, 2}, {7, 4}, {4, 0}, {0, 9}, {5, 4}};
        assert(validPath(10, edges, 5, 9));
    }

    return 0;
}