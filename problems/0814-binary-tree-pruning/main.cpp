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
        }

        if (right != nullptr) {
            if (!right->Equal(a->right)) {
                return false;
            }
        }

        return true;
    }
};

TreeNode *pruneTree(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::function<bool(TreeNode **)> f;
    f = [&f](TreeNode **node) -> bool {
        if ((*node)->left == nullptr && (*node)->right == nullptr) {
            return (*node)->val == 1;
        }

        bool leftHasOneNode;
        if ((*node)->left != nullptr) {
            leftHasOneNode = f(&((*node)->left));
            if (!leftHasOneNode) {
                delete (*node)->left;
                (*node)->left = nullptr;
            }
        } else {
            leftHasOneNode = false;
        }

        bool rightHasOneNode;
        if ((*node)->right != nullptr) {
            rightHasOneNode = f(&((*node)->right));
            if (!rightHasOneNode) {
                delete (*node)->right;
                (*node)->right = nullptr;
            }
        } else {
            rightHasOneNode = false;
        }

        if ((*node)->val == 1) {
            return true;
        }

        return leftHasOneNode || rightHasOneNode;
    };

    (void)f(&root);

    return root;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->right = new TreeNode(0);
        tree->right->left = new TreeNode(0);
        tree->right->right = new TreeNode(1);

        auto ret = pruneTree(tree);

        TreeNode *expected = new TreeNode(1);
        expected->right = new TreeNode(0);
        expected->right->right = new TreeNode(1);

        assert(ret->Equal(expected));
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(0);
        tree->left->left = new TreeNode(0);
        tree->left->right = new TreeNode(0);
        tree->right = new TreeNode(1);
        tree->right->left = new TreeNode(0);
        tree->right->right = new TreeNode(1);

        auto ret = pruneTree(tree);

        TreeNode *expected = new TreeNode(1);
        expected->right = new TreeNode(1);
        expected->right->right = new TreeNode(1);

        assert(ret->Equal(expected));
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(1);
        tree->left->left = new TreeNode(1);
        tree->left->right = new TreeNode(1);
        tree->left->left->left = new TreeNode(0);
        tree->right = new TreeNode(0);
        tree->right->left = new TreeNode(0);
        tree->right->right = new TreeNode(1);

        auto ret = pruneTree(tree);

        TreeNode *expected = new TreeNode(1);
        expected->left = new TreeNode(1);
        expected->left->left = new TreeNode(1);
        expected->left->right = new TreeNode(1);
        expected->right = new TreeNode(0);
        expected->right->right = new TreeNode(1);

        assert(ret->Equal(expected));
    }
    {
        TreeNode *tree = new TreeNode(0);
        tree->right = new TreeNode(0);
        tree->right->left = new TreeNode(1);
        tree->right->right = new TreeNode(1);

        auto ret = pruneTree(tree);

        TreeNode *expected = new TreeNode(1);
        expected->left = new TreeNode(1);
        expected->left->left = new TreeNode(1);
        expected->left->right = new TreeNode(1);
        expected->right = new TreeNode(0);
        expected->right->right = new TreeNode(1);

        assert(ret->Equal(expected));
    }

    return 0;
}
