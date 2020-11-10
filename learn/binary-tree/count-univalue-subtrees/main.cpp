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

int countUnivalSubtrees(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int ret = 0;
    std::function<bool(TreeNode * node)> f;
    f = [&f, &ret](TreeNode *node) -> bool {
        if (node->left == nullptr && node->right == nullptr) {
            ++ret;
            return true;
        }

        bool left = true;
        if (node->left != nullptr) {
            left = f(node->left);
            if (left) {
                left = node->val == node->left->val;
            }
        }

        bool right = true;
        if (node->right != nullptr) {
            right = f(node->right);
            if (right) {
                right = node->val == node->right->val;
            }
        }

        bool ok = left && right;
        if (ok) {
            ++ret;
        }

        return ok;
    };

    (void)f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->right = new TreeNode(5);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(5);
        r->right->right = new TreeNode(5);

        assert(countUnivalSubtrees(r) == 4);
        delete r;
    }
    return 0;
}
