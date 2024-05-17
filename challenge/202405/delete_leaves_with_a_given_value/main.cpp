#include <cassert>
#include <functional>

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

TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == target) {
            return nullptr;
        }

        return root;
    }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (root->left == nullptr && root->right == nullptr && root->val == target) {
        return nullptr;
    }

    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(2);
        r->right->right = new TreeNode(4);

        auto *ret = removeLeafNodes(r, 2);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 3);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 4);
        assert(ret->right->right->left == nullptr);
        assert(ret->right->right->right == nullptr);
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(2);
        r->right = new TreeNode(3);

        auto *ret = removeLeafNodes(r, 3);
        assert(ret->val == 1);
        assert(ret->left->val == 3);
        assert(ret->left->left == nullptr);
        assert(ret->left->right->val == 2);
        assert(ret->left->right->left == nullptr);
        assert(ret->left->right->right == nullptr);
        assert(ret->right == nullptr);
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(2);
        r->left->left->left = new TreeNode(2);

        auto *ret = removeLeafNodes(r, 2);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right == nullptr);
    }
    return 0;
}
