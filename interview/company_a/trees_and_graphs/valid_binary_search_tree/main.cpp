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

bool isValidBST(TreeNode *root) {
    std::function<bool(TreeNode * node, TreeNode * min, TreeNode * max)> f;
    f = [&f](TreeNode *node, TreeNode *min, TreeNode *max) -> bool {
        if (node == nullptr) {
            return true;
        }

        if (min != nullptr && node->val <= min->val) {
            return false;
        }
        if (max != nullptr && node->val >= max->val) {
            return false;
        }

        return f(node->left, min, node) && f(node->right, node, max);
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
    assert(isValidBST(nullptr));
    return 0;
}