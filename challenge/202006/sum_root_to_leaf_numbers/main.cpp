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

int sumNumbers(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode * node, int val)> f;
    f = [&f](TreeNode *node, int val) -> int {
        int new_val = (10 * val) + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return new_val;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left, new_val);
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right, new_val);
        }

        return left + right;
    };

    return f(root, 0);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        assert(sumNumbers(r) == 25);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(9);
        r->right = new TreeNode(0);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(1);
        assert(sumNumbers(r) == 1026);
        delete r;
    }
    return 0;
}