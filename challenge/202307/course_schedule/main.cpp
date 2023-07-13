#include <cassert>
#include <vector>
#include <functional>

bool canFinish(int numCourses, const std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> graph(numCourses);
    for (const auto& prequisite : prerequisites) {
        graph[prequisite[1]].push_back(prequisite[0]);
    }

    std::function<bool(int node, std::vector<int> &passed)> hasCircle;
    hasCircle = [&](int node, std::vector<int> &passed) -> bool {
        if (passed[node]) {
            return true;
        }

        passed[node] = true;
        for (int next : graph[node]) {
            if (hasCircle(next, passed)) {
                return true;
            }
        }

        passed[node] = false;
        return false;
    };

    for (int i = 0; i < numCourses; ++i) {
        std::vector<int> passed(numCourses, false);
        if (hasCircle(i, passed)) {
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
    return 0;
}
