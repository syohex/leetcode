#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

int minFlipMonoIncr(const std::string &s) {
    int len = s.size();
    std::vector<int> ones(len + 1, 0);
    std::vector<int> zeros(len + 1, 0);

    for (int i = 0; i < len; ++i) {
        ones[i + 1] = ones[i] + (s[i] == '1' ? 1 : 0);
    }

    for (int i = len - 1; i >= 0; --i) {
        zeros[i] = zeros[i + 1] + (s[i] == '0' ? 1 : 0);
    }

    int ret = INT_MAX;
    for (int i = 0; i <= len; ++i) {
        ret = std::min(ret, ones[i] + zeros[i]);
    }

    return ret;
}

int main() {
    assert(minFlipMonoIncr("00110") == 1);
    assert(minFlipMonoIncr("010110") == 2);
    assert(minFlipMonoIncr("00011000") == 2);
    assert(minFlipMonoIncr("00010000") == 1);
    assert(minFlipMonoIncr("11111") == 0);
    assert(minFlipMonoIncr("00000") == 0);
    return 0;
}
