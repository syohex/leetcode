#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <set>

std::vector<std::string> generateParentheses(int n) {
    std::vector<std::string> ret;
    std::function<void(int n, int opened, int pairs, const std::string &s)> f;
    f = [&f, &ret](int n, int opened, int pairs, const std::string &s) {
        if (n == pairs) {
            ret.push_back(s);
            return;
        }

        if (opened + pairs < n) {
            f(n, opened + 1, pairs, s + '(');
        }
        if (opened > 0) {
            f(n, opened - 1, pairs + 1, s + ')');
        }
    };

    f(n, 0, 0, "");

    return ret;
}

void check(const std::vector<std::string> &ret, const std::set<std::string> &expected) {
    std::set<std::string> s;
    for (const auto &str : ret) {
        s.insert(str);
    }

    assert(s == expected);
}

int main() {
    {
        std::set<std::string> expected{
            "((()))", "(()())", "(())()", "()(())", "()()()",
        };
        auto ret = generateParentheses(3);
        check(ret, expected);
    }
    {
        std::set<std::string> expected{
            "()",
        };
        auto ret = generateParentheses(1);
        check(ret, expected);
    }
    return 0;
}
