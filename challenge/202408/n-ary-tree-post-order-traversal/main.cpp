#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

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

std::vector<int> postorder(Node *root) {
    std::function<void(Node * node, std::vector<int> & acc)> f;
    f = [&](Node *node, std::vector<int> &acc) {
        if (node == nullptr) {
            return;
        }

        for (Node *next : node->children) {
            f(next, acc);
        }
        acc.push_back(node->val);
    };

    std::vector<int> acc;
    f(root, acc);
    return acc;
}

int main() {
    {
        Node *r = new Node(1);
        r->children.push_back(new Node(3));
        r->children.push_back(new Node(2));
        r->children.push_back(new Node(4));

        r->children[0]->children.push_back(new Node(5));
        r->children[0]->children.push_back(new Node(6));

        std::vector<int> expected{5, 6, 3, 2, 4, 1};
        auto ret = postorder(r);
        assert(ret == expected);
        delete r;
    }
    {
        Node *r = new Node(1);
        r->children.push_back(new Node(2));
        r->children.push_back(new Node(3));
        r->children.push_back(new Node(4));
        r->children.push_back(new Node(5));

        r->children[1]->children.push_back(new Node(6));
        r->children[1]->children.push_back(new Node(7));
        r->children[2]->children.push_back(new Node(8));
        r->children[3]->children.push_back(new Node(9));
        r->children[3]->children.push_back(new Node(10));

        r->children[1]->children[1]->children.push_back(new Node(11));
        r->children[2]->children[0]->children.push_back(new Node(12));
        r->children[3]->children[0]->children.push_back(new Node(13));

        r->children[1]->children[1]->children[0]->children.push_back(new Node(14));

        std::vector<int> expected{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
        auto ret = postorder(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}
