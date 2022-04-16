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

TreeNode *convertBST(TreeNode *root) {
    std::function<int(TreeNode * node, int val)> f;
    f = [&f](TreeNode *node, int val) -> int {
        if (node == nullptr) {
            return 0;
        }

        if (node->right != nullptr) {
            val = f(node->right, val);
        }

        node->val += val;
        val = node->val;

        if (node->left != nullptr) {
            val = f(node->left, node->val);
        }

        return val;
    };

    (void)f(root, 0);
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

        auto ret = convertBST(r);
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

        auto ret = convertBST(r);
        assert(ret->val == 1);
        assert(ret->right->val == 1);

        delete ret;
    }
    return 0;
}
