#include <cassert>
#include <functional>
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

int sumRootToLeaf(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int ret = 0;
    std::function<void(TreeNode * node, int val)> f;
    f = [&f, &ret](TreeNode *node, int val) {
        int newVal = (val << 1) + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            ret += newVal;
            return;
        }

        if (node->left != nullptr) {
            f(node->left, newVal);
        }
        if (node->right != nullptr) {
            f(node->right, newVal);
        }
    };

    f(root, 0);
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(0);
        tree->right = new TreeNode(1);
        tree->left->left = new TreeNode(0);
        tree->left->right = new TreeNode(1);
        tree->right->left = new TreeNode(0);
        tree->right->right = new TreeNode(1);

        assert(sumRootToLeaf(tree) == 22);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(0);
        assert(sumRootToLeaf(tree) == 0);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        assert(sumRootToLeaf(tree) == 1);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(1);
        assert(sumRootToLeaf(tree) == 3);
        delete tree;
    }
    return 0;
}
