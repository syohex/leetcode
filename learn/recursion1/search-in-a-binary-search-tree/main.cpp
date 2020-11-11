#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<TreeNode *(TreeNode * node, int v)> f;
    f = [&f](TreeNode *node, int v) -> TreeNode * {
        if (node->val == v) {
            return node;
        }

        if (v < node->val && node->left != nullptr) {
            auto n = f(node->left, v);
            if (n != nullptr) {
                return n;
            }
        }

        if (v > node->val && node->right != nullptr) {
            auto n = f(node->right, v);
            if (n != nullptr) {
                return n;
            }
        }

        return nullptr;
    };

    return f(root, val);
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(7);

        assert(searchBST(r, 2) == r->left);
        assert(searchBST(r, 10) == nullptr);
    }
    return 0;
}
