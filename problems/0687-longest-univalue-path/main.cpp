#include <cassert>
#include <functional>
#include <algorithm>
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

int longestUnivaluePath(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int ret = 0;
    std::function<int(TreeNode * node)> f;
    f = [&f, &ret](TreeNode *node) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left);
            if (node->val == node->left->val) {
                ++left;
            } else {
                left = 0;
            }
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right);
            if (node->val == node->right->val) {
                ++right;
            } else {
                right = 0;
            }
        }

        ret = std::max(ret, left + right);
        return std::max(left, right);
    };

    (void)f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(5);

        assert(longestUnivaluePath(r) == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(5);

        assert(longestUnivaluePath(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(5);

        assert(longestUnivaluePath(r) == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(1);
        r->right->left->left = new TreeNode(1);
        r->right->left->right = new TreeNode(1);
        r->right->right->left = new TreeNode(1);

        assert(longestUnivaluePath(r) == 4);
        delete r;
    }
    return 0;
}
