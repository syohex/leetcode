#include <cassert>
#include <vector>
#include <set>
#include <map>

std::vector<std::vector<int>> findWinners(const std::vector<std::vector<int>> &matches) {
    std::map<int, int> win;
    std::map<int, int> lose;
    std::set<int> player;

    for (const auto &v : matches) {
        ++win[v[0]];
        ++lose[v[1]];
        player.insert(v[0]);
        player.insert(v[1]);
    }

    std::vector<std::vector<int>> ret(2);
    for (int p : player) {
        if (win.find(p) != win.end() && lose.find(p) == lose.end()) {
            ret[0].push_back(p);
        } else if (lose.find(p) != lose.end() && lose[p] == 1) {
            ret[1].push_back(p);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> matches{{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
        std::vector<std::vector<int>> expected{{1, 2, 10}, {4, 5, 7, 8}};
        auto ret = findWinners(matches);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> matches{{2, 3}, {1, 3}, {5, 4}, {6, 4}};
        std::vector<std::vector<int>> expected{{1, 2, 5, 6}, {}};
        auto ret = findWinners(matches);
        assert(ret == expected);
    }
    return 0;
}
