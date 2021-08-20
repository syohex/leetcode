#include <cassert>
#include <vector>
#include <functional>
#include <set>

bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    std::vector<std::set<int>> horizontals(9);
    std::vector<std::set<int>> verticals(9);
    std::vector<std::set<int>> blocks(9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int v1 = board[i][j];
            if (v1 != '.') {
                if (horizontals[i].find(v1) != horizontals[i].end()) {
                    return false;
                }

                horizontals[i].insert(v1);
            }

            int v2 = board[j][i];
            if (v2 != '.') {
                if (verticals[i].find(v2) != verticals[i].end()) {
                    return false;
                }

                verticals[i].insert(board[j][i]);
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        int row_base = 3 * (i / 3);
        int col_base = 3 * (i % 3);
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                int v = board[row_base + j][col_base + k];
                if (v != '.') {
                    if (blocks[i].find(v) != blocks[i].end()) {
                        return false;
                    }

                    blocks[i].insert(v);
                }
            }
        }
    }

    std::function<bool(int x, int y)> f;
    f = [&](int x, int y) -> bool {
        if (board[x][y] != '.') {
            if (x == 8 && y == 8) {
                return true;
            }

            if (y == 8) {
                x += 1;
                y = 0;
            } else {
                y += 1;
            }

            return f(x, y);
        }

        for (int i = 1; i <= 9; ++i) {
            bool ok1 = horizontals[x].find(i) == horizontals[x].end();
            bool ok2 = verticals[y].find(i) == verticals[y].end();
            int index = (x / 3) * 3 + y / 3;
            bool ok3 = blocks[index].find(i) == blocks[index].end();

            if (ok1 && ok2 && ok3) {
                if (x == 8 && y == 8) {
                    return true;
                }

                horizontals[x].insert(i);
                verticals[y].insert(i);
                blocks[index].insert(i);

                int next_x, next_y;
                if (y == 8) {
                    next_x = x + 1;
                    next_y = 0;
                } else {
                    next_x = x;
                    next_y = y + 1;
                }

                if (f(next_x, next_y)) {
                    return true;
                }

                horizontals[x].erase(i);
                verticals[y].erase(i);
                blocks[index].erase(i);
            }
        }

        return false;
    };

    return f(0, 0);
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<char>> board{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
		};
        // clang-format on
        assert(isValidSudoku(board));
    }
    {
        // clang-format off
        std::vector<std::vector<char>> board{
			{'8','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'},
		};
        // clang-format on
        assert(!isValidSudoku(board));
    }

    return 0;
}
