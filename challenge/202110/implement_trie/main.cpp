#include <cassert>
#include <vector>
#include <string>

struct Node {
    Node() : links_(26, nullptr), leaf_(false) {
    }

    bool contains(char c) const {
        return links_[c - 'a'] != nullptr;
    }

    void put(char c) {
        links_[c - 'a'] = new Node();
    }

    Node *get(char c) const {
        return links_[c - 'a'];
    }

    void setLeaf() {
        leaf_ = true;
    }

    bool isLeaf() const {
        return leaf_;
    }

    std::vector<Node *> links_;
    bool leaf_;
};

class Trie {
  public:
    Trie() : root_(new Node()) {
    }

    void insert(const std::string &word) {
        Node *n = root_;
        for (char c : word) {
            if (!n->contains(c)) {
                n->put(c);
            }

            n = n->get(c);
        }

        n->setLeaf();
    }

    bool search(const std::string &word) {
        Node *n = root_;
        for (char c : word) {
            if (n->contains(c)) {
                n = n->get(c);
            } else {
                return false;
            }
        }

        return n != nullptr && n->isLeaf();
    }

    bool startsWith(const std::string &prefix) {
        Node *n = root_;
        for (char c : prefix) {
            if (n->contains(c)) {
                n = n->get(c);
            } else {
                return false;
            }
        }

        return n != nullptr;
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