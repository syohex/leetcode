#include <cassert>
#include <string>
#include <map>

bool canConstruct(const std::string &ransomNote, const std::string &magazine) {
    std::map<char, int> a, b;
    for (const char c : ransomNote) {
        ++a[c];
    }
    for (const char c : magazine) {
        ++b[c];
    }

    for (const auto &it : a) {
        if (b.find(it.first) == b.end()) {
            return false;
        }

        if (it.second > b[it.first]) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(!canConstruct("a", "b"));
    assert(!canConstruct("aa", "ab"));
    assert(canConstruct("aa", "aab"));
    return 0;
}
