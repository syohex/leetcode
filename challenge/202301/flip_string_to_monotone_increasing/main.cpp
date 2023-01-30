#include <cassert>
#include <string>
#include <algorithm>

int minFlips(const std::string &s) {
    int len = s.size();
    std::vector<int> ones(len + 1, 0);
    std::vector<int> zeros(len + 1, 0);

    for (int i = 0; i < len; ++i) {
        ones[i + 1] = ones[i] + (s[i] == '1' ? 1 : 0);
    }

    for (int i = len - 1; i >= 0; --i) {
        zeros[i] = zeros[i + 1] + (s[i] == '0' ? 1 : 0);
    }

    int ret = len + 1;
    for (int i = 0; i <= len; ++i) {
        ret = std::min(ret, ones[i] + zeros[i]);
    }

    return ret;
}

int main() {
    assert(minFlips("00110") == 1);
    assert(minFlips("010110") == 2);
    assert(minFlips("00011000") == 2);
    assert(minFlips("10011111110010111011") == 5);
    return 0;
}
