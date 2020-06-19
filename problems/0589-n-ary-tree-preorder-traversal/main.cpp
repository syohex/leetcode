#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    explicit Node(int _val) {
        val = _val;
    }
    ~Node() {
        for (auto *p : children) {
            delete p;
        }
    }
};

std::vector<int> preorder(Node *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(Node *)> f;
    f = [&f, &ret](Node *node) {
        if (node->children.empty()) {
            ret.push_back(node->val);
            return;
        }

        ret.push_back(node->val);
        for (auto *child : node->children) {
            f(child);
        }
    };

    f(root);

    return ret;
}

int main() {
    {
        Node *tree = new Node(1);
        tree->children.push_back(new Node(2));
        tree->children.push_back(new Node(3));
        tree->children.push_back(new Node(4));
        tree->children.push_back(new Node(5));

        tree->children[1]->children.push_back(new Node(6));
        tree->children[1]->children.push_back(new Node(7));
        tree->children[1]->children[1]->children.push_back(new Node(11));
        tree->children[1]->children[1]->children[0]->children.push_back(new Node(14));

        tree->children[2]->children.push_back(new Node(8));
        tree->children[2]->children[0]->children.push_back(new Node(12));

        tree->children[3]->children.push_back(new Node(9));
        tree->children[3]->children.push_back(new Node(10));
        tree->children[3]->children[0]->children.push_back(new Node(13));

        auto ret = preorder(tree);
        std::vector<int> expected{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
        assert(ret == expected);
        delete tree;
    }
    return 0;
}
