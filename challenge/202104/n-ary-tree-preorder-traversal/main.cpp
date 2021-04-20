#include <cassert>
#include <vector>
#include <functional>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }

    ~Node() {
        for (auto node : children) {
            delete node;
        }
    }
};

std::vector<int> preorder(Node *root) {
    std::vector<int> ret;
    std::function<void(Node * node)> f;
    f = [&f, &ret](Node *node) {
        if (node == nullptr) {
            return;
        }

        ret.push_back(node->val);
        for (auto *n : node->children) {
            f(n);
        }
    };

    f(root);
    return ret;
}

int main() {
    {
        Node *n1 = new Node(1);

        Node *n3 = new Node(3);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        n3->children.push_back(n5);
        n3->children.push_back(n6);

        Node *n2 = new Node(2);
        Node *n4 = new Node(4);

        n1->children.push_back(n3);
        n1->children.push_back(n2);
        n1->children.push_back(n4);

        auto ret = preorder(n1);
        std::vector<int> expected{1, 3, 5, 6, 2, 4};
        assert(ret == expected);
        delete n1;
    }
    {
        Node *n1 = new Node(1);

        Node *n2 = new Node(2);

        Node *n3 = new Node(3);
        Node *n6 = new Node(6);
        Node *n7 = new Node(7);
        Node *n11 = new Node(11);
        Node *n14 = new Node(14);
        n11->children.push_back(n14);
        n7->children.push_back(n11);
        n3->children.push_back(n6);
        n3->children.push_back(n7);

        Node *n4 = new Node(4);
        Node *n8 = new Node(8);
        Node *n12 = new Node(12);
        n8->children.push_back(n12);
        n4->children.push_back(n8);

        Node *n5 = new Node(5);
        Node *n9 = new Node(9);
        Node *n13 = new Node(13);
        n9->children.push_back(n13);
        Node *n10 = new Node(10);
        n5->children.push_back(n9);
        n5->children.push_back(n10);

        n1->children.push_back(n2);
        n1->children.push_back(n3);
        n1->children.push_back(n4);
        n1->children.push_back(n5);

        auto ret = preorder(n1);
        std::vector<int> expected{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
        assert(ret == expected);
        delete n1;
    }
    return 0;
}
