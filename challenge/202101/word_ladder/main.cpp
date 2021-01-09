#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <climits>

int ladderLength(const std::string &beginWord, const std::string &endWord, const std::vector<std::string> &wordList) {
    const auto can_move = [](const std::string &a, const std::string &b) -> bool {
        int diff = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
                if (diff >= 2) {
                    return false;
                }
            }
        }

        return diff == 1;
    };

    std::map<std::string, std::vector<std::string>> table;
    for (size_t i = 0; i < wordList.size(); ++i) {
        for (size_t j = 0; j < wordList.size(); ++j) {
            if (i == j) {
                continue;
            }

            if (can_move(wordList[i], wordList[j])) {
                table[wordList[i]].push_back(wordList[j]);
            }
        }
    }

    for (size_t i = 0; i < wordList.size(); ++i) {
        if (can_move(beginWord, wordList[i])) {
            table[beginWord].push_back(wordList[i]);
        }
    }

    std::function<int(int count, const std::vector<std::string> &ws, std::set<std::string> &checked)> f;
    f = [&f, &table, &endWord](int count, const std::vector<std::string> &ws, std::set<std::string> &checked) -> int {
        int ret = INT_MAX;
        for (size_t i = 0; i < ws.size(); ++i) {
            if (checked.find(ws[i]) != checked.end()) {
                continue;
            }

            if (ws[i] == endWord) {
                ret = std::min(ret, count);
            } else {
                checked.insert(ws[i]);
                ret = std::min(ret, f(count + 1, table[ws[i]], checked));
                checked.erase(ws[i]);
            }

            if (ret == count) {
                return ret;
            }
        }

        return ret;
    };

    std::set<std::string> checked{beginWord};
    int ret = f(2, table[beginWord], checked);
    return ret == INT_MAX ? 0 : ret;
}

int main() {
    {
        std::vector<std::string> word_list{"hot", "dot", "dog", "lot", "log", "cog"};
        assert(ladderLength("hit", "cog", word_list) == 5);
    }
    {
        std::vector<std::string> word_list{"hot", "dot", "dog", "lot", "log"};
        assert(ladderLength("hit", "cog", word_list) == 0);
    }
    {
        std::vector<std::string> word_list{"hot", "dog"};
        assert(ladderLength("hot", "dog", word_list) == 0);
    }
    {
        std::vector<std::string> word_list{"hot", "dog", "dot"};
        assert(ladderLength("hot", "dog", word_list) == 3);
    }
    {
        std::vector<std::string> word_list{"a", "b", "c"};
        assert(ladderLength("a", "c", word_list) == 2);
    }
    return 0;
}
