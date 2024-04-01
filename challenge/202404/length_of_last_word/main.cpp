#include <cassert>
#include <string>
#include <cstdio>

int lengthOfLastWord(const std::string &s) {
    int len = s.size();
    int end = len - 1;
    while (s[end] == ' ') {
        --end;
    }

    int start = end;
    while (start >= 0) {
        if (s[start] == ' ') {
            break;
        }
        --start;
    }

    return end - start;
}

int main() {
    assert(lengthOfLastWord("Hello World") == 5);
    assert(lengthOfLastWord("    fly me   to the   moon   ") == 4);
    assert(lengthOfLastWord("luffy is still joyboy") == 6);
    assert(lengthOfLastWord("apple") == 5);
    assert(lengthOfLastWord("  apple  ") == 5);
    return 0;
}
