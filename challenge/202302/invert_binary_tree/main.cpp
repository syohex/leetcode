#include <cassert>
#include <functional>
#include <algorithm>

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

TreeNode *invertTree(TreeNode *root) {
    std::function<TreeNode *(TreeNode * node)> f;
    f = [&](TreeNode *node) -> TreeNode * {
        if (node == nullptr) {
            return nullptr;
        }

        f(node->left);
        f(node->right);

        std::swap(node->left, node->right);
        return node;
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(7);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(9);

        auto ret = invertTree(r);
        assert(r->val == 4);
        assert(r->left->val == 7);
        assert(r->left->left->val == 9);
        assert(r->left->right->val == 6);
        assert(r->right->val == 2);
        assert(r->right->left->val == 3);
        assert(r->right->right->val == 1);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);

        auto ret = invertTree(r);
        assert(r->val == 2);
        assert(r->left->val == 3);
        assert(r->right->val == 1);
        delete ret;
    }
    {
        auto ret = invertTree(nullptr);
        assert(ret == nullptr);
    }

    return 0;
}
