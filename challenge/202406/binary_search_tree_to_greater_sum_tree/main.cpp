#include <cassert>
#include <functional>

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

TreeNode *bstToGst(TreeNode *root) {
    std::function<void(TreeNode * node, int &sum)> f;
    f = [&](TreeNode *node, int &sum) {
        if (node->right != nullptr) {
            f(node->right, sum);
        }

        sum += node->val;
        node->val = sum;

        if (node->left != nullptr) {
            f(node->left, sum);
        }
    };

    int sum = 0;
    f(root, sum);
    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(2);
        r->left->right->right = new TreeNode(3);
        r->right = new TreeNode(6);
        r->right->left = new TreeNode(5);
        r->right->right = new TreeNode(7);
        r->right->right->right = new TreeNode(8);

        auto *ret = bstToGst(r);
        assert(ret->val == 30);
        assert(ret->left->val == 36);
        assert(ret->left->left->val == 36);
        assert(ret->left->right->val == 35);
        assert(ret->left->right->right->val == 33);
        assert(ret->right->val == 21);
        assert(ret->right->left->val == 26);
        assert(ret->right->right->val == 15);
        assert(ret->right->right->right->val == 8);

        delete ret;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->right = new TreeNode(1);

        auto *ret = bstToGst(r);
        assert(ret->val == 1);
        assert(ret->right->val == 1);

        delete ret;
    }
    return 0;
}
