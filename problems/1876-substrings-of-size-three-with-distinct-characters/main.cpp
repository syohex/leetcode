#include <cassert>
#include <string>

int countGoodSubstrings(const std::string &s) {
    if (s.size() < 3) {
        return 0;
    }

    int table[26] = {};
    const auto f = [&table]() -> int {
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (table[i] != 0) {
                ++ret;
            }
        }

        return ret;
    };

    ++table[s[0] - 'a'];
    ++table[s[1] - 'a'];
    ++table[s[2] - 'a'];

    int ret = f() == 3 ? 1 : 0;
    for (size_t i = 3; i < s.size(); ++i) {
        --table[s[i - 3] - 'a'];
        ++table[s[i] - 'a'];

        if (f() == 3) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(countGoodSubstrings("xyzzaz") == 1);
    assert(countGoodSubstrings("aababcabc") == 4);
    return 0;
}