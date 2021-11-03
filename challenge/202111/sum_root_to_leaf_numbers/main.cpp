#include <cassert>
#include <functional>
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

int sumNumbers(TreeNode *root) {
    long ret = 0;
    std::function<void(TreeNode * node, long acc)> f;
    f = [&f, &ret](TreeNode *node, long acc) {
        acc = 10 * acc + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            ret += acc;
            return;
        }

        if (node->left != nullptr) {
            f(node->left, acc);
        }
        if (node->right != nullptr) {
            f(node->right, acc);
        }
    };

    f(root, 0);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        assert(sumNumbers(r) == 25);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(9);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(0);
        assert(sumNumbers(r) == 1026);
        delete r;
    }
    return 0;
}
