#include <cassert>
#include <string>
#include <map>
#include <queue>

class WordDictionary {
  public:
    struct TrieNode {
        std::map<char, TrieNode *> table_;
        bool end_;

        TrieNode() : end_(false) {
        }

        ~TrieNode() {
            for (auto it : table_) {
                delete it.second;
            }
        }
    };

    WordDictionary() : root_(new TrieNode()) {
    }

    void addWord(const std::string &word) {
        TrieNode *node = root_;
        for (char c : word) {
            if (node->table_.find(c) == node->table_.end()) {
                node->table_[c] = new TrieNode();
            }

            node = node->table_[c];
        }
        node->end_ = true;
    }

    bool search(const std::string &word) {
        struct Data {
            TrieNode *node;
            size_t pos;
        };

        std::deque<Data> q;
        q.push_back({root_, 0});

        while (!q.empty()) {
            Data d = q.front();
            q.pop_front();

            TrieNode *node = d.node;
            if (node->end_) {
                if (d.pos == word.size()) {
                    return true;
                }
            }

            char c = word[d.pos];
            if (c == '.') {
                for (auto it : node->table_) {
                    q.push_back({it.second, d.pos + 1});
                }
            } else {
                if (node->table_.find(c) != node->table_.end()) {
                    q.push_back({node->table_[c], d.pos + 1});
                }
            }
        }

        return false;
    }

    ~WordDictionary() {
        delete root_;
    }

    TrieNode *root_;
};

int main() {
    {
        WordDictionary w;
        w.addWord("bad");
        w.addWord("dad");
        w.addWord("mad");

        assert(!w.search("pad"));
        assert(w.search("bad"));
        assert(w.search(".ad"));
        assert(w.search("b.."));
        assert(!w.search("...."));
    }
    return 0;
}