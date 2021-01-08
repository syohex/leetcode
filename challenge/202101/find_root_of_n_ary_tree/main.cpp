#include <cassert>
#include <vector>
#include <set>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node(int _val) {
        val = _val;
    }

    ~Node() {
        for (auto *node : children) {
            delete node;
        }
    }
};

Node *findRoot(const std::vector<Node *> &tree) {
    std::set<Node *> s;
    for (auto *n : tree) {
        if (n != nullptr) {
            for (auto *child : n->children) {
                s.insert(child);
            }
        }
    }

    for (auto *n : tree) {
        if (s.find(n) == s.end()) {
            return n;
        }
    }

    assert(!"never reach here");
    return nullptr;
}

int main() {
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        Node *n7 = new Node(7);
        Node *n8 = new Node(8);
        Node *n9 = new Node(9);
        Node *n10 = new Node(10);
        Node *n11 = new Node(11);
        Node *n12 = new Node(12);
        Node *n13 = new Node(13);
        Node *n14 = new Node(14);

        n1->children = std::vector<Node *>{n2, n3, n4, n5};
        n3->children = std::vector<Node *>{n6, n7};
        n4->children = std::vector<Node *>{n8};
        n5->children = std::vector<Node *>{n9, n10};
        n7->children = std::vector<Node *>{n11};
        n8->children = std::vector<Node *>{n12};
        n9->children = std::vector<Node *>{n13};
        n11->children = std::vector<Node *>{n14};

        std::vector<Node *> input{n1, nullptr, n2,      n3,      n4,  n5,      nullptr, nullptr, n6,  n7,      nullptr, n8, nullptr,
                                  n9, n10,     nullptr, nullptr, n11, nullptr, n12,     nullptr, n13, nullptr, nullptr, n14};
        auto ret = findRoot(input);
        assert(ret == n1);
    }
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);

        n1->children = std::vector<Node *>{n3, n2, n4};
        n3->children = std::vector<Node *>{n5, n6};

        std::vector<Node *> input{n1, nullptr, n3, n2, n4, nullptr, n5, n6};

        auto ret = findRoot(input);
        assert(ret == n1);
    }
}
