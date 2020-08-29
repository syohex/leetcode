#include <cassert>
#include <vector>
#include <functional>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

std::vector<int> findMode(TreeNode *root) {
    if (root == nullptr) {
        return std::vector<int>{};
    }

    int max = -1;
    std::map<int, int> m;
    std::function<void(TreeNode * node)> f;
    f = [&f, &m, &max](TreeNode *node) {
        ++m[node->val];
        if (max < m[node->val]) {
            max = m[node->val];
        }

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

    std::vector<int> ret;
    for (const auto &it : m) {
        if (it.second == max) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->right = new TreeNode(2);
        tree->right->left = new TreeNode(2);
        auto ret = findMode(tree);
        assert((ret == std::vector<int>{2}));
        delete tree;
    }
    return 0;
}
