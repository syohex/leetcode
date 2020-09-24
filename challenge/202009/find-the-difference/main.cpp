#include <cassert>
#include <string>
#include <map>

char findTheDifference(const std::string &s, const std::string &t) {
    std::map<char, int> ms, mt;
    for (size_t i = 0; i < s.size(); ++i) {
        ++ms[s[i]];
        ++mt[t[i]];
    }
    ++mt[t.back()];

    for (const auto it : mt) {
        if (it.second - ms[it.first] != 0) {
            return it.first;
        }
    }

    return 0;
}

int main() {
    assert(findTheDifference("abcd", "abcde") == 'e');
    assert(findTheDifference("abc", "abcd") == 'd');
    assert(findTheDifference("", "a") == 'a');
    return 0;
}
