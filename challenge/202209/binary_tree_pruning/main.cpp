#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
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

        bool ret1 = f(node->left);
        if (ret1) {
            delete node->left;
            node->left = nullptr;
        }

        bool ret2 = f(node->right);
        if (ret2) {
            delete node->right;
            node->right = nullptr;
        }

        return ret1 && ret2 && node->val == 0;
    };

    if (f(root)) {
        delete root;
        return nullptr;
    }

    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(0);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);

        auto ret = pruneTree(r);

        assert(ret->val == 1);
        assert(ret->right->val == 0);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 1);
        delete ret;
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
        assert(ret->right->val == 1);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 1);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->left->left->left = new TreeNode(0);
        r->right = new TreeNode(0);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);

        auto ret = pruneTree(r);

        assert(ret->val == 1);
        assert(ret->left->val == 1);
        assert(ret->left->left->val == 1);
        assert(ret->left->left->left == nullptr);
        assert(ret->left->right->val == 1);
        assert(ret->right->val == 0);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 1);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->right = new TreeNode(0);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(1);
        r->right->left->left = new TreeNode(1);
        r->right->right->left = new TreeNode(1);

        auto ret = pruneTree(r);

        assert(ret->val == 0);
        assert(ret->right->val == 0);
        assert(ret->right->left->val == 1);
        assert(ret->right->right->val == 1);
        assert(ret->right->left->left->val == 1);
        assert(ret->right->right->left->val == 1);
        delete ret;
    }
    return 0;
}
