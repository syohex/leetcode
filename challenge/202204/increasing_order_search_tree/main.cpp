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

TreeNode *increasingBST(TreeNode *root) {
    std::function<TreeNode *(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> TreeNode * {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode *ret1 = f(node->left);
        TreeNode *ret2 = f(node->right);

        TreeNode *p = ret1;
        TreeNode *prev = nullptr;

        while (p != nullptr) {
            prev = p;
            p = p->right;
        }

        node->left = nullptr;

        if (prev != nullptr) {
            prev->right = node;
            node->right = ret2;
            return ret1;
        }

        node->right = ret2;
        return node;
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->left->left->left = new TreeNode(1);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(8);
        r->right->right->left = new TreeNode(7);
        r->right->right->right = new TreeNode(9);

        auto ret = increasingBST(r);
        assert(ret->val == 1);
        assert(ret->right->val == 2);
        assert(ret->right->right->val == 3);
        assert(ret->right->right->right->val == 4);
        assert(ret->right->right->right->right->val == 5);
        assert(ret->right->right->right->right->right->val == 6);
        assert(ret->right->right->right->right->right->right->val == 7);
        assert(ret->right->right->right->right->right->right->right->val == 8);
        assert(ret->right->right->right->right->right->right->right->right->val == 9);

        delete ret;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->right = new TreeNode(7);

        auto ret = increasingBST(r);
        assert(ret->val == 1);
        assert(ret->right->val == 5);
        assert(ret->right->right->val == 7);

        delete ret;
    }

    return 0;
}
