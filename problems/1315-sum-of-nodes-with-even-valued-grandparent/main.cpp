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

int sumEvenGrandparent(TreeNode *root) {
    int sum = 0;
    std::function<void(TreeNode * node, size_t depth, int grandParent, int parent)> f;
    f = [&f, &sum](TreeNode *node, size_t depth, int grandParent, int parent) {
        if (depth >= 2 && grandParent % 2 == 0) {
            sum += node->val;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1, parent, node->val);
        }
        if (node->right != nullptr) {
            f(node->right, depth + 1, parent, node->val);
        }
    };

    f(root, 0, -1, -1);
    return sum;
}

int main() {
    {
        TreeNode *tree = new TreeNode(6);
        tree->left = new TreeNode(7);
        tree->left->left = new TreeNode(2);
        tree->left->left->left = new TreeNode(9);
        tree->left->right = new TreeNode(7);
        tree->left->right->left = new TreeNode(1);
        tree->left->right->right = new TreeNode(4);
        tree->right = new TreeNode(8);
        tree->right->left = new TreeNode(1);
        tree->right->right = new TreeNode(3);
        tree->right->right->right = new TreeNode(5);
        assert(sumEvenGrandparent(tree) == 18);
        delete tree;
    }
    return 0;
}
