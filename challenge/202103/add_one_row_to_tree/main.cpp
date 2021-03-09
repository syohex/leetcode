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

TreeNode *addOneRow(TreeNode *root, int v, int d) {
    std::function<void(TreeNode * node, int depth)> f;
    f = [&f, v, d](TreeNode *node, int depth) {
        if (node == nullptr || depth >= d) {
            return;
        }

        if (depth == d - 1) {
            auto tmp = node->left;
            node->left = new TreeNode(v);
            node->left->left = tmp;

            tmp = node->right;
            node->right = new TreeNode(v);
            node->right->right = tmp;
        } else {
            f(node->left, depth + 1);
            f(node->right, depth + 1);
        }
    };

    if (d == 1) {
        auto *ret = new TreeNode(v);
        ret->left = root;
        return ret;
    }

    f(root, 1);
    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->right = new TreeNode(6);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);
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
        assert(ret->left->right->val == 1);
        assert(ret->left->left->left->val == 3);
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
