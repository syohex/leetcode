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

TreeNode *bstToGst(TreeNode *root) {
    std::function<void(TreeNode * node, TreeNode * r)> f;
    int sum = 0;
    f = [&f, &sum](TreeNode *node, TreeNode *r) {
        if (node->right != nullptr) {
            r->right = new TreeNode(0);
            f(node->right, r->right);
        }

        sum += node->val;
        r->val = sum;

        if (node->left != nullptr) {
            r->left = new TreeNode(0);
            f(node->left, r->left);
        }
    };

    TreeNode *ret = new TreeNode(0);
    f(root, ret);
    return ret;
}

int main() {
    {
        TreeNode *t = new TreeNode(4);
        t->left = new TreeNode(1);
        t->left->left = new TreeNode(0);
        t->left->right = new TreeNode(2);
        t->left->right->right = new TreeNode(3);
        t->right = new TreeNode(6);
        t->right->left = new TreeNode(5);
        t->right->right = new TreeNode(7);
        t->right->right->right = new TreeNode(8);

        auto ret = bstToGst(t);
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
        delete t;
    }
    {
        TreeNode *t = new TreeNode(0);
        t->right = new TreeNode(1);
        auto ret = bstToGst(t);
        assert(ret->val == 1);
        assert(ret->right->val == 1);
        delete ret;
        delete t;
    }
    {
        TreeNode *t = new TreeNode(1);
        t->left = new TreeNode(0);
        t->right = new TreeNode(2);
        auto ret = bstToGst(t);
        assert(ret->val == 3);
        assert(ret->left->val == 3);
        assert(ret->right->val == 2);
        delete ret;
        delete t;
    }
    return 0;
}
