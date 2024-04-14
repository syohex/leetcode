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

int sumOfLeftLeaves(TreeNode *root) {
    std::function<int(TreeNode * node, bool left)> f;
    f = [&](TreeNode *node, bool left) -> int {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            if (left) {
                return node->val;
            }

            return 0;
        }

        int lsum = f(node->left, true);
        int rsum = f(node->right, false);

        return lsum + rsum;
    };

    return f(root, false);
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        int ret = sumOfLeftLeaves(r);
        assert(ret == 24);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        int ret = sumOfLeftLeaves(r);
        assert(ret == 0);
        delete r;
    }
    return 0;
}
