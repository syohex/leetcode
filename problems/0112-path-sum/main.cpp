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

bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
        return false;
    }

    std::function<bool(TreeNode * p, int sum, int acc)> f;
    f = [&f](TreeNode *p, int sum, int acc) -> bool {
        if (p->left == nullptr && p->right == nullptr) {
            if (acc + p->val == sum) {
                return true;
            }

            return false;
        }

        if (p->left != nullptr) {
            if (f(p->left, sum, acc + p->val)) {
                return true;
            }
        }
        if (p->right != nullptr) {
            if (f(p->right, sum, acc + p->val)) {
                return true;
            }
        }

        return false;
    };

    return f(root, sum, 0);
}

int main() {
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->right->right->right = new TreeNode(1);

        assert(hasPathSum(root, 22));
    }
    return 0;
}
