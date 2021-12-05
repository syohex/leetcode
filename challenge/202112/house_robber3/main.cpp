#include <cassert>
#include <algorithm>
#include <utility>

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

int rob(TreeNode *root) {
    std::function<std::pair<int, int>(TreeNode * node)> f;
    f = [&](TreeNode *node) -> std::pair<int, int> {
        if (node == nullptr) {
            return {0, 0};
        }

        auto left = f(node->left);
        auto right = f(node->right);

        int included = node->val + left.second + right.second;
        int not_includes = std::max(left.first, left.second) + std::max(right.first, right.second);

        return {included, not_includes};
    };

    auto ret = f(root);
    return std::max(ret.first, ret.second);
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->right = new TreeNode(3);
        r->right->right = new TreeNode(1);

        assert(rob(r) == 7);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(4);
        r->right = new TreeNode(5);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right->right = new TreeNode(1);

        assert(rob(r) == 9);
        delete r;
    }
    return 0;
}
