#include <cassert>
#include <vector>
#include <set>
#include <stack>

bool validPath(int n, const std::vector<std::vector<int>> &edges, int start, int end) {
    if (start == end) {
        return true;
    }
    std::vector<std::set<int>> v(n);
    for (const auto &edge : edges) {
        v[edge[0]].insert(edge[1]);
        v[edge[1]].insert(edge[0]);
    }

    std::set<int> checked;

    std::stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (checked.find(node) != checked.end()) {
            continue;
        }

        checked.insert(node);

        for (int p : v[node]) {
            if (p == end) {
                return true;
            }

            stack.push(p);
        }
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<int>> edges{
            {0, 1},
            {1, 2},
            {2, 0},
        };
        assert(validPath(3, edges, 0, 2));
    }
    {
        std::vector<std::vector<int>> edges{
            {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3},
        };
        assert(!validPath(6, edges, 0, 5));
    }
    {
        std::vector<std::vector<int>> edges{
            {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3},
        };
        assert(!validPath(6, edges, 0, 5));
    }
    return 0;
}
