#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

int robotSim(const std::vector<int> &commands, const std::vector<std::vector<int>> &obstacles) {
    const auto get_key = [](int x, int y) { return 60'001 * x + y; };
    std::vector<std::pair<int, int>> steps{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    std::set<int> obstacle_set;
    for (const auto &v : obstacles) {
        obstacle_set.insert(get_key(v[0], v[1]));
    }

    int direction = 0;
    int x = 0;
    int y = 0;
    int ret = 0;
    for (int command : commands) {
        switch (command) {
        case -2:
            direction = (direction + 3) % 4;
            break;
        case -1:
            direction = (direction + 1) % 4;
            break;
        default:
            for (int i = 0; i < command; ++i) {
                int new_x = x + steps[direction].first;
                int new_y = y + steps[direction].second;

                int key = get_key(new_x, new_y);
                if (obstacle_set.find(key) != obstacle_set.end()) {
                    break;
                }

                x = new_x;
                y = new_y;

                ret = std::max(ret, x * x + y * y);
            }
            break;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> commands{4, -1, 3};
        std::vector<std::vector<int>> obstacles{};
        int ret = robotSim(commands, obstacles);
        assert(ret == 25);
    }
    {
        std::vector<int> commands{4, -1, 4, -2, 4};
        std::vector<std::vector<int>> obstacles{{2, 4}};
        int ret = robotSim(commands, obstacles);
        assert(ret == 65);
    }
    {
        std::vector<int> commands{6, -1, -1, 6};
        std::vector<std::vector<int>> obstacles{};
        int ret = robotSim(commands, obstacles);
        assert(ret == 36);
    }
    return 0;
}