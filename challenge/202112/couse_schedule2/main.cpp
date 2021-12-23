#include <cassert>
#include <vector>
#include <map>
#include <set>

std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>> &prerequisites) {
    std::map<int, std::vector<int>> graph;
    std::map<int, std::set<int>> dependencies;
    for (const auto &p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        dependencies[p[0]].insert(p[1]);
    }

    std::vector<int> ret;
    std::vector<int> stack;
    std::vector<bool> checked(numCourses);
    for (int i = 0; i < numCourses; ++i) {
        if (dependencies.find(i) == dependencies.end()) {
            stack.push_back(i);
            ret.push_back(i);
            checked[i] = true;
        }
    }

    while (!stack.empty()) {
        int current = stack.back();
        stack.pop_back();

        for (int next : graph[current]) {
            if (checked[next]) {
                continue;
            }

            bool ok = true;
            for (int dep : dependencies[next]) {
                if (!checked[dep]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                stack.push_back(next);
                checked[next] = true;
                ret.push_back(next);
            }
        }
    }

    if (static_cast<int>(ret.size()) < numCourses) {
        return {};
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> prerequisites{{1, 0}};
        std::vector<int> expected{0, 1};
        auto ret = findOrder(2, prerequisites);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> prerequisites{
            {1, 0},
            {2, 0},
            {3, 1},
            {3, 2},
        };
        std::vector<int> expected{0, 1, 2, 3};
        auto ret = findOrder(4, prerequisites);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> prerequisites{};
        std::vector<int> expected{0};
        auto ret = findOrder(1, prerequisites);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> prerequisites{};
        std::vector<int> expected{0, 1};
        auto ret = findOrder(2, prerequisites);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> prerequisites{{0, 1}};
        std::vector<int> expected{1, 0};
        auto ret = findOrder(2, prerequisites);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> prerequisites{{0, 1}, {1, 0}};
        auto ret = findOrder(2, prerequisites);
        assert(ret.empty());
    }
    {
        std::vector<std::vector<int>> prerequisites{{0, 1}, {0, 2}, {1, 2}};
        std::vector<int> expected{2, 1, 0};
        auto ret = findOrder(3, prerequisites);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> prerequisites{{1, 0}, {1, 2}, {0, 1}};
        auto ret = findOrder(3, prerequisites);
        assert(ret.empty());
    }
    return 0;
}