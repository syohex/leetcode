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

bool isCousins(TreeNode *root, int x, int y) {
    struct NodeDepth {
        TreeNode *parent;
        int depth;
    };

    std::function<bool(TreeNode *, int, TreeNode *, int, NodeDepth &)> f;
    f = [&f](TreeNode *node, int n, TreeNode *parent, int depth, NodeDepth &ret) -> bool {
        if (node->val == n) {
            ret.parent = parent;
            ret.depth = depth;
            return true;
        }

        if (node->left != nullptr) {
            if (f(node->left, n, node, depth + 1, ret)) {
                return true;
            }
        }
        if (node->right != nullptr) {
            if (f(node->right, n, node, depth + 1, ret)) {
                return true;
            }
        }

        return false;
    };

    NodeDepth xRet, yRet;
    bool xFound = f(root, x, nullptr, 0, xRet);
    bool yFound = f(root, y, nullptr, 0, yRet);
    if (xFound && yFound) {
        if (xRet.parent != yRet.parent && xRet.depth == yRet.depth) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->left = new TreeNode(4);
        assert(!isCousins(tree, 4, 3));
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(4);
        tree->right = new TreeNode(3);
        tree->right->right = new TreeNode(5);
        assert(isCousins(tree, 5, 4));
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->right = new TreeNode(4);
        assert(!isCousins(tree, 2, 3));
        delete tree;
    }
    return 0;
}
