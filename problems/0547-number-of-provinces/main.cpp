#include <cassert>
#include <vector>
#include <set>

int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
    std::set<int> checked;

    int ret = 0;
    int len = isConnected.size();
    for (int i = 0; i < len; ++i) {
        if (checked.find(i) != checked.end()) {
            continue;
        }

        checked.insert(i);

        std::vector<int> stack{i};
        while (!stack.empty()) {
            int node = stack.back();
            stack.pop_back();

            for (int j = 0; j < len; ++j) {
                if (isConnected[node][j] == 1) {
                    if (checked.find(j) != checked.end()) {
                        continue;
                    }

                    checked.insert(j);
                    stack.push_back(j);
                }
            }
        }

        ++ret;
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> is_connected {
            {1,1,0},
            {1,1,0},
            {0,0,1},
        };
        assert(findCircleNum(is_connected) == 2);
    }
    {
        std::vector<std::vector<int>> is_connected {
            {1,0,0},
            {0,1,0},
            {0,0,1},
        };
        assert(findCircleNum(is_connected) == 3);
    }
    return 0;
}