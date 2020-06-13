#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }

    bool Equal(TreeNode *t) {
        if (t == nullptr) {
            return false;
        }

        if (val != t->val) {
            return false;
        }

        if (left != nullptr) {
            if (!left->Equal(t->left)) {
                return false;
            }
        }
        if (right != nullptr) {
            if (!right->Equal(t->right)) {
                return false;
            }
        }

        return true;
    }
};

TreeNode *increasingBST(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode *ret = nullptr;
    TreeNode **p = &ret;
    std::function<void(TreeNode * node)> f;
    f = [&f, &p](TreeNode *node) {
        if (node->left != nullptr) {
            f(node->left);
        }

        *p = new TreeNode(node->val);
        p = &((*p)->right);

        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(5);
        tree->left = new TreeNode(3);
        tree->left->left = new TreeNode(2);
        tree->left->right = new TreeNode(4);
        tree->left->left->left = new TreeNode(1);
        tree->right = new TreeNode(6);
        tree->right->right = new TreeNode(8);
        tree->right->right->left = new TreeNode(7);
        tree->right->right->right = new TreeNode(9);

        TreeNode *expected = new TreeNode(1);
        expected->right = new TreeNode(2);
        expected->right->right = new TreeNode(3);
        expected->right->right->right = new TreeNode(4);
        expected->right->right->right->right = new TreeNode(5);
        expected->right->right->right->right->right = new TreeNode(6);
        expected->right->right->right->right->right->right = new TreeNode(7);
        expected->right->right->right->right->right->right->right = new TreeNode(8);
        expected->right->right->right->right->right->right->right->right = new TreeNode(9);

        TreeNode *ret = increasingBST(tree);
        assert(ret->Equal(expected));

        delete ret;
        delete expected;
        delete tree;
    }
    return 0;
}
