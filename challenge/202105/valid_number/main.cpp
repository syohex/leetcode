#include <cassert>
#include <string>
#include <cctype>

bool isNumber(const std::string &s) {
    bool has_digit = false;
    bool has_dot = false;
    bool has_e = false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            has_digit = true;
        } else if (s[i] == '+' || s[i] == '-') {
            if (i >= 1 && !(s[i - 1] == 'e' || s[i - 1] == 'E')) {
                return false;
            }
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (has_e || !has_digit) {
                return false;
            }

            has_e = true;
            has_digit = false;
        } else if (s[i] == '.') {
            if (has_dot || has_e) {
                return false;
            }

            has_dot = true;
        } else {
            return false;
        }
    }

    return has_digit;
}

int main() {
    auto valids = {"2",     "0089", "-0.1",  "+3.14",   "4.",           "-.9", "2e10",
                   "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", "0",   ".1"};
    auto invalids = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "e", "."};
    for (const auto *valid : valids) {
        assert(isNumber(valid));
    }
    for (const auto *invalid : invalids) {
        assert(!isNumber(invalid));
    }
    return 0;
}
