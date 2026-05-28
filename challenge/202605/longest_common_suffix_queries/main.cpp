#include <cassert>
#include <limits>
#include <vector>
#include <string>
#include <limits>

using namespace std;

vector<int> stringIndices(const vector<string> &wordsContainer, const vector<string> &wordsQuery) {
    struct Trie {
        int min_index;
        int min_len = numeric_limits<int>::max();
        Trie *table[26] = {};

        ~Trie() {
            for (int i = 0; i < 26; ++i) {
                delete table[i];
            }
        }

        void insert(int pos, const string &word, int index) {
            if (pos < 0) {
                return;
            }

            int word_index = word[pos] - 'a';
            Trie *node = table[word_index];
            if (node == nullptr) {
                node = new Trie();
                table[word_index] = node;
            }

            node->insert(pos - 1, word, index);

            int len = word.size();
            if (len < node->min_len) {
                node->min_index = index;
                node->min_len = len;
            }
        }

        int findLongestSuffix(int pos, const string &word) const {
            if (pos < 0) {
                return -1;
            }

            int word_index = word[pos] - 'a';
            Trie *node = table[word_index];
            if (node == nullptr) {
                return min_index;
            }

            int ret = node->findLongestSuffix(pos - 1, word);
            return ret == -1 ? node->min_index : ret;
        }
    };

    Trie root;
    int i = 0;
    for (const auto &word : wordsContainer) {
        int len = word.size();
        root.insert(len - 1, word, i);
        if (len < root.min_len) {
            root.min_len = len;
            root.min_index = i;
        }
        ++i;
    }

    vector<int> ret;
    for (const auto &word : wordsQuery) {
        int index = root.findLongestSuffix(word.size() - 1, word);
        ret.push_back(index);


    return ret;
}

int main() {
    {
        vector<string> wordsContainer{"a", "b"};
        vector<string> wordsQuery{"a", "b"};
        vector<int> expected{0, 1};
        auto ret = stringIndices(wordsContainer, wordsQuery);
        assert(ret == expected);
    }
    {
        vector<string> wordsContainer{"abcd", "bcd", "xbcd"};
        vector<string> wordsQuery{"cd", "bcd", "xyz"};
        vector<int> expected{1, 1, 1};
        auto ret = stringIndices(wordsContainer, wordsQuery);
        assert(ret == expected);
    }
    {
        vector<string> wordsContainer{"abcdefgh", "poiuygh", "ghghgh"};
        vector<string> wordsQuery{"gh", "acbfgh", "acbfegh"};
        vector<int> expected{2, 0, 2};
        auto ret = stringIndices(wordsContainer, wordsQuery);
        assert(ret == expected);
    }
    return 0;
}
