#include <cassert>
#include <algorithm>
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

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode *, int)> f;
    f = [&f](TreeNode *node, int depth) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }

        int leftDepth = 0;
        if (node->left != nullptr) {
            leftDepth = f(node->left, depth + 1);
        }

        int rightDepth = 0;
        if (node->right != nullptr) {
            rightDepth = f(node->right, depth + 1);
        }

        return std::max(leftDepth, rightDepth);
    };

    return f(root, 1);
}

int main() {
    {
        TreeNode *tree = new TreeNode(3);
        tree->left = new TreeNode(9);
        tree->right = new TreeNode(20);
        tree->right->left = new TreeNode(15);
        tree->right->right = new TreeNode(7);
        assert(maxDepth(tree) == 3);
        delete tree;
    }
    return 0;
}
