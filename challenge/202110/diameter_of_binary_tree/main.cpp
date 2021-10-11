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

int diameterOfBinaryTree(TreeNode *root) {
    std::function<int(TreeNode *node)> f;
    int ret = 0;
    f = [&](TreeNode *node) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left) + 1;
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right) + 1;
        }

        ret = std::max(ret, left + right);
        return std::max(left, right);
    };

    (void)f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        assert(diameterOfBinaryTree(r) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        assert(diameterOfBinaryTree(r) == 1);
        delete r;
    }
    return 0;
}