#include <cassert>
#include <string>
#include <vector>

std::string reverseWords(const std::string &s) {
    std::vector<std::string> v;
    size_t pos = 0;
    size_t limit = s.size();

    while (pos < limit) {
        while (pos < limit && s[pos] == ' ') {
            ++pos;
        }

        if (pos >= limit) {
            break;
        }

        std::string tmp;
        while (pos < limit && s[pos] != ' ') {
            tmp += s[pos];
            ++pos;
        }

        v.push_back(tmp);
    }

    std::string ret;
    int len = v.size();
    for (int i = len - 1; i >= 0; --i) {
        ret += v[i];
        if (i != 0) {
            ret += ' ';
        }
    }

    return ret;
}

int main() {
    assert(reverseWords("apple") == "apple");
    assert(reverseWords("the sky is blue") == "blue is sky the");
    assert(reverseWords("a good    example") == "example good a");
    assert(reverseWords("  Bob     Loves Alice") == "Alice Loves Bob");
    assert(reverseWords("Alice does not even like bob") == "bob like even not does Alice");
    return 0;
}