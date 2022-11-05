#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <cstdio>

std::string oddString(const std::vector<std::string> &words) {
    std::map<std::vector<int>, std::vector<std::string>> m;
    for (const auto &word : words) {
        std::vector<int> tmp;
        for (size_t i = 1; i < word.size(); ++i) {
            tmp.push_back(word[i] - word[i - 1]);
        }

        m[tmp].push_back(word);
    }

    for (const auto &it : m) {
        if (it.second.size() == 1) {
            return it.second.front();
        }
    }

    return "";
}

int main() {
    {
        std::vector<std::string> words{"adc", "wzy", "abc"};
        auto ret = oddString(words);
        assert(ret == "abc");
    }
    {
        std::vector<std::string> words{"aaa", "bob", "ccc", "ddd"};
        auto ret = oddString(words);
        assert(ret == "bob");
    }
    return 0;
}
