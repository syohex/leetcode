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

int goodNodes(TreeNode *root) {
    int ret = 0;

    std::function<void(TreeNode * node, TreeNode * max_parent)> f;
    f = [&f, &ret](TreeNode *node, TreeNode *max_parent) {
        if (node == nullptr) {
            return;
        }

        TreeNode *p;
        if (max_parent == nullptr || node->val >= max_parent->val) {
            p = node;
            ++ret;
        } else {
            p = max_parent;
        }

        f(node->left, p);
        f(node->right, p);
    };

    f(root, nullptr);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(3);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(5);
        assert(goodNodes(r) == 4);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(2);
        assert(goodNodes(r) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        assert(goodNodes(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(9);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        assert(goodNodes(r) == 1);
        delete r;
    }
    return 0;
}
