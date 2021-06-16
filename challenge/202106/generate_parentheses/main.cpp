#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <set>
#include <stack>

std::vector<std::string> generateParenthesis(int n) {
    const auto is_ok = [](const std::string &s) -> bool {
        std::stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    };

    std::vector<std::string> ret;
    std::function<void(int m, int opens, int closes, std::string &acc)> f;
    f = [&f, &ret, &n, &is_ok](int m, int opens, int closes, std::string &acc) {
        if (m == 2 * n) {
            if (is_ok(acc)) {
                ret.push_back(acc);
            }
            return;
        }

        if (opens < n) {
            acc[m] = '(';
            f(m + 1, opens + 1, closes, acc);
        }
        if (closes < n) {
            acc[m] = ')';
            f(m + 1, opens, closes + 1, acc);
        }
    };

    std::string acc(2 * n, '(');
    f(1, 1, 0, acc);
    return ret;
}

void check(const std::vector<std::string> &a, const std::vector<std::string> &b) {
    assert(a.size() == b.size());

    std::set<std::string> sa(a.begin(), a.end());
    std::set<std::string> sb(b.begin(), b.end());
    assert(sa == sb);
}

int main() {
    {
        std::vector<std::string> expected{"((()))", "(()())", "(())()", "()(())", "()()()"};
        auto got = generateParenthesis(3);
        check(got, expected);
    }
    {
        std::vector<std::string> expected{"()"};
        auto got = generateParenthesis(1);
        check(got, expected);
    }
    return 0;
}
