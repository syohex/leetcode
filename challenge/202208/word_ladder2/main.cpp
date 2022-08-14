#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <cstdio>

std::vector<std::vector<std::string>> findLadders(const std::string &beginWord, const std::string &endWord,
                                                  const std::vector<std::string> &wordList) {
    if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
        return {};
    }

    std::map<size_t, std::vector<std::vector<std::string>>> m;
    size_t word_len = beginWord.size();
    size_t len = wordList.size();
    size_t min = len + 1;

    std::function<void(const std::string &word, std::vector<bool> &checked, std::vector<std::string> &acc)> f;
    f = [&](const std::string &word, std::vector<bool> &checked, std::vector<std::string> &acc) {
        if (word == endWord) {
            m[acc.size()].push_back(acc);
            min = std::min(min, acc.size());
            return;
        }

        std::string tmp1, tmp2;
        for (size_t i = 0; i < word_len; ++i) {
            tmp1 = word;
            tmp1[i] = '?';
            for (size_t j = 0; j < len; ++j) {
                if (checked[j]) {
                    continue;
                }

                tmp2 = wordList[j];
                tmp2[i] = '?';

                if (tmp1 == tmp2) {
                    checked[j] = true;
                    acc.push_back(wordList[j]);

                    f(wordList[j], checked, acc);

                    acc.pop_back();
                    checked[j] = false;
                }
            }
        }
    };

    std::vector<bool> checked(len, false);
    std::vector<std::string> acc{beginWord};

    f(beginWord, checked, acc);

    return m[min];
}

int main() {
    {
        std::string beginWord = "hit";
        std::string endWord = "cog";
        std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};

        std::vector<std::vector<std::string>> expected{
            {"hit", "hot", "dot", "dog", "cog"},
            {"hit", "hot", "lot", "log", "cog"},
        };
        auto ret = findLadders(beginWord, endWord, wordList);
        assert(ret == expected);
    }
    {
        std::string beginWord = "hit";
        std::string endWord = "cog";
        std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log"};

        auto ret = findLadders(beginWord, endWord, wordList);
        assert(ret.empty());
    }
    return 0;
}
