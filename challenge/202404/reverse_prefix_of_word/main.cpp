#include <cassert>
#include <string>
#include <algorithm>

std::string reversePrefix(std::string word, char ch) {
    const auto it = std::find(word.begin(), word.end(), ch);
    if (it == word.end()) {
        return word;
    }

    std::reverse(word.begin(), it + 1);
    return word;
}

int main() {
    assert(reversePrefix("abcdefd", 'd') == "dcbaefd");
    assert(reversePrefix("xyxzxe", 'z') == "zxyxxe");
    assert(reversePrefix("abcd", 'z') == "abcd");
    return 0;
}
