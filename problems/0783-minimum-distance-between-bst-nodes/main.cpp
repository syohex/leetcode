#include <cassert>
#include <functional>
#include <climits>
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

int minDiffInBST(TreeNode *root) {
    std::vector<int> v;
    std::function<void(TreeNode * node)> f;
    f = [&f, &v](TreeNode *node) {
        v.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left);
        }
        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);

    int min = INT_MAX;
    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = i + 1; j < v.size(); ++j) {
            int diff = v[i] > v[j] ? v[i] - v[j] : v[j] - v[i];
            if (diff < min) {
                min = diff;
                if (min == 1) {
                    return min;
                }
            }
        }
    }

    return min;
}

int main() {
    {
        TreeNode *tree = new TreeNode(4);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(6);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(3);
        assert(minDiffInBST(tree) == 1);
        delete tree;
    }
    return 0;
}
