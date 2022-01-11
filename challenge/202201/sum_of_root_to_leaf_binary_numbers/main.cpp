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

int sumRootToLeaf(TreeNode *root) {
    std::function<int(TreeNode * node, int acc)> f;
    f = [&](TreeNode *node, int acc) -> int {
        int val = acc * 2 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return val;
        }

        int ret = 0;
        if (node->left != nullptr) {
            ret += f(node->left, val);
        }
        if (node->right != nullptr) {
            ret += f(node->right, val);
        }

        return ret;
    };

    return f(root, 0);
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

        assert(sumRootToLeaf(r) == 22);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        assert(sumRootToLeaf(r) == 0);
        delete r;
    }
    return 0;
}
