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

TreeNode *trimBST(TreeNode *root, int low, int high) {
    std::function<TreeNode *(TreeNode * node, int low, int high)> f;
    f = [&f](TreeNode *node, int low, int high) -> TreeNode * {
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val >= low && node->val <= high) {
                return node;
            }

            return nullptr;
        }

        if (node->left != nullptr) {
            node->left = f(node->left, low, high);
        }

        if (node->right != nullptr) {
            node->right = f(node->right, low, high);
        }

        if (node->val >= low && node->val <= high) {
            return node;
        }

        auto ret = node->left != nullptr ? node->left : node->right;
        node->left = node->right = nullptr;
        delete node;

        return ret;
    };

    return f(root, low, high);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(0);
        r->right = new TreeNode(2);

        auto ret = trimBST(r, 1, 2);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 2);

        delete ret;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(0);
        r->right = new TreeNode(4);
        r->left->right = new TreeNode(2);
        r->left->right->left = new TreeNode(1);

        auto ret = trimBST(r, 1, 3);
        assert(ret->val == 3);
        assert(ret->left->val == 2);
        assert(ret->left->left->val == 1);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(1);
        auto ret = trimBST(r, 1, 2);
        assert(ret->val == 1);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        auto ret = trimBST(r, 1, 3);
        assert(ret->val == 1);
        assert(ret->right->val == 2);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        auto ret = trimBST(r, 2, 4);
        assert(ret->val == 2);
        assert(ret->right == nullptr);
        delete ret;
    }
    return 0;
}
