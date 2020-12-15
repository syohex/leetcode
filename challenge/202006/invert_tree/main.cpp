#include <cassert>
#include <functional>
#include <cstdio>
#include <utility>

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

TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<void(TreeNode * node)> f;
    f = [&f](TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        std::swap(node->left, node->right);

        if (node->left != nullptr) {
            f(node->left);
        }
        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);
    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->right = new TreeNode(7);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(9);

        auto ret = invertTree(r);

        assert(ret == r);
        assert(ret->left->val == 7);
        assert(ret->right->val == 2);
        assert(ret->left->left->val == 9);
        assert(ret->left->right->val == 6);
        assert(ret->right->left->val == 3);
        assert(ret->right->right->val == 1);

        delete r;
    }
    return 0;
}
