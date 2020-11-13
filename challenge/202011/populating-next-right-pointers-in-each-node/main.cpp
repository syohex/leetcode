#include <cassert>
#include <functional>
#include <vector>
#include <cmath>

class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {
    }
};

Node *connect(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::vector<std::vector<Node *>> v;
    std::function<void(Node * node, size_t depth, size_t col, size_t limit)> f;
    f = [&f, &v](Node *node, size_t depth, size_t col, size_t limit) {
        if (v.size() < depth + 1) {
            v.resize(depth + 1);
            v[depth].resize(limit);
        }

        v[depth][col] = node;

        if (node->right != nullptr) {
            f(node->right, depth + 1, 2 * col + 1, 2 * limit);
        }

        if (col == limit - 1) {
            node->next = nullptr;
        } else {
            node->next = v[depth][col + 1];
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1, 2 * col, 2 * limit);
        }
    };

    f(root, 0, 0, 1);
    return root;
}

int main() {
    {
        Node *r = new Node(1);
        r->left = new Node(2);
        r->right = new Node(3);
        r->left->left = new Node(4);
        r->left->right = new Node(5);
        r->right->left = new Node(6);
        r->right->right = new Node(7);

        auto ret = connect(r);
        assert(ret->next == nullptr);
        assert(ret->left->next == ret->right);
        assert(ret->right->next == nullptr);
        assert(ret->left->left->next == ret->left->right);
        assert(ret->left->right->next == ret->right->left);
        assert(ret->right->left->next == ret->right->right);
        assert(ret->right->right->next == nullptr);
    }
    return 0;
}