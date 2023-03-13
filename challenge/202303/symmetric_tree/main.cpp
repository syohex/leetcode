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

bool isSymmetric(TreeNode *root) {
    std::function<bool(TreeNode * left, TreeNode * right)> f;
    f = [&](TreeNode *left, TreeNode *right) -> bool {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return f(left->left, right->right) && f(left->right, right->left);
    };

    return f(root, root);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(4);
        r->right->right = new TreeNode(3);
        assert(isSymmetric(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(3);
        assert(!isSymmetric(r));
        delete r;
    }
    return 0;
}
