#include <cassert>
#include <functional>
#include <algorithm>
#include <cmath>
#include <cstdio>

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
    std::function<int(TreeNode * node, int min, int max)> f;
    f = [&](TreeNode *node, int min, int max) -> int {
        if (node == nullptr) {
            return -1;
        }

        int ret = std::max(std::abs(node->val - min), std::abs(node->val - max));

        int new_min = std::min(node->val, min);
        int new_max = std::max(node->val, max);
        int left = f(node->left, new_min, new_max);
        int right = f(node->right, new_min, new_max);

        return std::max({ret, left, right});
    };

    return f(root, root->val, root->val);
}

int main() {
    {
        TreeNode *r = new TreeNode(8);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(6);
        r->left->right->left = new TreeNode(4);
        r->left->right->right = new TreeNode(7);
        r->right = new TreeNode(10);
        r->right->right = new TreeNode(14);
        r->right->right->right = new TreeNode(13);

        int ret = maxAncestorDiff(r);
        assert(ret == 7);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(0);
        r->right->right->left = new TreeNode(3);

        int ret = maxAncestorDiff(r);
        assert(ret == 3);
        delete r;
    }
    return 0;
}
