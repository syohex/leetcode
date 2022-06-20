#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int minimumLengthEncoding(std::vector<std::string> &words) {
    struct Trie {
        std::vector<Trie *> table;
        bool end;

        Trie() : table(26, nullptr), end(false) {
        }
        ~Trie() {
            for (auto *p : table) {
                delete p;
            }
        }
    };

    std::set<std::string> s(words.begin(), words.end());
    words.clear();

    for (const auto &word : s) {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });

    Trie trie;
    for (const auto &word : words) {
        Trie *cur = &trie;
        for (auto it = word.rbegin(); it != word.rend(); ++it) {
            char c = *it;
            size_t index = c - 'a';

            if (cur->table[index] == nullptr) {
                cur->table[index] = new Trie();
            }

            cur = cur->table[index];
            cur->end = false;
        }

        cur->end = true;
    }

    int ret = 0;
    for (const auto &word : words) {
        Trie *cur = &trie;
        for (auto it = word.rbegin(); it != word.rend(); ++it) {
            cur = cur->table[*it - 'a'];
        }

        if (cur->end) {
            ret += word.size() + 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"time", "me", "bell"};
        int ret = minimumLengthEncoding(words);
        assert(ret == 10);
    }
    {
        std::vector<std::string> words{"time", "me", "bell"};
        int ret = minimumLengthEncoding(words);
        assert(ret == 10);
    }
    {
        std::vector<std::string> words{"time", "time", "time", "time"};
        int ret = minimumLengthEncoding(words);
        assert(ret == 5);
    }
    return 0;
}
