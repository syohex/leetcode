#include <cassert>
#include <string>
#include <map>

bool canPermutePalindrome(const std::string &s) {
    std::map<char, int> m;
    for (char c : s) {
        ++m[c];
    }

    int odds = 0;
    for (const auto &it : m) {
        if (it.second % 2 != 0) {
            ++odds;
        }
    }

    if (s.size() % 2 == 0) {
        return odds == 0;
    }

    return odds == 1;
}

int main() {
    assert(!canPermutePalindrome("code"));
    assert(canPermutePalindrome("aab"));
    assert(canPermutePalindrome("carerac"));
    return 0;
}
