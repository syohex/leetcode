#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int rangeSumBST(TreeNode *root, int low, int high) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode * node, int low, int high)> f;
    f = [&f](TreeNode *node, int row, int high) -> int {
        int val = node->val;
        if (!(val >= row && val <= high)) {
            val = 0;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left, row, high);
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right, row, high);
        }

        return val + left + right;
    };

    return f(root, low, high);
}

int main() {
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->right = new TreeNode(15);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(7);
        r->right->right = new TreeNode(18);

        assert(rangeSumBST(r, 7, 15) == 32);
    }
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->right = new TreeNode(15);
        r->left->left = new TreeNode(3);
        r->left->left->left = new TreeNode(1);
        r->left->right = new TreeNode(7);
        r->left->right->left = new TreeNode(6);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(18);

        assert(rangeSumBST(r, 6, 10) == 23);
    }
    return 0;
}