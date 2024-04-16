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

TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    std::function<TreeNode *(TreeNode * node, int val, int depth, bool is_left)> f;
    f = [&](TreeNode *node, int val, int depth, bool is_left) -> TreeNode * {
        if (depth == 0) {
            TreeNode *n = new TreeNode(val);
            if (node == nullptr) {
                return n;
            }

            if (is_left) {
                n->left = node;
            } else {
                n->right = node;
            }

            return n;
        }

        if (node == nullptr) {
            return nullptr;
        }

        node->left = f(node->left, val, depth - 1, true);
        node->right = f(node->right, val, depth - 1, false);

        return node;
    };

    if (depth == 1) {
        TreeNode *node = new TreeNode(val);
        node->left = root;
        return node;
    }

    return f(root, val, depth - 1, false);
}

int main() {
    {
        TreeNode *r1 = new TreeNode(4);
        TreeNode *r2 = new TreeNode(2);
        TreeNode *r3 = new TreeNode(6);
        TreeNode *r4 = new TreeNode(3);
        TreeNode *r5 = new TreeNode(1);
        TreeNode *r6 = new TreeNode(5);
        r1->left = r2;
        r1->right = r3;
        r2->left = r4;
        r2->right =r5;
        r3->left = r6;

        auto *ret = addOneRow(r1, 1, 2);
        assert(ret->val == 4);
        assert(ret->left->val == 1);
        assert(ret->left->left == r2);
        assert(ret->left->right == nullptr);
        assert(ret->right->val == 1);
        assert(ret->right->left == nullptr);
        assert(ret->right->right == r3);

        delete ret;
    }
    {
        TreeNode *r1 = new TreeNode(4);
        TreeNode *r2 = new TreeNode(2);
        TreeNode *r3 = new TreeNode(3);
        TreeNode *r4 = new TreeNode(1);
        r1->left = r2;
        r2->left = r3;
        r2->right = r4;

        auto *ret = addOneRow(r1, 1, 3);
        assert(ret->val == 4);
        assert(ret->left->val == 2);
        assert(ret->left->left->val == 1);
        assert(ret->left->left->left == r3);
        assert(ret->left->right->val == 1);
        assert(ret->left->right->right == r4);

        delete ret;
    }
    {
        TreeNode *r1 = new TreeNode(4);
        TreeNode *r2 = new TreeNode(2);
        TreeNode *r3 = new TreeNode(6);
        TreeNode *r4 = new TreeNode(3);
        TreeNode *r5 = new TreeNode(1);
        TreeNode *r6 = new TreeNode(5);
        r1->left = r2;
        r1->right = r3;
        r2->left = r4;
        r2->right =r5;
        r3->left = r6;

        auto *ret = addOneRow(r1, 1, 1);
        assert(ret->val == 1);
        assert(ret->left == r1);
        assert(ret->right == nullptr);

        delete ret;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        TreeNode *r2 = new TreeNode(2);
        TreeNode *r3 = new TreeNode(3);
        TreeNode *r4 = new TreeNode(4);
        r1->left = r2;
        r1->right = r3;
        r2->left = r4;

        auto *ret = addOneRow(r1, 5, 4);
        assert(ret == r1);
        assert(ret->left == r2);
        assert(ret->right == r3);
        assert(ret->left->left == r4);
        assert(ret->left->left->left->val == 5);
        assert(ret->left->left->left->left == nullptr);
        assert(ret->left->left->left->right == nullptr);
        assert(ret->left->left->right->val == 5);
        assert(ret->left->left->right->left == nullptr);
        assert(ret->left->left->right->right == nullptr);

        delete ret;
    }
    return 0;
}
