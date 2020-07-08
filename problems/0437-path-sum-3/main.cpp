#include <cassert>
#include <functional>
#include <vector>

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

int pathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
        return 0;
    }

    int ret = 0;
    std::function<void(TreeNode *, int, const std::vector<int> &)> f;
    f = [&f, &ret](TreeNode *node, int sum, const std::vector<int> &acc) {
        if (node->val == sum) {
            ++ret;
        }

        for (int v : acc) {
            if (v + node->val == sum) {
                ++ret;
            }
        }

        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        auto newAcc = acc;
        for (size_t i = 0; i < acc.size(); ++i) {
            newAcc[i] += node->val;
        }
        newAcc.push_back(node->val);
        if (node->left != nullptr) {
            f(node->left, sum, newAcc);
        }

        if (node->right != nullptr) {
            f(node->right, sum, newAcc);
        }
    };

    f(root, sum, std::vector<int>{});
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(10);
        tree->left = new TreeNode(5);
        tree->left->left = new TreeNode(3);
        tree->left->left->left = new TreeNode(3);
        tree->left->left->right = new TreeNode(-2);
        tree->left->right = new TreeNode(2);
        tree->left->right->right = new TreeNode(1);
        tree->right = new TreeNode(-3);
        tree->right->right = new TreeNode(11);

        assert(pathSum(tree, 8) == 3);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(5);
        tree->left = new TreeNode(4);
        tree->right = new TreeNode(8);
        tree->left->left = new TreeNode(11);
        tree->right->left = new TreeNode(13);
        tree->right->right = new TreeNode(4);
        tree->left->left->left = new TreeNode(7);
        tree->left->left->right = new TreeNode(2);
        tree->right->left->left = new TreeNode(5);
        tree->right->left->right = new TreeNode(1);

        assert(pathSum(tree, 22) == 3);
        delete tree;
    }
    return 0;
}
