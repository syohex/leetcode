#include <cassert>
#include <functional>
#include <climits>

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

int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode *, int)> f;
    int max = 0;
    f = [&f, &max](TreeNode *tree, int depth) -> int {
        if (tree->left == nullptr && tree->right == nullptr) {
            return depth;
        }

        int leftDepth = 0;
        if (tree->left != nullptr) {
            leftDepth = f(tree->left, depth + 1);
        }

        int rightDepth = 0;
        if (tree->right != nullptr) {
            rightDepth = f(tree->right, depth + 1);
        }

        int sum = leftDepth + rightDepth - (2 * depth);
        if (max < sum) {
            max = sum;
        }

        return leftDepth > rightDepth ? leftDepth : rightDepth;
    };

    (void)f(root, 0);
    return max;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(4);
        tree->left->right = new TreeNode(5);
        tree->right = new TreeNode(3);

        assert(diameterOfBinaryTree(tree) == 3);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        assert(diameterOfBinaryTree(tree) == 0);
        delete tree;
    }
    return 0;
}
