#include <cassert>
#include <string>
#include <cstdio>

int lengthOfLastWord(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    int limit = static_cast<int>(s.size() - 1);
    int end = limit;
    while (s[end] == ' ') {
        if (end == 0) {
            return 0;
        }

        --end;
    }

    if (end == 0) {
        return 1;
    }

    int start = end - 1;
    while (s[start] != ' ') {
        if (start == 0) {
            return end + 1;
        }

        --start;
    }

    ++start;
    return end - start + 1;
}

int main() {
    assert(lengthOfLastWord("Hello World") == 5);
    assert(lengthOfLastWord("World") == 5);
    assert(lengthOfLastWord("World    ") == 5);
    assert(lengthOfLastWord("") == 0);
    assert(lengthOfLastWord("     ") == 0);
    assert(lengthOfLastWord("a") == 1);
    return 0;
}
