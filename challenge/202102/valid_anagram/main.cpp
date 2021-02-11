#include <cassert>
#include <string>
#include <map>

bool isAnagram(const std::string &s, const std::string &t) {
    std::map<char, int> sm, tm;
    for (char c : s) {
        ++sm[c];
    }
    for (char c : t) {
        ++tm[c];
    }

    return sm == tm;
}

int main() {
    assert(isAnagram("anagram", "nagaram"));
    assert(!isAnagram("rat", "car"));
    return 0;
}
