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

TreeNode *searchBST(TreeNode *root, int val) {
    TreeNode *p = root;

    while (p != nullptr) {
        if (val == p->val) {
            return p;
        }

        if (val < p->val) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    return nullptr;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(7);

        auto ret = searchBST(r, 2);
        assert(ret == r->left);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(7);

        auto ret = searchBST(r, 5);
        assert(ret == nullptr);

        delete r;
    }
    return 0;
}
