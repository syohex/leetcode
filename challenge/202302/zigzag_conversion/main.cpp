#include <cassert>
#include <vector>
#include <string>

std::string convert(const std::string &s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    enum class State {
        kDown,
        kUp,
    };

    std::vector<std::vector<char>> v(numRows, std::vector<char>(s.size(), -1));
    int row = 0;
    int col = 0;
    int last_col = 0;
    State state = State::kDown;
    for (char c : s) {
        last_col = col;
        v[row][col] = c;

        switch (state) {
        case State::kDown:
            if (row == numRows - 1) {
                state = State::kUp;
                row -= 1;
                col += 1;
            } else {
                row += 1;
            }
            break;
        case State::kUp:
            if (row == 0) {
                state = State::kDown;
                row += 1;
            } else {
                row -= 1;
                col += 1;
            }
            break;
        }
    }

    std::string ret;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= last_col; ++j) {
            if (v[i][j] != -1) {
                ret.push_back(v[i][j]);
            }
        }
    }
    return ret;
}

int main() {
    {
        std::string s = "PAYPALISHIRING";
        auto ret = convert(s, 3);
        assert(ret == "PAHNAPLSIIGYIR");
    }
    {
        std::string s = "PAYPALISHIRING";
        auto ret = convert(s, 4);
        assert(ret == "PINALSIGYAHRPI");
    }
    {
        std::string s = "A";
        auto ret = convert(s, 1);
        assert(ret == "A");
    }
    {
        std::string s = "AB";
        auto ret = convert(s, 1);
        assert(ret == "AB");
    }
    return 0;
}
