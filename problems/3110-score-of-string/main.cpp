#include <cassert>
#include <string>
#include <cmath>

int scoreOfString(const std::string &s) {
    int ret = 0;
    for (size_t i = 1; i < s.size(); ++i) {
        ret += std::abs(s[i - 1] - s[i]);
    }
    return ret;
}

int main() {
    assert(scoreOfString("hello") == 13);
    assert(scoreOfString("zaz") == 50);
    return 0;
}
