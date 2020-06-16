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

TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<TreeNode *(TreeNode *, int, int, int)> f;
    f = [&f](TreeNode *node, int min, int max, int depth) -> TreeNode * {
        if (node->left == nullptr && node->right == nullptr) {
            return (node->val >= min && node->val <= max) ? node : nullptr;
        }

        TreeNode *leftSideNode = nullptr;
        if (node->left != nullptr) {
            leftSideNode = f(node->left, min, max, depth + 1);
            if (leftSideNode == nullptr) {
                delete node->left;
                node->left = nullptr;
            } else {
                node->left = leftSideNode;
            }
        }

        TreeNode *rightSideNode = nullptr;
        if (node->right != nullptr) {
            rightSideNode = f(node->right, min, max, depth + 1);
            if (rightSideNode == nullptr) {
                delete node->right;
                node->right = nullptr;
            } else {
                node->right = rightSideNode;
            }
        }

        if (node->val >= min && node->val <= max) {
            return node;
        }

        if (leftSideNode != nullptr && rightSideNode != nullptr) {
            // possible case ?? There are no rules in this case
            return nullptr;
        }
        if (leftSideNode != nullptr && rightSideNode == nullptr) {
            return leftSideNode;
        }
        if (leftSideNode == nullptr && rightSideNode != nullptr) {
            return rightSideNode;
        }

        return nullptr;
    };

    auto rootNode = f(root, L, R, 0);
    if (rootNode == nullptr) {
        return nullptr;
    }

    return rootNode;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(0);
        tree->right = new TreeNode(2);

        auto ret = trimBST(tree, 1, 2);
        assert(ret->val = 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 2);
        assert(ret->right->left == nullptr);
        assert(ret->right->right == nullptr);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(3);
        tree->left = new TreeNode(0);
        tree->left->right = new TreeNode(2);
        tree->left->right->left = new TreeNode(1);
        tree->right = new TreeNode(4);

        auto ret = trimBST(tree, 1, 3);
        assert(ret->val = 3);
        assert(ret->left->val == 2);
        assert(ret->left->right == nullptr);
        assert(ret->left->left->val == 1);
        assert(ret->left->left->left == nullptr);
        assert(ret->left->left->right == nullptr);
        assert(ret->right == nullptr);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->right = new TreeNode(2);

        auto ret = trimBST(tree, 2, 4);
        assert(ret->val = 2);
        assert(ret->left == nullptr);
        assert(ret->right == nullptr);

        delete tree;
    }
    return 0;
}
