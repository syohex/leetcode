#include <cassert>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    enum class State {
        kRight,
        kDown,
        kLeft,
        kUp,
    };

    std::vector<std::vector<int>> ret(n);
    int limit = n * n;
    for (int i = 0; i < n; ++i) {
        ret[i] = std::vector<int>(n, -1);
    }

    int count = 1;
    ret[0][0] = count;
    ++count;

    State state = State::kRight;
    int row = 0;
    int col = 0;
    while (count <= limit) {
        switch (state) {
        case State::kRight: {
            if (col + 1 < n && ret[row][col + 1] < 0) {
                col += 1;
                ret[row][col] = count;
                ++count;
            } else {
                state = State::kDown;
            }
            break;
        }
        case State::kDown: {
            if (row + 1 < n && ret[row + 1][col] < 0) {
                row += 1;
                ret[row][col] = count;
                ++count;
            } else {
                state = State::kLeft;
            }
            break;
        }
        case State::kLeft: {
            if (col - 1 >= 0 && ret[row][col - 1] < 0) {
                col -= 1;
                ret[row][col] = count;
                ++count;
            } else {
                state = State::kUp;
            }
            break;
        }
        case State::kUp: {
            if (row - 1 >= 0 && ret[row - 1][col] < 0) {
                row -= 1;
                ret[row][col] = count;
                ++count;
            } else {
                state = State::kRight;
            }
            break;
        }
        }
    }

    return ret;
}

int main() {
    {
        auto ret = generateMatrix(3);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{1, 2, 3}));
        assert((ret[1] == std::vector<int>{8, 9, 4}));
        assert((ret[2] == std::vector<int>{7, 6, 5}));
    }
    {
        auto ret = generateMatrix(2);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{1, 2}));
        assert((ret[1] == std::vector<int>{4, 3}));
    }
    {
        auto ret = generateMatrix(1);
        assert(ret.size() == 1);
        assert((ret[0] == std::vector<int>{1}));
    }
    return 0;
}
