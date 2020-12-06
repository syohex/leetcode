#include <cassert>
#include <vector>
#include <functional>

class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {
    }
    ~Node() {
        delete left;
        delete right;
    }
};

Node *connect(Node *root) {
    std::vector<std::vector<Node *>> v;
    std::function<void(Node * node, size_t depth)> f;
    f = [&f, &v](Node *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        if (v.size() < depth + 1) {
            v.resize(depth + 1);
        }

        f(node->left, depth + 1);
        v[depth].push_back(node);
        f(node->right, depth + 1);
    };

    f(root, 0);

    for (auto &nodes : v) {
        for (size_t i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }

        nodes.back()->next = nullptr;
    }

    return root;
}

int main() {
    {
        Node *r = new Node(1);
        r->left = new Node(2);
        r->right = new Node(3);
        r->left->left = new Node(4);
        r->left->right = new Node(5);
        r->right->right = new Node(7);

        auto ret = connect(r);
        assert(ret->next == nullptr);
        assert(ret->left->next == ret->right);
        assert(ret->right->next == nullptr);
        assert(ret->left->left->next == ret->left->right);
        assert(ret->left->right->next == ret->right->right);
        assert(ret->right->right->next == nullptr);

        delete r;
    }
    return 0;
}
