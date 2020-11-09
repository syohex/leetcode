#include <cassert>
#include <vector>
#include <functional>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int maxAncestorDiff(TreeNode *root) {
    int ret = 0;
    std::function<void(TreeNode * node, int min, int max)> f;
    f = [&f, &ret](TreeNode *node, int min, int max) {
        if (min != -1) {
            int a = std::abs(min - node->val);
            if (a > ret) {
                ret = a;
            }
        }
        if (max != -1) {
            int b = std::abs(max - node->val);
            if (b > ret) {
                ret = b;
            }
        }

        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (min == -1 || max == -1) {
            min = node->val;
            max = node->val;
        } else {
            min = std::min(min, node->val);
            max = std::max(max, node->val);
        }

        if (node->left != nullptr) {
            f(node->left, min, max);
        }
        if (node->right != nullptr) {
            f(node->right, min, max);
        }
    };

    f(root, -1, -1);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(8);
        r->left = new TreeNode(3);
        r->right = new TreeNode(10);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(6);
        r->left->right->left = new TreeNode(4);
        r->left->right->right = new TreeNode(7);
        r->right->right = new TreeNode(14);
        r->right->right->right = new TreeNode(13);

        assert(maxAncestorDiff(r) == 7);
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(0);
        r->right->right->left = new TreeNode(3);

        assert(maxAncestorDiff(r) == 3);
    }
    return 0;
}
