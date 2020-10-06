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

TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    std::function<void(TreeNode * node, int v)> f;
    f = [&f](TreeNode *node, int v) {
        if (v < node->val) {
            if (node->left == nullptr) {
                node->left = new TreeNode(v);
                return;
            }

            f(node->left, v);
            return;
        }

        if (v > node->val) {
            if (node->right == nullptr) {
                node->right = new TreeNode(v);
                return;
            }

            f(node->right, v);
            return;
        }
    };

    f(root, val);
    return root;
}

int main() {
    {
        TreeNode *tree = new TreeNode(4);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(3);
        tree->right = new TreeNode(7);

        insertIntoBST(tree, 5);

        assert(tree->right->left->val == 5);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(40);
        tree->left = new TreeNode(20);
        tree->right = new TreeNode(60);
        tree->left->left = new TreeNode(10);
        tree->left->right = new TreeNode(30);
        tree->right->left = new TreeNode(50);
        tree->right->right = new TreeNode(70);

        insertIntoBST(tree, 25);

        assert(tree->left->right->left->val == 25);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(4);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(7);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(3);

        insertIntoBST(tree, 5);

        assert(tree->right->left->val == 5);
        delete tree;
    }
    return 0;
}
