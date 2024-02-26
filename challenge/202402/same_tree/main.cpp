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

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }

    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    assert(isSameTree(nullptr, nullptr));
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        r1->right = new TreeNode(3);
        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(2);
        r2->right = new TreeNode(3);

        assert(isSameTree(r1, r2));

        delete r1;
        delete r2;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        TreeNode *r2 = new TreeNode(1);
        r2->right = new TreeNode(2);

        assert(!isSameTree(r1, r2));

        delete r1;
        delete r2;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        r1->right = new TreeNode(1);
        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(1);
        r2->right = new TreeNode(2);

        assert(!isSameTree(r1, r2));

        delete r1;
        delete r2;
    }
    return 0;
}
