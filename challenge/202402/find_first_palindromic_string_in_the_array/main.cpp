#include <cassert>
#include <string>
#include <vector>

std::string firstPalindrome(const std::vector<std::string> &words) {
    for (const auto &word : words) {
        size_t len = word.size();
        size_t half = len / 2;
        bool ok = true;
        for (size_t i = 0; i <= half; ++i) {
            if (word[i] != word[len - 1 - i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return word;
        }
    }
    return "";
}

int main() {
    {
        std::vector<std::string> words{"abc", "car", "ada", "racecar", "cool"};
        auto ret = firstPalindrome(words);
        assert(ret == "ada");
    }
    {
        std::vector<std::string> words{"notapalindrome", "racecar"};
        auto ret = firstPalindrome(words);
        assert(ret == "racecar");
    }
    {
        std::vector<std::string> words{"def", "ghi"};
        auto ret = firstPalindrome(words);
        assert(ret == "");
    }
    return 0;
}
