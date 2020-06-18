#include <cassert>
#include <functional>
#include <vector>

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

int deepestLeavesSum(TreeNode *root) {
    std::function<void(TreeNode * node, int depth)> f;
    std::vector<int> sums;
    f = [&f, &sums](TreeNode *node, int depth) {
        if (node->left == nullptr && node->right == nullptr) {
            if (depth >= sums.size()) {
                sums.resize(depth + 1);
                sums[depth] = node->val;
            } else {
                sums[depth] += node->val;
            }

            return;
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            f(node->right, depth + 1);
        }
    };

    f(root, 0);
    return sums.back();
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        assert(deepestLeavesSum(tree) == 5);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->left = new TreeNode(4);
        tree->left->left->left = new TreeNode(7);
        tree->left->right = new TreeNode(5);
        tree->right = new TreeNode(3);
        tree->right->right = new TreeNode(6);
        tree->right->right->right = new TreeNode(8);
        assert(deepestLeavesSum(tree) == 15);
        delete tree;
    }
    return 0;
}
