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

std::vector<int> postorder(Node *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(Node * node)> f;
    f = [&f, &ret](Node *node) {
        if (node->children.empty()) {
            ret.push_back(node->val);
            return;
        }

        for (auto *child : node->children) {
            f(child);
        }
        ret.push_back(node->val);
    };

    f(root);

    return ret;
}

int main() {
    {
        Node *root = new Node(1);
        root->children.push_back(new Node(3));
        root->children.push_back(new Node(2));
        root->children.push_back(new Node(4));

        root->children[0]->children.push_back(new Node(5));
        root->children[0]->children.push_back(new Node(6));

        auto ret = postorder(root);
        std::vector<int> expected{5, 6, 3, 2, 4, 1};
        assert(ret == expected);
        delete root;
    }
    {
        Node *root = new Node(1);
        root->children.push_back(new Node(2));
        root->children.push_back(new Node(3));
        root->children.push_back(new Node(4));
        root->children.push_back(new Node(5));

        root->children[1]->children.push_back(new Node(6));
        root->children[1]->children.push_back(new Node(7));
        root->children[1]->children[1]->children.push_back(new Node(11));
        root->children[1]->children[1]->children[0]->children.push_back(new Node(14));

        root->children[2]->children.push_back(new Node(8));
        root->children[2]->children[0]->children.push_back(new Node(12));

        root->children[3]->children.push_back(new Node(9));
        root->children[3]->children.push_back(new Node(10));
        root->children[3]->children[0]->children.push_back(new Node(13));

        auto ret = postorder(root);
        std::vector<int> expected{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
        assert(ret == expected);
        delete root;
    }
    return 0;
}
