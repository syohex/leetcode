#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <stack>

bool validPath(int n, const std::vector<std::vector<int>> &edges, int start, int end) {
    std::map<int, std::set<int>> graph;
    for (const auto &edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    std::stack<int> stack;
    stack.push(start);

    std::set<int> checked;
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        if (current == end) {
            return true;
        }

        checked.insert(start);

        for (int p : graph[current]) {
            if (checked.find(p) != checked.end()) {
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
    return 0;
}