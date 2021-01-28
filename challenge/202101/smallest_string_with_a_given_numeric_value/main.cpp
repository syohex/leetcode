#include <cassert>
#include <string>
#include <algorithm>

std::string getSmallestString(int n, int k) {
    std::string ret;
    while (k - n + 1 >= 26) {
        ret.push_back('z');
        k -= 26;
        --n;
    }

    if (k != 0) {
        ret.push_back('a' + (k - n));
        --n;

        for (int i = 0; i < n; ++i) {
            ret.push_back('a');
        }
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(getSmallestString(3, 27) == "aay");
    assert(getSmallestString(5, 73) == "aaszz");
    assert(getSmallestString(5, 130) == "zzzzz");
    return 0;
}
