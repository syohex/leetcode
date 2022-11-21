#include <cassert>
#include <string>
#include <functional>

int calculate(const std::string &s) {
    std::function<std::int64_t(const std::string &s, size_t &pos)> expr;
    std::function<std::int64_t(const std::string &s, size_t &pos)> factor;

    expr = [&](const std::string &s, size_t &pos) -> std::int64_t {
        std::int64_t val = factor(s, pos);
        while (s[pos] == '+' || s[pos] == '-') {
            char op = s[pos];

            ++pos;
            std::int64_t val2 = factor(s, pos);
            if (op == '+') {
                val = val + val2;
            } else {
                val = val - val2;
            }
        }

        return val;
    };

    factor = [&](const std::string &s, size_t &pos) -> std::int64_t {
        bool negative = false;
        if (s[pos] == '-') {
            negative = true;
            ++pos;
        }

        std::int64_t ret = 0;
        if (s[pos] == '(') {
            ++pos;
            ret = expr(s, pos);
            ++pos;
        }

        size_t len = s.size();
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            ret = ret * 10 + s[pos] - '0';
            ++pos;
        }

        if (negative) {
            return -ret;
        }

        return ret;
    };

    std::string input;
    for (char c : s) {
        if (c != ' ') {
            input.push_back(c);
        }
    }

    size_t pos = 0;
    return expr(input, pos);
}

int main() {
    {
        std::string s = "1 + 1";
        int ret = calculate(s);
        assert(ret == 2);
    }
    {
        std::string s = "2-1 + 2";
        int ret = calculate(s);
        assert(ret == 3);
    }
    {
        std::string s = "(1+(4+5+2)-3)+(6+8)";
        int ret = calculate(s);
        assert(ret == 23);
    }
    {
        std::string s = "- (3 + (4 + 5))";
        int ret = calculate(s);
        assert(ret == -12);
    }
    {
        std::string s = "-123";
        int ret = calculate(s);
        assert(ret == -123);
    }
    return 0;
}
