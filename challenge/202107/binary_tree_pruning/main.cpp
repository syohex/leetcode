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

TreeNode *pruneTree(TreeNode *root) {
    std::function<bool(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> bool {
        if (node == nullptr) {
            return true;
        }

        bool ret_left = f(node->left);
        if (ret_left) {
            delete node->left;
            node->left = nullptr;
        }

        bool ret_right = f(node->right);
        if (ret_right) {
            delete node->right;
            node->right = nullptr;
        }

        if (node->val == 1) {
            return false;
        }

        return ret_left && ret_right;
    };

    return f(root) ? nullptr : root;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(0);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);
        auto ret = pruneTree(r);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 0);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(0);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(0);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);

        auto ret = pruneTree(r);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 1);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->left->left = new TreeNode(0);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(0);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);

        auto ret = pruneTree(r);
        assert(ret->val == 1);
        assert(ret->left->val == 1);
        assert(ret->left->left->val == 1);
        assert(ret->left->right->val == 1);
        assert(ret->left->left->left == nullptr);
        assert(ret->right->val == 0);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(0);
        r->right = new TreeNode(0);

        auto ret = pruneTree(r);
        assert(ret == nullptr);

        delete r;
    }
    return 0;
}