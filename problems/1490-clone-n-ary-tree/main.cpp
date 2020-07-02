#include <cassert>
#include <vector>
#include <functional>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    explicit Node(int _val) {
        val = _val;
    }

    ~Node() {
        for (auto *node : children) {
            delete node;
        }
    }

    bool Equal(Node *other, int depth = 0) {
        if (this == other) {
            return false;
        }

        if (children.size() != other->children.size()) {
            return false;
        }

        for (size_t i = 0; i < children.size(); ++i) {
            if (!children[i]->Equal(other->children[i], depth + 1)) {
                return false;
            }
        }

        return true;
    }
};

Node *cloneTree(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node *ret;
    std::function<void(Node * node, Node * *v)> f;
    f = [&f](Node *node, Node **v) {
        *v = new Node(node->val);
        if (node->children.empty()) {
            return;
        }

        (*v)->children.resize(node->children.size());
        for (size_t i = 0; i < node->children.size(); ++i) {
            f(node->children[i], &(*v)->children[i]);
        }
    };

    f(root, &ret);
    return ret;
}

int main() {
    {
        Node *tree = new Node(1);
        tree->children.push_back(new Node(3));
        tree->children.push_back(new Node(2));
        tree->children.push_back(new Node(4));
        tree->children[0]->children.push_back(new Node(5));
        tree->children[0]->children.push_back(new Node(6));

        auto ret = cloneTree(tree);
        assert(tree->Equal(ret));

        delete ret;
        delete tree;
    }
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

        auto ret = cloneTree(tree);
        assert(tree->Equal(ret));

        delete ret;
        delete tree;
    }
    return 0;
}
