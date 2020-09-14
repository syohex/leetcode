#include <cassert>
#include <string>
#include <cctype>
#include <cstdio>

int countSegments(const std::string &s) {
    int ret = 0;
    size_t i = 0;
    while (i < s.size()) {
        if (isspace(static_cast<int>(s[i]))) {
            ++i;
            continue;
        }

        break;
    }

    while (i < s.size()) {
        while (i < s.size()) {
            if (!isspace(static_cast<int>(s[i]))) {
                ++i;
                continue;
            }

            break;
        }

        ++ret;

        while (i < s.size()) {
            if (isspace(static_cast<int>(s[i]))) {
                ++i;
                continue;
            }

            break;
        }
    }

    return ret;
}

int main() {
    assert(countSegments("Hello, my name is John") == 5);
    assert(countSegments("Hello") == 1);
    assert(countSegments("love live! mu'sic forever") == 4);
    assert(countSegments(" hello world  ") == 2);
    assert(countSegments("") == 0);
    return 0;
}
