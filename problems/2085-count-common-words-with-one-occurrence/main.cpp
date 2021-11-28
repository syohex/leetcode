#include <cassert>
#include <vector>
#include <string>
#include <map>

int countWords(const std::vector<std::string> &words1, const std::vector<std::string> &words2) {
    std::map<std::string, int> m1, m2;
    for (const auto &word : words1) {
        ++m1[word];
    }
    for (const auto &word : words2) {
        ++m2[word];
    }

    int ret = 0;
    for (const auto &it1 : m1) {
        const auto &it2 = m2.find(it1.first);
        if (it2 == m2.end()) {
            continue;
        }

        if (it1.second == 1 && it2->second == 1) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words1{"leetcode",
                                        "is"
                                        "amazing",
                                        "as", "is"};
        std::vector<std::string> words2{"amazing", "leetcode", "is"};
        assert(countWords(words1, words2) == 2);
    }
    {
        std::vector<std::string> words1{"b", "bb", "bbb"};
        std::vector<std::string> words2{"a", "aa", "aaa"};
        assert(countWords(words1, words2) == 0);
    }
    {
        std::vector<std::string> words1{"a", "ab"};
        std::vector<std::string> words2{"a", "a", "a", "ab"};
        assert(countWords(words1, words2) == 1);
    }
    return 0;
}