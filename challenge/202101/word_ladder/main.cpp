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

    std::map<std::string, int> distance{
        {beginWord, 0},
    };
    for (size_t i = 0; i < wordList.size(); ++i) {
        if (can_move(beginWord, wordList[i])) {
            table[beginWord].push_back(wordList[i]);
        }
        distance[wordList[i]] = INT_MAX;
    }

    std::function<int(int count, const std::vector<std::string> &ws)> f;
    f = [&f, &table, &endWord, &distance](int count, const std::vector<std::string> &ws) -> int {
        int ret = INT_MAX;
        for (size_t i = 0; i < ws.size(); ++i) {
            if (distance[ws[i]] <= count) {
                continue;
            }

            distance[ws[i]] = count;

            if (ws[i] == endWord) {
                return count;
            }

            ret = std::min(ret, f(count + 1, table[ws[i]]));
        }

        return ret;
    };

    int ret = f(2, table[beginWord]);
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
