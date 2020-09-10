#include <cassert>
#include <cstdio>
#include <vector>
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

bool findTarget(TreeNode *root, int k) {
    if (root == nullptr) {
        return false;
    }

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

    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[i] + v[j] == k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    {
        TreeNode *tree = new TreeNode(5);
        tree->left = new TreeNode(3);
        tree->left->left = new TreeNode(2);
        tree->left->right = new TreeNode(4);
        tree->right = new TreeNode(6);
        tree->right->right = new TreeNode(7);
        assert(findTarget(tree, 9));
        assert(!findTarget(tree, 28));
        delete tree;
    }
    return 0;
}
