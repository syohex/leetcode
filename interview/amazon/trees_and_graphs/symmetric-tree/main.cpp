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
    std::function<bool(TreeNode * n1, TreeNode * n2)> f;
    f = [&f](TreeNode *n1, TreeNode *n2) -> bool {
        if (n1 == nullptr && n2 == nullptr) {
            return true;
        }

        if (n1 == nullptr || n2 == nullptr) {
            return false;
        }

        if (n1->val != n2->val) {
            return false;
        }

        return f(n1->left, n2->right) && f(n1->right, n2->left);
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
    { assert(isSymmetric(nullptr)); }
    return 0;
}
