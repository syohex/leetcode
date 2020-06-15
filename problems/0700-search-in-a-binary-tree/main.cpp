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

    bool Equal(TreeNode *a) {
        if (a == nullptr) {
            return false;
        }
        if (val != a->val) {
            return false;
        }
        if (left != nullptr) {
            if (!left->Equal(a->left)) {
                return false;
            }
        } else {
            if (a->left != nullptr) {
                return false;
            }
        }
        if (right != nullptr) {
            if (!right->Equal(a->right)) {
                return false;
            }
        } else {
            if (a->right != nullptr) {
                return false;
            }
        }

        return true;
    }
};

TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<TreeNode *(TreeNode *, int)> f;
    f = [&f](TreeNode *node, int target) -> TreeNode * {
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == target) {
                return node;
            }

            return nullptr;
        }

        if (node->val == target) {
            return node;
        }
        if (node->left != nullptr) {
            auto n = f(node->left, target);
            if (n != nullptr) {
                return n;
            }
        }
        if (node->right != nullptr) {
            auto n = f(node->right, target);
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
        TreeNode *tree = new TreeNode(4);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(3);
        tree->right = new TreeNode(7);

        auto got = searchBST(tree, 2);
        assert(got == tree->left);
        assert(searchBST(tree, 5) == nullptr);
        delete tree;
    }
    return 0;
}
