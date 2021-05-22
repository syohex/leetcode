#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <cmath>
#include <set>

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> ret;

    std::function<void(int pos, std::vector<int> &acc)> f;
    f = [&f, &n, &ret](int pos, std::vector<int> &acc) {
        if (pos == n) {
            std::vector<std::string> v(n);
            std::string tmp(n, 0);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j == acc[i]) {
                        tmp[j] = 'Q';
                    } else {
                        tmp[j] = '.';
                    }
                }
                v[i] = tmp;
            }
            ret.push_back(v);
            return;
        }

        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < pos; ++j) {
                if (i == acc[j] || std::abs(i - acc[j]) == pos - j) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                acc[pos] = i;
                f(pos + 1, acc);
            }
        }
    };

    std::vector<int> acc(n);
    f(0, acc);
    return ret;
}

void check(const std::vector<std::vector<std::string>> &got, const std::vector<std::vector<std::string>> &expected) {
    std::set<std::vector<std::string>> g(got.begin(), got.end());
    std::set<std::vector<std::string>> e(expected.begin(), expected.end());

    assert(g == e);
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<std::string>> expected{
            {
                ".Q..",
                "...Q",
                "Q...",
                "..Q.",
            },
            {
                "..Q.",
                "Q...",
                "...Q",
                ".Q.."
            }
        };
        //clang-format on

        auto ret = solveNQueens(4);
        check(ret, expected);
    }
    {
        // clang-format off
        std::vector<std::vector<std::string>> expected{
            {
                "Q",
            },
        };
        //clang-format on

        auto ret = solveNQueens(1);
        check(ret, expected);
    }
    return 0;
}
