#include <cassert>
#include <string>

std::string breakPalindrome(std::string &palindrome) {
    int len = palindrome.size();
    if (len <= 1) {
        return "";
    }

    if (len % 2 == 1) {
        int half = len / 2;
        for (int i = 0; i < len; ++i) {
            if (palindrome[i] != 'a') {
                if (i == half) {
                    for (int j = i + 1; j < len; ++j) {
                        if (palindrome[j] != 'a') {
                            palindrome[j] = 'a';
                            return palindrome;
                        }
                    }

                    palindrome.back() = 'b';
                    return palindrome;
                } else {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
        }
    } else {
        for (int i = 0; i < len; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
    }

    palindrome.back() = 'b';
    return palindrome;
}

int main() {
    {
        std::string str("abccba");
        assert(breakPalindrome(str) == "aaccba");
    }
    {
        std::string str("a");
        assert(breakPalindrome(str) == "");
    }
    {
        std::string str("aa");
        assert(breakPalindrome(str) == "ab");
    }
    {
        std::string str("aba");
        assert(breakPalindrome(str) == "abb");
    }
    {
        std::string str("aaa");
        assert(breakPalindrome(str) == "aab");
    }
    {
        std::string str("bab");
        assert(breakPalindrome(str) == "aab");
    }
    {
        std::string str("aabaa");
        assert(breakPalindrome(str) == "aabab");
    }
    return 0;
}