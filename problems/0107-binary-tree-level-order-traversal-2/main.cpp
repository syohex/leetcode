#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

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

std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node, int depth)> f;
    f = [&f, &ret](TreeNode *node, int depth) {
        if (static_cast<int>(ret.size()) <= depth) {
            ret.resize(depth + 1);
        }
        ret[depth].push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
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

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(3);
        tree->left = new TreeNode(9);
        tree->right = new TreeNode(20);
        tree->right->left = new TreeNode(15);
        tree->right->right = new TreeNode(7);

        auto ret = levelOrderBottom(tree);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{15, 7}));
        assert((ret[1] == std::vector<int>{9, 20}));
        assert((ret[2] == std::vector<int>{3}));
        delete tree;
    }
    return 0;
}
