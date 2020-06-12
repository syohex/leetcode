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

int sumRootToLeaf(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode *, int)> f;
    f = [&f](TreeNode *node, int acc) -> int {
        if (node == nullptr) {
            return 0;
        }

        int val = (acc << 1) + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return val;
        }

        return f(node->left, val) + f(node->right, val);
    };

    return f(root, 0);
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(0);
        tree->left->left = new TreeNode(0);
        tree->left->right = new TreeNode(1);
        tree->right = new TreeNode(1);
        tree->right->left = new TreeNode(0);
        tree->right->right = new TreeNode(1);

        assert(sumRootToLeaf(tree) == 22);

        delete tree;
    }
    return 0;
}
