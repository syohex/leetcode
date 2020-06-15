#include <cassert>
#include <functional>
#include <cstdio>

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

    bool Equal(TreeNode *a) {
        if (a == nullptr) {
            return false;
        }
        if (val != a->val) {
            return false;
        }

        if (left != nullptr) {
            if (!left->Equal(a->left)) {
                return false;
            }
        } else {
            if (a->left != nullptr) {
                return false;
            }
        }
        if (right != nullptr) {
            if (!right->Equal(a->right)) {
                return false;
            }
        } else {
            if (a->right != nullptr) {
                return false;
            }
        }

        return true;
    }
};

TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<bool(TreeNode * *node, int val)> f;
    f = [&f](TreeNode **node, int val) {
        TreeNode *n = *node;
        if (n->left == nullptr && n->right == nullptr) {
            bool match = n->val == val;
            if (match) {
                delete n;
            }

            return match;
        }

        bool deleteLeft = true;
        if (n->left != nullptr) {
            deleteLeft = f(&(n->left), val);
            if (deleteLeft) {
                n->left = nullptr;
            }
        }

        bool deleteRight = true;
        if (n->right != nullptr) {
            deleteRight = f(&(n->right), val);
            if (deleteRight) {
                n->right = nullptr;
            }
        }

        if (n->val == val && deleteLeft && deleteRight) {
            delete n;
            return true;
        }

        return false;
    };

    bool deleteRoot = f(&root, target);
    if (deleteRoot) {
        return nullptr;
    }
    return root;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->right->left = new TreeNode(2);
        tree->right->right = new TreeNode(4);

        TreeNode *expected = new TreeNode(1);
        expected->right = new TreeNode(3);
        expected->right->right = new TreeNode(4);

        auto ret = removeLeafNodes(tree, 2);
        assert(ret->Equal(expected));
        delete tree;
        delete expected;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(3);
        tree->left->left = new TreeNode(3);
        tree->left->right = new TreeNode(2);
        tree->right = new TreeNode(3);

        TreeNode *expected = new TreeNode(1);
        expected->left = new TreeNode(3);
        expected->left->right = new TreeNode(2);

        auto ret = removeLeafNodes(tree, 3);
        assert(ret->Equal(expected));
        delete tree;
        delete expected;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(2);
        tree->left->left->left = new TreeNode(2);

        TreeNode *expected = new TreeNode(1);
        auto ret = removeLeafNodes(tree, 2);
        assert(ret->Equal(expected));
        delete tree;
        delete expected;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(1);
        tree->right = new TreeNode(1);
        auto ret = removeLeafNodes(tree, 1);
        assert(ret == nullptr);
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);

        TreeNode *expected = new TreeNode(1);
        expected->left = new TreeNode(2);
        expected->right = new TreeNode(3);
        auto ret = removeLeafNodes(tree, 1);
        assert(ret->Equal(expected));

        delete expected;
        delete tree;
    }
    return 0;
}
