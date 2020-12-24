#include <cassert>
#include <cstdint>
#include <string>

int titleToNumber(const std::string &s) {
    std::int64_t start = static_cast<int>(s.size()) - 1;
    std::int64_t mul = 1;
    std::int64_t ret = 0;
    for (int i = start; i >= 0; --i) {
        std::int64_t val = s[i] - 'A' + 1;
        ret = val * mul + ret;
        mul *= 26;
    }

    return static_cast<int>(ret);
}

int main() {
    assert(titleToNumber("A") == 1);
    assert(titleToNumber("Z") == 26);
    assert(titleToNumber("AB") == 28);
    assert(titleToNumber("ZY") == 701);
    assert(titleToNumber("AAA") == 703);
    return 0;
}
