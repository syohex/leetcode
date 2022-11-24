#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <set>
#include <cstdio>

bool exist(const std::vector<std::vector<char>> &board, const std::string &word) {
    int rows = board.size();
    int cols = board[0].size();

    std::vector<std::vector<int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::function<bool(int row, int col, size_t pos, std::vector<std::vector<bool>> &visited)> f;
    f = [&](int row, int col, size_t pos, std::vector<std::vector<bool>> &visited) -> bool {
        if (pos == word.size()) {
            return true;
        }

        visited[row][col] = true;
        for (const auto &step : steps) {
            int new_row = row + step[0];
            int new_col = col + step[1];

            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
                if (visited[new_row][new_col]) {
                    continue;
                }

                if (board[new_row][new_col] != word[pos]) {
                    continue;
                }

                if (f(new_row, new_col, pos + 1, visited)) {
                    return true;
                }
            }
        }
        visited[row][col] = false;
        return false;
    };

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == word[0]) {
                if (f(i, j, 1, visited)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        assert(exist(board, "ABCCED"));
        assert(exist(board, "SEE"));
        assert(!exist(board, "ABCB"));
    }
    return 0;
}
