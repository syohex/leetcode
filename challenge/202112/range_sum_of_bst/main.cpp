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

int rangeSumBST(TreeNode *root, int low, int high) {
    std::function<int(TreeNode * node)> f;
    f = [&](TreeNode *node) -> int {
        if (node == nullptr) {
            return 0;
        }

        int ret = 0;
        if (node->val >= low && node->val <= high) {
            ret += node->val;
        }

        ret += f(node->left);
        ret += f(node->right);
        return ret;
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(7);
        r->right = new TreeNode(15);
        r->right->right = new TreeNode(18);
        assert(rangeSumBST(r, 7, 15) == 32);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(3);
        r->left->left->left = new TreeNode(1);
        r->left->right = new TreeNode(7);
        r->left->right->left = new TreeNode(6);
        r->right = new TreeNode(15);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(18);
        assert(rangeSumBST(r, 6, 10) == 23);
        delete r;
    }
    return 0;
}
