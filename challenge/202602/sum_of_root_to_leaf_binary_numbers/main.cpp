#include <cassert>
#include <functional>
#include <print>

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

int sumRootToLeaf(TreeNode *root) {
    std::function<void (TreeNode * node, int sum, int &acc)> f;
    f = [&](TreeNode *node, int sum, int &acc) {
        if (node == nullptr) {
            return;
        }

        sum = (sum << 1) + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            acc += sum;
            return;
        }

        f(node->left, sum, acc);
        f(node->right, sum, acc);
    };

    int ret = 0;
    f(root, 0, ret);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(0);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);
        int ret = sumRootToLeaf(r);
        assert(ret == 22);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        int ret = sumRootToLeaf(0);
        assert(ret == 0);
        delete r;
    }
    return 0;
}
