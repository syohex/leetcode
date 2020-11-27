#include <cassert>
#include <functional>
#include <algorithm>

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

bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    std::function<bool(TreeNode * node, int *low, int *high)> f;
    f = [&f](TreeNode *node, int *low, int *high) -> bool {
        if (node == nullptr) {
            return true;
        }

        if (low != nullptr && node->val <= *low) {
            return false;
        }

        if (high != nullptr && node->val >= *high) {
            return false;
        }

        int *tmp = new int(node->val);
        if (!f(node->left, low, tmp)) {
            delete tmp;
            return false;
        }

        if (!f(node->right, tmp, high)) {
            delete tmp;
            return false;
        }

        delete tmp;
        return true;
    };

    return f(root, nullptr, nullptr);
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);
        assert(isValidBST(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(6);
        assert(!isValidBST(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(1);
        assert(!isValidBST(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->right = new TreeNode(15);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(20);
        assert(!isValidBST(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->right = new TreeNode(10);
        r->right->left = new TreeNode(8);
        r->right->left->right = new TreeNode(9);
        r->right->right = new TreeNode(16);
        assert(isValidBST(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(2);
        r->right = new TreeNode(5);
        r->right->left = new TreeNode(4);
        r->right->right = new TreeNode(6);
        assert(isValidBST(r));
        delete r;
    }

    return 0;
}
