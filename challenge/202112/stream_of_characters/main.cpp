#include <cassert>
#include <string>
#include <vector>

class StreamChecker {
  public:
    struct TrieNode {
        std::vector<TrieNode *> table;
        bool end;

        TrieNode() : table(std::vector<TrieNode *>(26, nullptr)), end(false) {
        }

        ~TrieNode() {
            for (auto *t : table) {
                delete t;
            }
        }
    };

    StreamChecker(const std::vector<std::string> &words) {
        for (const auto &word : words) {
            TrieNode *node = &root_;
            for (auto it = word.rbegin(); it != word.rend(); ++it) {
                int index = *it - 'a';
                if (node->table[index] == nullptr) {
                    node->table[index] = new TrieNode();
                }

                node = node->table[index];
            }

            node->end = true;
        }
    }

    bool query(char letter) {
        stream_.push_back(letter);

        TrieNode *node = &root_;
        for (auto it = stream_.rbegin(); it != stream_.rend(); ++it) {
            int index = *it - 'a';
            if (node->table[index] == nullptr) {
                return false;
            }

            node = node->table[index];
            if (node->end) {
                return true;
            }
        }

        return false;
    }

    TrieNode root_;
    std::string stream_;
};

int main() {
    {
        StreamChecker s({"cd", "f", "kl"});
        assert(!s.query('a'));
        assert(!s.query('b'));
        assert(!s.query('c'));
        assert(s.query('d'));
        assert(!s.query('e'));
        assert(s.query('f'));
        assert(!s.query('g'));
        assert(!s.query('h'));
        assert(!s.query('i'));
        assert(!s.query('j'));
        assert(!s.query('k'));
        assert(s.query('l'));
    }
    return 0;
}