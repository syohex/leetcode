#include <cassert>
#include <vector>
#include <string>

int vowelStrings(const std::vector<std::string> &words, int left, int right) {
    const auto check = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };

    int ret = 0;
    for (int i = left; i <= right; ++i) {
        if (check(words[i].front()) && check(words[i].back())) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"are", "amy", "u"};
        int ret = vowelStrings(words, 0, 2);
        assert(ret == 2);
    }
    {
        std::vector<std::string> words{"hey", "aeo", "mu", "ooo", "artro"};
        int ret = vowelStrings(words, 1, 4);
        assert(ret == 3);
    }
    return 0;
}
