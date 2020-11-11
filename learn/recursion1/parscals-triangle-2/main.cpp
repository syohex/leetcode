#include <cassert>
#include <vector>
#include <functional>
#include <map>
#include <tuple>

std::vector<int> getRow(int rowIndex) {
    struct Arg {
        int row;
        int col;
        int max_col;

        bool operator<(const Arg &other) const {
            return std::tie(row, col, max_col) < std::tie(other.row, other.col, other.max_col);
        }
    };

    std::map<Arg, int> m;
    std::function<int(const Arg &a)> f;
    f = [&f, &m](const Arg &a) -> int {
        if (a.row == 0 || a.col == 0 || a.col == a.max_col) {
            return 1;
        }

        const auto &it = m.find(a);
        if (it != m.end()) {
            return it->second;
        }

        Arg left_arg{a.row - 1, a.col - 1, a.max_col - 1};
        int left = f(left_arg);
        m[left_arg] = left;

        Arg right_arg{a.row - 1, a.col, a.max_col - 1};
        int right = f(right_arg);
        m[right_arg] = right;
        return left + right;
    };

    std::vector<int> ret;
    for (int i = 0; i <= rowIndex; ++i) {
        ret.push_back(f(Arg{rowIndex, i, rowIndex}));
    }

    return ret;
}

int main() {
    assert((getRow(3) == std::vector<int>{1, 3, 3, 1}));
    assert((getRow(0) == std::vector<int>{1}));
    assert((getRow(1) == std::vector<int>{1, 1}));
    return 0;
}
