#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <functional>

bool canFinish(int numCourses, const std::vector<std::vector<int>> &prerequisites) {
    std::function<bool(int node, std::map<int, std::set<int>> &graph, std::vector<bool> &visited)> f;
    f = [&f](int node, std::map<int, std::set<int>> &graph, std::vector<bool> &visited) -> bool {
        if (visited[node]) {
            return true;
        }

        if (graph.find(node) == graph.end()) {
            // leaf node
            return false;
        }

        visited[node] = true;

        for (int next : graph[node]) {
            if (f(next, graph, visited)) {
                return true;
            }
        }

        visited[node] = false;
        return false;
    };

    std::map<int, std::set<int>> graph;
    for (const auto &p : prerequisites) {
        graph[p[1]].insert(p[0]);
    }

    std::vector<bool> visited(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
        if (f(i, graph, visited)) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::vector<int>> prerequisites{{1, 0}};
        assert(canFinish(2, prerequisites));
    }
    {
        std::vector<std::vector<int>> prerequisites{{1, 0}, {0, 1}};
        assert(!canFinish(2, prerequisites));
    }
    {
        std::vector<std::vector<int>> prerequisites{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
        assert(canFinish(5, prerequisites));
    }
    {
        std::vector<std::vector<int>> prerequisites{{1, 0}, {0, 3}, {0, 2}, {3, 2}, {2, 5}, {4, 5}, {5, 6}, {2, 4}};
        assert(canFinish(7, prerequisites));
    }
    return 0;
}