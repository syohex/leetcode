#include <cassert>
#include <functional>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left);
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right);
        }

        return std::max(left, right) + 1;
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        assert(maxDepth(r) == 3);
    }
    return 0;
}
