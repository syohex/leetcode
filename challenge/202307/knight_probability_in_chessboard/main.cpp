#include <cassert>
#include <queue>
#include <utility>
#include <vector>
#include <cstdio>

double knightProbability(int n, int k, int row, int column) {
    std::queue<std::pair<int, int>> q;
    q.push({row, column});

    std::vector<std::pair<int, int>> steps{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

    for (int i = 0; i < k; ++i) {
        int len = q.size();
        for (int j = 0; j < len; ++j) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto &[x, y] : steps) {
                int new_r = r + x;
                int new_c = c + y;
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n) {
                    q.push({new_r, new_c});
                }
            }
        }
    }

    auto ret = static_cast<double>(q.size());
    for (int i = 0; i < k; ++i) {
        ret /= 8.0;
    }

    return ret;
}

int main() {
    {
        double ret = knightProbability(3, 2, 0, 0);
        assert(ret == 0.06250);
    }
    {
        double ret = knightProbability(1, 0, 0, 0);
        assert(ret == 1);
    }
    return 0;
}
