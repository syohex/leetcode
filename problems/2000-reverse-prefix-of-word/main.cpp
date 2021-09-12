#include <cassert>
#include <string>
#include <algorithm>

std::string reversePrefix(std::string word, char ch) {
    size_t pos = word.find(ch);
    if (pos == std::string::npos) {
        return word;
    }

    int left = 0;
    int right = pos;
    while (left < right) {
        std::swap(word[left], word[right]);
        ++left;
        --right;
    }

    return word;
}

int main() {
    assert(reversePrefix("abcdefg", 'd') == "dcbaefg");
    assert(reversePrefix("xyxzxe", 'z') == "zxyxxe");
    assert(reversePrefix("abcd", 'z') == "abcd");
    return 0;
}