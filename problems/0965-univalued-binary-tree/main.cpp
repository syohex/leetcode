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
};

bool isUnivalTree(TreeNode *root) {
    std::function<bool(TreeNode *, int)> f;
    f = [&f](TreeNode *node, int rootVal) {
        if (node->val != rootVal) {
            return false;
        }

        if (node->left != nullptr) {
            if (!f(node->left, rootVal)) {
                return false;
            }
        }
        if (node->right != nullptr) {
            if (!f(node->right, rootVal)) {
                return false;
            }
        }

        return true;
    };

    return f(root, root->val);
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(1);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(1);
        tree->right = new TreeNode(1);
        tree->right->right = new TreeNode(1);

        assert(isUnivalTree(tree));
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(2);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(5);
        tree->left->right = new TreeNode(2);
        tree->right = new TreeNode(2);

        assert(!isUnivalTree(tree));
        delete tree;
    }
    return 0;
}
