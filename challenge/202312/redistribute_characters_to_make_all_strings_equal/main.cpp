#include <cassert>
#include <string>
#include <vector>

bool makeEqual(const std::vector<std::string> &words) {
    std::vector<size_t> freq(26, 0);
    for (const auto &word : words) {
        for (char c : word) {
            ++freq[c - 'a'];
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (freq[i] % words.size() != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::string> words{"abc", "aabc", "bc"};
        bool ret = makeEqual(words);
        assert(ret);
    }
    {
        std::vector<std::string> words{"ab", "a"};
        bool ret = makeEqual(words);
        assert(!ret);
    }
    return 0;
}
