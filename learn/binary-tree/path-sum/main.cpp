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

bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
        return false;
    }

    std::function<bool(TreeNode * node, int acc)> f;
    f = [&f, &sum](TreeNode *node, int acc) -> bool {
        acc += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return acc == sum;
        }

        bool left = false;
        if (node->left != nullptr) {
            left = f(node->left, acc);
        }

        bool right = false;
        if (!left && node->right != nullptr) {
            right = f(node->right, acc);
        }

        return left || right;
    };

    return f(root, 0);
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(11);
        r->left->left->left = new TreeNode(7);
        r->left->left->right = new TreeNode(2);
        r->right = new TreeNode(8);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(4);
        r->right->right->right = new TreeNode(1);

        assert(hasPathSum(r, 22));
        assert(!hasPathSum(r, 5));
    }
    return 0;
}
