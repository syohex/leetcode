#include <cassert>
#include <functional>
#include <algorithm>
#include <cmath>
#include <limits>

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

int maxAncestorDiff(TreeNode *root) {
    std::function<int(TreeNode * node, int max_val, int min_val)> f;
    f = [&](TreeNode *node, int max_val, int min_val) -> int {
        if (node == nullptr) {
            return 0;
        }

        int min = std::min(min_val, node->val);
        int max = std::max(max_val, node->val);
        int left = f(node->left, max, min);
        int right = f(node->right, max, min);

        int v1 = std::abs(node->val - min_val);
        int v2 = std::abs(node->val - max_val);

        return std::max({v1, v2, left, right});
    };

    return f(root, root->val, root->val);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(0);
        r->right->right->left = new TreeNode(3);

        assert(maxAncestorDiff(r) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(8);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(6);
        r->left->right->left = new TreeNode(4);
        r->left->right->right = new TreeNode(7);
        r->right = new TreeNode(10);
        r->right->right = new TreeNode(14);
        r->right->right->left = new TreeNode(13);

        assert(maxAncestorDiff(r) == 7);
        delete r;
    }
    return 0;
}
