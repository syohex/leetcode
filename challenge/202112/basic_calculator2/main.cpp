#include <cassert>
#include <string>
#include <functional>

int calculate(std::string s) {
    std::string str;
    for (char c : s) {
        if (c != ' ') {
            str.push_back(c);
        }
    }

    std::function<int(const std::string &s, size_t &pos)> expr;
    std::function<int(const std::string &s, size_t &pos)> term;

    const auto number = [](const std::string &s, size_t &pos) {
        int val = 0;
        while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
            val = 10 * val + (s[pos] - '0');
            ++pos;
        }
        return val;
    };

    expr = [&](const std::string &s, size_t &pos) -> int {
        int val = term(s, pos);
        while (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) {
            int op = s[pos];
            ++pos;

            int val2 = term(s, pos);
            if (op == '+') {
                val += val2;
            } else {
                val -= val2;
            }
        }
        return val;
    };

    term = [&](const std::string &s, size_t &pos) -> int {
        int val = number(s, pos);
        while (pos < s.size() && (s[pos] == '*' || s[pos] == '/')) {
            int op = s[pos];
            ++pos;

            int val2 = number(s, pos);
            if (op == '*') {
                val *= val2;
            } else {
                val /= val2;
            }
        }
        return val;
    };

    size_t pos = 0;
    return expr(str, pos);
}

int main() {
    assert(calculate("3+2*2") == 7);
    assert(calculate(" 3/2 ") == 1);
    assert(calculate(" 3+5 / 2") == 5);
    assert(calculate("2147483640") == 2147483640);
    return 0;
}
