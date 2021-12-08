#include <cassert>
#include <functional>
#include <cmath>

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

int findTilt(TreeNode *root) {
    std::function<int(TreeNode * node)> f;
    int ret = 0;
    f = [&](TreeNode *node) -> int {
        if (node == nullptr) {
            return 0;
        }

        int left = f(node->left);
        int right = f(node->right);

        ret += std::abs(left - right);
        return left + right + node->val;
    };

    (void)f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        assert(findTilt(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(9);
        r->right->right = new TreeNode(7);
        assert(findTilt(r) == 15);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(21);
        r->left = new TreeNode(7);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->left->left->left = new TreeNode(3);
        r->left->left->right = new TreeNode(3);
        r->right = new TreeNode(14);
        r->right->left = new TreeNode(2);
        r->right->right = new TreeNode(2);
        assert(findTilt(r) == 9);
        delete r;
    }
    return 0;
}
