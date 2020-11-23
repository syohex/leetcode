#include <cassert>
#include <functional>
#include <algorithm>
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

int rob(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    struct Val {
        int with_this_node;
        int without_this_node;
    };

    std::function<Val(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> Val {
        if (node == nullptr) {
            return Val{0, 0};
        }

        Val left = f(node->left);
        Val right = f(node->right);

        int with = node->val + left.without_this_node + right.without_this_node;
        int without =
            std::max(left.with_this_node, left.without_this_node) + std::max(right.with_this_node, right.without_this_node);

        return Val{with, without};
    };

    Val v = f(root);
    return std::max(v.with_this_node, v.without_this_node);
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(1);

        assert(rob(r) == 7);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(1);

        assert(rob(r) == 9);

        delete r;
    }
    return 0;
}
