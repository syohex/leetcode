#include <cassert>
#include <string>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstdint>

std::string toHex(int num) {
    uint32_t n;
    if (num >= 0) {
        n = num;
    } else {
        std::int64_t nn = num;
        n = ~static_cast<uint32_t>(-nn);
        n += 1;
    }

    std::string ret;
    while (true) {
        int mod = n % 16;
        if (mod >= 10) {
            ret.push_back(mod - 10 + 'a');
        } else {
            ret.push_back(mod + '0');
        }
        n /= 16;
        if (n == 0) {
            break;
        }
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(toHex(26) == "1a");
    assert(toHex(-1) == "ffffffff");
    return 0;
}
