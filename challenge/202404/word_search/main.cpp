#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <functional>

bool exist(const std::vector<std::vector<char>> &board, const std::string &word) {
    std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int rows = board.size();
    int cols = board[0].size();

    std::function<bool(int row, int col, size_t pos, std::vector<std::vector<bool>> &checked)> f;
    f = [&](int row, int col, size_t pos, std::vector<std::vector<bool>> &checked) -> bool {
        if (pos == word.size()) {
            return true;
        }

        for (auto [x, y] : steps) {
            int a = row + x;
            int b = col + y;
            if (a >= 0 && a < rows && b >= 0 && b < cols && !checked[a][b] && board[a][b] == word[pos]) {
                checked[a][b] = true;
                if (f(a, b, pos + 1, checked)) {
                    return true;
                }
                checked[a][b] = false;
            }
        }

        return false;
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == word[0]) {
                std::vector<std::vector<bool>> checked(rows, std::vector<bool>(cols));
                checked[i][j] = true;
                if (f(i, j, 1, checked)) {
                    return true;
                }
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
    {
        std::vector<std::vector<char>> board{
            {'A', 'B'},
            {'C', 'D'},
        };
        assert(exist(board, "ACDB"));
    }
    {
        std::vector<std::vector<char>> board{
            {'A', 'A'},
        };
        assert(!exist(board, "AAA"));
    }
    return 0;
}
