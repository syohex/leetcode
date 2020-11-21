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
    if (root == nullptr) {
        return true;
    }

    std::function<bool(TreeNode * r1, TreeNode * r2)> f;
    f = [&f](TreeNode *r1, TreeNode *r2) -> bool {
        if (r1->left != nullptr) {
            if (r2->right == nullptr) {
                return false;
            }

            if (!f(r1->left, r2->right)) {
                return false;
            }
        } else {
            if (r2->right != nullptr) {
                return false;
            }
        }

        if (r1->right != nullptr) {
            if (r2->left == nullptr) {
                return false;
            }

            if (!f(r1->right, r2->left)) {
                return false;
            }
        } else {
            if (r2->left != nullptr) {
                return false;
            }
        }

        return r1->val == r2->val;
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
