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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
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

    std::function<bool(TreeNode *, TreeNode *)> f;
    f = [&f](TreeNode *a, TreeNode *b) -> bool {
        if (a->left == nullptr && a->right == nullptr && b->left == nullptr && b->right == nullptr) {
            return a->val == b->val;
        }

        if (a->left != nullptr) {
            if (b->right == nullptr) {
                return false;
            }

            if (!f(a->left, b->right)) {
                return false;
            }
        } else {
            if (b->right != nullptr) {
                return false;
            }
        }

        if (a->right != nullptr) {
            if (b->left == nullptr) {
                return false;
            }
            if (!f(a->right, b->left)) {
                return false;
            }
        } else {
            if (b->left != nullptr) {
                return false;
            }
        }

        return a->val == b->val;
    };

    return f(root, root);
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(3);
        tree->left->right = new TreeNode(4);
        tree->right = new TreeNode(2);
        tree->right->left = new TreeNode(4);
        tree->right->right = new TreeNode(3);

        assert(isSymmetric(tree));
        delete tree;
    }
    {

        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->right = new TreeNode(3);
        tree->right = new TreeNode(2);
        tree->right->right = new TreeNode(3);

        assert(!isSymmetric(tree));
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);

        assert(!isSymmetric(tree));
        delete tree;
    }

    return 0;
}
