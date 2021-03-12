#include <cassert>
#include <string>
#include <cmath>

bool hasAllCodes(const std::string &s, int k) {
    const auto f = [](std::string &str, int n, int k) {
        unsigned int mask = 1;
        for (int i = 0; i < k; ++i) {
            size_t index = str.size() - 1 - i;
            str[index] = ((n & mask) != 0) ? '1' : '0';
            mask <<= 1;
        }
    };

    std::string digits(k, 0);
    int limit = std::pow(2, k);
    for (int i = 0; i < limit; ++i) {
        f(digits, i, k);
        if (s.find(digits) == std::string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(hasAllCodes("00110110", 2));
    assert(hasAllCodes("00110", 2));
    assert(hasAllCodes("0110", 1));
    assert(!hasAllCodes("0110", 2));
    assert(!hasAllCodes("0000000001011100", 4));
    return 0;
}
