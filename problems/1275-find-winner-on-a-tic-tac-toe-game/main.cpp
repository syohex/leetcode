#include <cassert>
#include <vector>
#include <string>

std::string tictactoe(const std::vector<std::vector<int>> &moves) {
    enum Val {
        kNone,
        kA,
        kB,
    };

    Val b[3][3]{
        {kNone, kNone, kNone},
        {kNone, kNone, kNone},
        {kNone, kNone, kNone},
    };

    Val val = kA;
    for (const auto &m : moves) {
        b[m[0]][m[1]] = val;
        if (val == kA) {
            val = kB;
        } else {
            val = kA;
        }
    }

    for (size_t i = 0; i < 3; ++i) {
        if (b[i][0] != kNone && b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
            return b[i][0] == kA ? "A" : "B";
        }
        if (b[0][i] != kNone && b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
            return b[0][i] == kA ? "A" : "B";
        }
    }

    if (b[1][1] != kNone) {
        if ((b[0][0] == b[1][1] && b[1][1] == b[2][2]) || (b[0][2] == b[1][1] && b[1][1] == b[2][0])) {
            return b[1][1] == kA ? "A" : "B";
        }
    }

    return moves.size() == 9 ? "Draw" : "Pending";
}

int main() {
    {
        std::vector<std::vector<int>> input{
            {0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2},
        };
        assert(tictactoe(input) == "A");
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0},
        };
        assert(tictactoe(input) == "B");
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2},
        };
        assert(tictactoe(input) == "Draw");
    }
    {
        std::vector<std::vector<int>> input{
            {0, 0},
            {1, 1},
        };
        assert(tictactoe(input) == "Pending");
    }
    {
        std::vector<std::vector<int>> input{
            {0, 2},
            {0, 1},
            {2, 1},
        };
        assert(tictactoe(input) == "Pending");
    }
    return 0;
}
