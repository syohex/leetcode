#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

int snakesAndLadders(const std::vector<std::vector<int>> &board) {
    int n = board.size();

    std::vector<std::pair<int, int>> cells(n * n + 1);
    std::vector<int> columns(n);
    std::iota(columns.begin(), columns.end(), 0);

    int id = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int column : columns) {
            cells[id] = {i, column};
            ++id;
        }
        std::reverse(columns.begin(), columns.end());
    }

    std::vector<int> dist(n * n + 1, -1);
    dist[1] = 0;

    std::deque<int> q;
    q.push_back(1);

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();

        int limit = std::min(current + 6, n * n);
        for (int i = current + 1; i <= limit; ++i) {
            auto [row, column] = cells[i];
            int next = board[row][column] == -1 ? i : board[row][column];
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push_back(next);
            }
        }
    }

    return dist[n * n];
}

int main() {
    {
        std::vector<std::vector<int>> board{{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
                                            {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
        int ret = snakesAndLadders(board);
        assert(ret == 4);
    }
    {
        std::vector<std::vector<int>> board{{-1, -1}, {-1, 3}};
        int ret = snakesAndLadders(board);
        assert(ret == 1);
    }
    return 0;
}
