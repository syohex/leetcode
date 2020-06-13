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

    bool Equal(TreeNode *a) {
        if (a == nullptr) {
            return false;
        }

        if (val != a->val) {
            return false;
        }

        if (left != nullptr) {
            return left->Equal(a->left);
        }
        if (right != nullptr) {
            return right->Equal(a->right);
        }

        return true;
    }
};

TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<void(TreeNode *, TreeNode **)> f;
    f = [&f](TreeNode *node, TreeNode **r) {
        *r = new TreeNode(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left, &((*r)->right));
        }
        if (node->right != nullptr) {
            f(node->right, &((*r)->left));
        }
    };

    TreeNode *ret = nullptr;
    f(root, &ret);
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(4);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(3);
        tree->right = new TreeNode(7);
        tree->right->left = new TreeNode(6);
        tree->right->right = new TreeNode(9);

        TreeNode *invert = invertTree(tree);

        TreeNode *expected = new TreeNode(4);
        expected->left = new TreeNode(7);
        expected->left->left = new TreeNode(9);
        expected->left->right = new TreeNode(6);
        expected->right = new TreeNode(2);
        expected->right->left = new TreeNode(3);
        expected->right->right = new TreeNode(1);

        assert(invert->Equal(expected));

        delete expected;
        delete tree;
    }
    return 0;
}
