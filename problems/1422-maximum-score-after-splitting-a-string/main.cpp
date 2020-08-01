#include <cassert>
#include <string>

int maxScore(const std::string &s) {
    int max = 0;
    int limit = static_cast<int>(s.size());
    for (int i = 1; i < limit; ++i) {
        int left = 0;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '0') {
                ++left;
            }
        }

        int right = 0;
        for (int j = i; j < limit; ++j) {
            if (s[j] == '1') {
                ++right;
            }
        }

        if (left + right > max) {
            max = left + right;
            if (max == limit) {
                return max;
            }
        }
    }
    return max;
}

int main() {
    assert(maxScore("011101") == 5);
    assert(maxScore("00111") == 5);
    assert(maxScore("1111") == 3);
    return 0;
}
