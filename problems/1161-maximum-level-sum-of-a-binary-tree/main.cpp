#include <cassert>
#include <vector>
#include <functional>
#include <climits>

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

int maxLevelSum(TreeNode *root) {
    std::function<void(TreeNode *, int)> f;
    std::vector<int> sums;
    f = [&f, &sums](TreeNode *node, int depth) {
        if (node->left == nullptr && node->right == nullptr) {
            if (depth + 1 > sums.size()) {
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

        sums[depth] += node->val;
    };

    f(root, 0);

    int max = INT_MIN;
    int ret = 0;
    for (int i = 0; i < static_cast<int>(sums.size()); ++i) {
        if (max < sums[i]) {
            ret = i + 1;
            max = sums[i];
        }
    }
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(7);
        tree->left->left = new TreeNode(7);
        tree->left->right = new TreeNode(-8);
        tree->right = 0;
        assert(maxLevelSum(tree) == 2);
        delete tree;
    }
    return 0;
}
