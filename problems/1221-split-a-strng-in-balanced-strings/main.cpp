#include <cassert>
#include <string>
#include <vector>

int balancedStringSplit(const std::string &s) {
    std::vector<char> v;

    int ret = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        const char c = s[i];
        if (v.empty()) {
            v.push_back(c);
            continue;
        }

        const char d = c == 'L' ? 'R' : 'L';
        bool found = false;
        for (int j = static_cast<int>(v.size()) - 1, pair = 0; j >= 0; --j) {
            if (v[j] == d) {
                if (pair == 0 && j == 0) {
                    v.resize(0);
                    found = true;
                    ++ret;
                    break;
                }
                --pair;
            } else if (v[j] == c) {
                ++pair;
            }
        }

        if (!found) {
            v.push_back(c);
        }
    }

    if (!v.empty()) {
        int left = 0;
        int right = 0;
        for (const auto c : v) {
            if (c == 'L') {
                ++left;
            } else {
                ++right;
            }
        }

        if (left == right) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(balancedStringSplit("RLRRLLRLLRL") == 4);
    assert(balancedStringSplit("RLLLRRRLR") == 3);
    assert(balancedStringSplit("LLLLRRRR") == 1);
    assert(balancedStringSplit("RLRRRLLRLL") == 2);
    return 0;
}
