#include <cassert>
#include <vector>
#include <string>
#include <functional>

bool exist(const std::vector<std::vector<char>> &board, const std::string &word) {
    int rows = board.size();
    int cols = board[0].size();

    std::vector<std::vector<int>> moves{
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1},
    };
    std::vector<std::vector<bool>> checked(rows, std::vector<bool>(cols, false));

    std::function<bool(size_t pos, int row, int col)> f;
    f = [&](size_t pos, int row, int col) -> bool {
        if (pos == word.size()) {
            return true;
        }

        checked[row][col] = true;
        for (const auto &move : moves) {
            int x = row + move[0];
            int y = col + move[1];

            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                if (checked[x][y] || board[x][y] != word[pos]) {
                    continue;
                }

                if (f(pos + 1, x, y)) {
                    return true;
                }
            }
        }

        checked[row][col] = false;
        return false;
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == word[0] && f(1, i, j)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    {
        std::vector<std::vector<char>> board{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        assert(exist(board, "ABCCED"));
    }
    {
        std::vector<std::vector<char>> board{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        assert(exist(board, "SEE"));
    }
    {
        std::vector<std::vector<char>> board{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        assert(!exist(board, "ABCB"));
    }
    return 0;
}