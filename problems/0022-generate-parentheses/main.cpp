#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <stack>

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ret;
    if (n <= 0) {
        return ret;
    }

    auto check = [](const std::string &str) -> bool {
        std::stack<char> st;
        for (char c : str) {
            if (c == ')') {
                while (!st.empty()) {
                    char tmp = st.top();
                    st.pop();
                    if (tmp == '(') {
                        break;
                    }
                }
            } else {
                st.push(c);
            }
        }

        return st.empty();
    };

    std::function<void(const std::string &acc, int left, int right)> f;
    f = [&f, &check, &ret](const std::string &acc, int left, int right) {
        if (left == 0 && right == 0) {
            if (check(acc)) {
                ret.push_back(acc);
            }
            return;
        }

        if (left != 0) {
            f(acc + "(", left - 1, right);
        }
        if (right != 0) {
            f(acc + ")", left, right - 1);
        }
    };

    f("(", n - 1, n);
    return ret;
}

int main() {
    {
        auto ret = generateParenthesis(3);
        assert(ret.size() == 5);

        std::vector<std::string> expected{
            "((()))", "(()())", "(())()", "()(())", "()()()",
        };

        for (const auto &s : expected) {
            assert(std::find(ret.begin(), ret.end(), s) != ret.end());
        }
    }
    return 0;
}
