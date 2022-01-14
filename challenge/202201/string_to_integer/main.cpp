#include <cassert>
#include <string>
#include <limits>
#include <cstdint>
#include <cstdio>

int myAtoi(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    size_t pos = 0;
    size_t limit = s.size();
    while (pos < limit && s[pos] == ' ') {
        ++pos;
    }

    if (pos >= limit) {
        return 0;
    }

    if (!((s[pos] >= '0' && s[pos] <= '9') || s[pos] == '+' || s[pos] == '-')) {
        return 0;
    }

    bool negative = false;
    if (s[pos] == '-') {
        negative = true;
        ++pos;
    } else if (s[pos] == '+') {
        ++pos;
    }

    std::int64_t val = 0;
    std::int64_t int_min = std::numeric_limits<int>::min();
    std::int64_t int_max = std::numeric_limits<int>::max();
    while (pos < limit && s[pos] >= '0' && s[pos] <= '9') {
        val = 10 * val + s[pos] - '0';
        if (negative) {
            if (-val <= int_min) {
                return int_min;
            }
        } else {
            if (val >= int_max) {
                return int_max;
            }
        }
        ++pos;
    }

    if (negative) {
        return -val;
    }

    return val;
}

int main() {
    assert(myAtoi("42") == 42);
    assert(myAtoi("    -42") == -42);
    assert(myAtoi("4193 with words") == 4193);
    assert(myAtoi("-91283472332") == -2147483647);
    return 0;
}
