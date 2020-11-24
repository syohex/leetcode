#include <cassert>
#include <string>
#include <functional>

int calculate(const std::string &s) {
    const auto skipWhiteSpace = [](const std::string &s, size_t &pos) {
        while (pos < s.size() && s[pos] == ' ') {
            ++pos;
        }
    };

    const auto number = [&](const std::string &s, size_t &pos) -> int {
        skipWhiteSpace(s, pos);

        int ret = 0;
        while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
            ret = 10 * ret + (s[pos] - '0');
            ++pos;
        }

        return ret;
    };

    const auto term = [&](const std::string &s, size_t &pos) -> int {
        int ret = number(s, pos);
        skipWhiteSpace(s, pos);

        while (pos < s.size() && (s[pos] == '*' || s[pos] == '/')) {
            ++pos;
            if (s[pos - 1] == '*') {
                ret *= number(s, pos);
            } else {
                ret /= number(s, pos);
            }

            skipWhiteSpace(s, pos);
        }

        return ret;
    };

    const auto expression = [&](const std::string &s, size_t pos) -> int {
        int ret = term(s, pos);

        skipWhiteSpace(s, pos);

        while (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) {
            ++pos;
            if (s[pos - 1] == '+') {
                ret += term(s, pos);
            } else {
                ret -= term(s, pos);
            }

            skipWhiteSpace(s, pos);
        }

        return ret;
    };

    return expression(s, 0);
}

int main() {
    assert(calculate("3+2*2") == 7);
    assert(calculate("  3/2  ") == 1);
    assert(calculate("  3 + 5    / 2") == 5);
    assert(calculate("42") == 42);
    return 0;
}
