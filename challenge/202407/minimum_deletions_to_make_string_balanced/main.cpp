#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int minimumDeletions(const std::string &s) {
    int len = s.size();
    std::vector<int> vb(len, 0);
    int count_b = 0;
    for (int i = 0; i < len; ++i) {
        vb[i] = count_b;
        if (s[i] == 'b') {
            ++count_b;
        }
    }

    std::vector<int> va(len, 0);
    int count_a = 0;
    for (int i = len - 1; i >= 0; --i) {
        va[i] = count_a;
        if (s[i] == 'a') {
            ++count_a;
        }
    }

    int ret = len;
    for (std::size_t i = 0; i < s.size(); ++i) {
        ret = std::min(ret, va[i] + vb[i]);
    }
    return ret;
}

int main() {
    assert(minimumDeletions("aababbab") == 2);
    assert(minimumDeletions("bbaaaaabb") == 2);
    return 0;
}