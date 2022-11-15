#include <cassert>

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

int countNodes(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);

        int ret = countNodes(r);
        assert(ret == 6);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        int ret = countNodes(r);
        assert(ret == 1);
        delete r;
    }
    {
        int ret = countNodes(nullptr);
        assert(ret == 0);
    }
    return 0;
}
