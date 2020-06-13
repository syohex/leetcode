#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(), left(l), right(r) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode * node, bool isLeft)> f;
    f = [&f](TreeNode *node, bool isLeft) -> int {
        if (isLeft && node->left == nullptr && node->right == nullptr) {
            return node->val;
        }

        int ret = 0;
        if (node->left != nullptr) {
            ret += f(node->left, true);
        }
        if (node->right != nullptr) {
            ret += f(node->right, false);
        }

        return ret;
    };

    return f(root, false);
}

int main() {
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        int sum = sumOfLeftLeaves(root);
        assert(sum == 24);
        delete root;
    }
    return 0;
}
