#include <cassert>
#include <vector>
#include <string>
#include <functional>

bool exist(std::vector<std::vector<char>> &board, const std::string &word) {
    std::function<bool(size_t pos, size_t row, size_t col)> f;
    f = [&f, &board, &word](size_t pos, size_t row, size_t col) -> bool {
        if (pos == word.size()) {
            return true;
        }

        char orig = board[row][col];
        board[row][col] = '!';

        int rs[4] = {-1, 0, 0, 1};
        int cs[4] = {0, -1, 1, 0};
        int row_limit = board.size();
        int col_limit = board[row].size();
        for (int i = 0; i < 4; ++i) {
            int r = row + rs[i];
            int c = col + cs[i];
            if (r >= 0 && r < row_limit && c >= 0 && c < col_limit) {
                if (board[r][c] == word[pos]) {
                    if (f(pos + 1, r, c)) {
                        return true;
                    }
                }
            }
        }

        board[row][col] = orig;
        return false;
    };

    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == word[0]) {
                if (f(1, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<char>> input{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        // clang-format on

        assert(exist(input, "ABCCED"));
    }
    {
        // clang-format off
        std::vector<std::vector<char>> input{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        // clang-format on

        assert(exist(input, "SEE"));
    }
    {
        // clang-format off
        std::vector<std::vector<char>> input{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        // clang-format on

        assert(!exist(input, "ABCB"));
    }
    return 0;
}
