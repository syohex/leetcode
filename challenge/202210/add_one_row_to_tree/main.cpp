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

TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    std::function<void(TreeNode * node, int d, int val, int depth)> f;
    f = [&](TreeNode *node, int d, int val, int depth) {
        if (node == nullptr) {
            return;
        }

        if (d + 1 == depth) {
            TreeNode *new_left = new TreeNode(val);
            new_left->left = node->left;
            node->left = new_left;

            TreeNode *new_right = new TreeNode(val);
            new_right->right = node->right;
            node->right = new_right;

            return;
        }

        f(node->left, d + 1, val, depth);
        f(node->right, d + 1, val, depth);
    };

    if (depth == 1) {
        TreeNode *ret = new TreeNode(val);
        ret->left = root;
        return ret;
    }

    f(root, 1, val, depth);
    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(6);
        r->right->left = new TreeNode(5);

        auto ret = addOneRow(r, 1, 2);
        assert(ret->val == 4);
        assert(ret->left->val == 1);
        assert(ret->left->left->val == 2);
        assert(ret->left->left->left->val == 3);
        assert(ret->left->left->right->val == 1);
        assert(ret->right->val == 1);
        assert(ret->right->right->val == 6);
        assert(ret->right->right->left->val == 5);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);

        auto ret = addOneRow(r, 1, 3);
        assert(ret->val == 4);
        assert(ret->left->val == 2);
        assert(ret->left->left->val == 1);
        assert(ret->left->left->left->val == 3);
        assert(ret->left->right->val == 1);
        assert(ret->left->right->right->val == 1);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->left = new TreeNode(4);

        auto ret = addOneRow(r, 5, 4);
        assert(ret->val == 1);
        assert(ret->left->val == 2);
        assert(ret->right->val == 3);
        assert(ret->left->left->val == 4);
        assert(ret->left->left->left->val == 5);
        assert(ret->left->left->right->val == 5);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->right = new TreeNode(6);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);
        r->right->left = new TreeNode(5);

        auto ret = addOneRow(r, 1, 1);
        assert(ret->val == 1);
        assert(ret->left->val == 4);
        assert(ret->right == nullptr);
        assert(ret->left->left->val == 2);
        assert(ret->left->right->val == 6);
        assert(ret->left->left->left->val == 3);
        assert(ret->left->left->right->val == 1);
        assert(ret->left->right->left->val == 5);
        delete ret;
    }
    return 0;
}
