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

TreeNode *convertBST(TreeNode *root) {
    if (root == nullptr) {
        return root;
    }

    std::function<int(TreeNode * node, int acc)> f;
    f = [&f](TreeNode *node, int acc) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            node->val += acc;
            return node->val;
        }

        int right = acc;
        if (node->right != nullptr) {
            right = f(node->right, acc);
        }

        node->val += right;

        int left = node->val;
        if (node->left != nullptr) {
            left = f(node->left, node->val);
        }

        return left;
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
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(0);
        r->right = new TreeNode(2);

        auto ret = convertBST(r);
        assert(ret->val == 3);
        assert(ret->left->val == 3);
        assert(ret->right->val == 2);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(2);
        r->right = new TreeNode(4);
        r->left->left = new TreeNode(1);

        auto ret = convertBST(r);
        assert(ret->val == 7);
        fprintf(stderr, "## val=%d\n", ret->left->val);
        assert(ret->left->val == 9);
        assert(ret->right->val == 4);
        assert(ret->left->left->val == 10);
        delete ret;
    }
    return 0;
}
