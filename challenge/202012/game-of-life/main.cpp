#include <cassert>
#include <vector>

void gameOfLife(std::vector<std::vector<int>> &board) {
    auto tmp = board;
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            int lives = 0;
            if (i >= 1) {
                if (j >= 1) {
                    lives += tmp[i - 1][j - 1];
                }
                lives += tmp[i - 1][j];
                if (j + 1 < board[i].size()) {
                    lives += tmp[i - 1][j + 1];
                }
            }
            if (j >= 1) {
                lives += tmp[i][j - 1];
            }
            if (j + 1 < board[i].size()) {
                lives += tmp[i][j + 1];
            }
            if (i + 1 < board.size()) {
                if (j >= 1) {
                    lives += tmp[i + 1][j - 1];
                }
                lives += tmp[i + 1][j];
                if (j + 1 < board[i].size()) {
                    lives += tmp[i + 1][j + 1];
                }
            }

            if (tmp[i][j] == 1) {
                if (lives < 2 || lives > 3) {
                    board[i][j] = 0;
                }
            } else {
                if (lives == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> board {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0},
        };
        std::vector<std::vector<int>> expected {
            {0, 0, 0},
            {1, 0, 1},
            {0, 1, 1},
            {0, 1, 0},
        };
        // clang-format on
        gameOfLife(board);
        assert(board == expected);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> board {
            {1, 1},
            {1, 0},
        };
        std::vector<std::vector<int>> expected {
            {1, 1},
            {1, 1},
        };
        // clang-format on
        gameOfLife(board);
        assert(board == expected);
    }
    return 0;
}
