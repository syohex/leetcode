#include <cassert>
#include <string>
#include <climits>

int myAtoi(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    size_t i = 0;
    while (i < s.size() && s[i] == ' ') {
        ++i;
    }

    if (i == s.size()) {
        return 0;
    }

    if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-')) {
        return 0;
    }

    bool negative = false;
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            negative = true;
        }
        ++i;
    }

    if (i == s.size()) {
        return 0;
    }

    long val = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
        val = (10 * val) + s[i] - '0';
        if (negative) {
            if (val * -1 < static_cast<long>(INT_MIN)) {
                return INT_MIN;
            }
        } else {
            if (val > static_cast<long>(INT_MAX)) {
                return INT_MAX;
            }
        }
        ++i;
    }

    if (negative) {
        return static_cast<int>(val * -1);
    }

    return static_cast<int>(val);
}

int main() {
    assert(myAtoi("") == 0);
    assert(myAtoi("+") == 0);
    assert(myAtoi("-") == 0);
    assert(myAtoi("             ") == 0);
    assert(myAtoi("words and 987") == 0);

    assert(myAtoi("1234") == 1234);
    assert(myAtoi("-1234") == -1234);
    assert(myAtoi("    -42") == -42);
    assert(myAtoi("4193 with words") == 4193);
    assert(myAtoi("-91283472332") == INT_MIN);
    assert(myAtoi("193092090302909") == INT_MAX);
    return 0;
}
