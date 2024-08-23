#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>

std::string fractionAddition(const std::string &expression) {
    std::size_t len = expression.size();

    const auto parse_num = [&](const std::string &s, std::size_t &pos) -> long {
        long sign = 1;

        while (s[pos] == '+' || s[pos] == '-') {
            if (s[pos] == '-') {
                sign *= -1;
            }
            ++pos;
        }

        long v = 0;
        while (pos < len) {
            char c = s[pos];
            if (c == '+' || c == '-') {
                break;
            } else if (c == '/') {
                ++pos;
                break;
            }

            v = 10 * v + s[pos] - '0';
            ++pos;
        }

        return sign * v;
    };

    const auto parse_term = [&](const std::string &s, std::size_t &pos) -> std::pair<long, long> {
        int v1 = parse_num(s, pos);
        int v2 = parse_num(s, pos);
        return {v1, v2};
    };

    const auto cancel = [](long a, long b) -> std::string {
        if (a == 0) {
            return "0/1";
        }

        long divisor = std::gcd(a, b);
        return std::to_string(a / divisor) + "/" + std::to_string(b / divisor);
    };

    std::vector<std::pair<long, long>> terms;
    std::size_t pos = 0;
    while (pos < len) {
        terms.push_back(parse_term(expression, pos));
    }

    std::pair<long, long> v{0, 1};
    for (const auto &[n1, n2] : terms) {
        v.first = v.first * n2 + n1 * v.second;
        v.second = v.second * n2;
    }

    return cancel(v.first, v.second);
}

int main() {
    assert(fractionAddition("-1/2+1/2") == "0/1");
    assert(fractionAddition("-1/2+1/2+1/3") == "1/3");
    assert(fractionAddition("1/3-1/2") == "-1/6");
    return 0;
}