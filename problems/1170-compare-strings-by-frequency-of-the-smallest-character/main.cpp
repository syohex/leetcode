#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

std::vector<int> numSamllerByFrequency(const std::vector<std::string> &queries, const std::vector<std::string> &words) {
    std::vector<int> queryNum;
    std::map<char, int> m;
    for (const auto &query : queries) {
        for (char c : query) {
            ++m[c];
        }

        queryNum.push_back(m.begin()->second);
        m.clear();
    }

    std::vector<int> wordNum;
    for (const auto &word : words) {
        for (char c : word) {
            ++m[c];
        }

        wordNum.push_back(m.begin()->second);
        m.clear();
    }

    std::sort(wordNum.begin(), wordNum.end());

    std::vector<int> ret;
    int limit = static_cast<int>(wordNum.size());
    for (int n : queryNum) {
        ret.push_back(0);
        for (size_t i = 0; i < limit; ++i) {
            if (n < wordNum[i]) {
                ret.back() = limit - i;
                break;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> queries{"cbd"};
        std::vector<std::string> words{"zaaaaz"};
        auto ret = numSamllerByFrequency(queries, words);
        assert((ret == std::vector<int>{1}));
    }
    {
        std::vector<std::string> queries{"bbb", "cc"};
        std::vector<std::string> words{"a", "aa", "aaa", "aaaa"};
        auto ret = numSamllerByFrequency(queries, words);
        assert((ret == std::vector<int>{1, 2}));
    }
    return 0;
}
