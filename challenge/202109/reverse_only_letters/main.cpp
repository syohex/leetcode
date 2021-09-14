#include <cassert>
#include <string>
#include <cctype>
#include <algorithm>

std::string reverseOnlyLetters(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        while (left < right && !std::isalpha(s[left])) {
            ++left;
        }

        while (left < right && !std::isalpha(s[right])) {
            --right;
        }

        if (left < right) {
            std::swap(s[left], s[right]);
        }
        ++left;
        --right;
    }

    return s;
}

int main() {
    assert(reverseOnlyLetters("ab-cd") == "dc-ba");
    assert(reverseOnlyLetters("a-bC-dEf-ghIj") == "j-Ih-gfE-dCba");
    assert(reverseOnlyLetters("Test1ng-Leet=code-Q!") == "Qedo1ct-eeLg=ntse-T!");
    return 0;
}