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
};

int findTilt(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode *, int &)> f;
    f = [&f](TreeNode *node, int &tilt) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return node->val;
        }

        int leftSum = 0;
        if (node->left != nullptr) {
            leftSum = f(node->left, tilt);
        }
        int rightSum = 0;
        if (node->right != nullptr) {
            rightSum = f(node->right, tilt);
        }

        int currentTilt = leftSum < rightSum ? rightSum - leftSum : leftSum - rightSum;
        tilt += currentTilt;
        return leftSum + rightSum + node->val;
    };

    int tilt = 0;
    f(root, tilt);
    return tilt;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        assert(findTilt(tree) == 1);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        assert(findTilt(tree) == 0);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->left = new TreeNode(4);
        tree->right->left = new TreeNode(5);
        assert(findTilt(tree) == 11);
        delete tree;
    }
    return 0;
}
