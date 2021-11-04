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

int sumOfLeftLeaves(TreeNode *root) {
    std::function<int(TreeNode * node, bool is_left)> f;
    f = [&](TreeNode *node, bool is_left) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            if (is_left) {
                return node->val;
            }

            return 0;
        }

        int sum = 0;
        if (node->left != nullptr) {
            sum += f(node->left, true);
        }
        if (node->right != nullptr) {
            sum += f(node->right, false);
        }

        return sum;
    };

    return f(root, false);
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);
        assert(sumOfLeftLeaves(r) == 24);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        assert(sumOfLeftLeaves(r) == 0);
        delete r;
    }
    return 0;
}