#include <cassert>
#include <vector>
#include <functional>
#include <cstddef>

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
    std::vector<std::vector<Node *>> nexts;
    std::function<void(Node * node, size_t depth)> f;
    f = [&](Node *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        f(node->left, depth + 1);

        if (nexts.size() <= depth + 1) {
            nexts.resize(depth + 1);
        }
        nexts[depth].push_back(node);

        f(node->right, depth + 1);
    };

    f(root, 0);

    for (const auto &v : nexts) {
        int len = v.size();
        for (int i = 1; i < len; ++i) {
            v[i - 1]->next = v[i];
        }
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

        delete r;
    }
    {
        auto ret = connect(nullptr);
        assert(ret == nullptr);
    }
    return 0;
}
