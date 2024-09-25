#include <cassert>
#include <vector>
#include <string>

std::vector<int> sumPrefixScores(const std::vector<std::string> &words) {
    struct Trie {
        struct TrieNode {
            TrieNode *table[26]{};
            int score = 0;

            ~TrieNode() {
                for (auto *p : table) {
                    delete p;
                }
            }
        };

        TrieNode root;

        void insert(const std::string &s) {
            TrieNode *p = &root;
            for (char c : s) {
                int key = c - 'a';
                if (p->table[key] == nullptr) {
                    p->table[key] = new TrieNode();
                }

                p->table[key]->score += 1;
                p = p->table[key];
            }
        }

        int count_score(const std::string &s) {
            TrieNode *p = &root;
            int score = 0;
            for (char c : s) {
                int key = c - 'a';
                if (p->table[key] == nullptr) {
                    break;
                }

                score += p->table[key]->score;
                p = p->table[key];
            }

            return score;
        }
    };

    Trie t;
    for (const auto &word : words) {
        t.insert(word);
    }

    std::vector<int> ret;
    for (const auto &word : words) {
        ret.push_back(t.count_score(word));
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"abc", "ab", "bc", "b"};
        std::vector<int> expected{5, 4, 3, 2};
        auto ret = sumPrefixScores(words);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"abcd"};
        std::vector<int> expected{4};
        auto ret = sumPrefixScores(words);
        assert(ret == expected);
    }
    return 0;
}