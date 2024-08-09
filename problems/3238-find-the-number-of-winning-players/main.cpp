#include <cassert>
#include <vector>
#include <map>

int winningPlayerCount(int n, const std::vector<std::vector<int>> &pick) {
    std::vector<std::map<int, int>> v(n, std::map<int, int>{});
    for (const auto &p : pick) {
        ++v[p[0]][p[1]];
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = false;
        for (const auto &[k, v] : v[i]) {
            if (v > i) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> pick{{0, 0}, {1, 0}, {1, 0}, {2, 1}, {2, 1}, {2, 0}};
        int ret = winningPlayerCount(4, pick);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> pick{{1, 1}, {1, 2}, {1, 3}, {1, 4}};
        int ret = winningPlayerCount(5, pick);
        assert(ret == 0);
    }
    {
        std::vector<std::vector<int>> pick{{1, 1}, {2, 4}, {2, 4}, {2, 4}};
        int ret = winningPlayerCount(5, pick);
        assert(ret == 1);
    }

    return 0;
}
