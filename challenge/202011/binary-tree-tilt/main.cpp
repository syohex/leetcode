#include <cassert>
#include <functional>
#include <cstdio>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int findTilt(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int sum = 0;
    std::function<int(TreeNode * node)> f;
    f = [&f, &sum](TreeNode *node) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return node->val;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left);
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right);
        }

        sum += std::abs(right - left);
        return left + right + node->val;
    };

    f(root);
    return sum;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        assert(findTilt(r) == 1);
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->right = new TreeNode(9);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(5);
        r->right->right = new TreeNode(7);

        assert(findTilt(r) == 15);
    }
    {
        TreeNode *r = new TreeNode(21);
        r->left = new TreeNode(7);
        r->right = new TreeNode(14);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->left->left->left = new TreeNode(3);
        r->left->left->right = new TreeNode(3);
        r->right->left = new TreeNode(2);
        r->right->right = new TreeNode(2);

        assert(findTilt(r) == 9);
    }
    return 0;
}
