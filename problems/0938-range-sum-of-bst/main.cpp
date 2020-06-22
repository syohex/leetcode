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

int rangeSumBST(TreeNode *root, int L, int R) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode *, int, int)> f;
    f = [&f](TreeNode *node, int mi, int ma) -> int {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return (node->val >= mi && node->val <= ma) ? node->val : 0;
        }

        int leftSum = f(node->left, mi, ma);
        int rightSum = f(node->right, mi, ma);

        int val = (node->val >= mi && node->val <= ma) ? node->val : 0;
        return leftSum + val + rightSum;
    };

    return f(root, L, R);
}

int main() {
    {
        TreeNode *tree = new TreeNode(10);
        tree->left = new TreeNode(5);
        tree->right = new TreeNode(15);
        tree->left->left = new TreeNode(3);
        tree->left->right = new TreeNode(7);
        tree->right->right = new TreeNode(18);
        assert(rangeSumBST(tree, 7, 15) == 32);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(10);
        tree->left = new TreeNode(5);
        tree->right = new TreeNode(15);
        tree->left->left = new TreeNode(3);
        tree->left->right = new TreeNode(7);
        tree->right->left = new TreeNode(13);
        tree->right->right = new TreeNode(18);
        tree->left->left->left = new TreeNode(1);
        tree->left->right->left = new TreeNode(6);
        assert(rangeSumBST(tree, 6, 10) == 23);
        delete tree;
    }
    return 0;
}
