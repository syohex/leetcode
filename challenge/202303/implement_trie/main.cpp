#include <cassert>
#include <string>
#include <memory>
#include <vector>

class Trie {
  public:
    struct Node {
        Node() : table(26, nullptr), end(false) {
        }
        ~Node() {
            for (Node *n : table) {
                delete n;
            }
        }
        std::vector<Node *> table;
        bool end;
    };

    Trie() : root_(new Node()) {
    }

    ~Trie() {
        delete root_;
    }

    void insert(const std::string &word) {
        Node *p = root_;
        for (char c : word) {
            int index = c - 'a';
            if (p->table[index] == nullptr) {
                p->table[index] = new Node();
            }

            p = p->table[index];
        }

        p->end = true;
    }

    bool search(const std::string &word) {
        Node *p = root_;
        for (char c : word) {
            int index = c - 'a';
            if (p->table[index] == nullptr) {
                return false;
            }

            p = p->table[index];
        }

        return p->end;
    }

    bool startsWith(const std::string &prefix) {
        Node *p = root_;
        for (char c : prefix) {
            int index = c - 'a';
            if (p->table[index] == nullptr) {
                return false;
            }

            p = p->table[index];
        }

        return true;
    }

    Node *root_;
};

int main() {
    {
        Trie t;
        t.insert("apple");
        assert(t.search("apple"));
        assert(!t.search("app"));
        assert(t.startsWith("app"));
        t.insert("app");
        assert(t.search("app"));
    }
    return 0;
}
