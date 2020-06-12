#include <cassert>
#include <cstdio>

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

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }

    if (p == nullptr || q == nullptr) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    if (p->left != nullptr) {
        if (q->left == nullptr) {
            return false;
        }

        if (!isSameTree(p->left, q->left)) {
            return false;
        }
    } else {
        if (q->left != nullptr) {
            return false;
        }
    }

    if (p->right != nullptr) {
        if (q->right == nullptr) {
            return false;
        }

        if (!isSameTree(p->right, q->right)) {
            return false;
        }
    } else {
        if (q->right != nullptr) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        TreeNode *tree1 = new TreeNode(1);
        tree1->left = new TreeNode(2);
        tree1->right = new TreeNode(3);

        TreeNode *tree2 = new TreeNode(1);
        tree2->left = new TreeNode(2);
        tree2->right = new TreeNode(3);

        assert(isSameTree(tree1, tree2));
    }
    {
        TreeNode *tree1 = new TreeNode(1);
        tree1->left = new TreeNode(2);

        TreeNode *tree2 = new TreeNode(1);
        tree2->right = new TreeNode(2);

        assert(!isSameTree(tree1, tree2));
    }
    {
        TreeNode *tree1 = new TreeNode(1);
        tree1->left = new TreeNode(2);
        tree1->right = new TreeNode(1);

        TreeNode *tree2 = new TreeNode(1);
        tree2->left = new TreeNode(1);
        tree2->right = new TreeNode(2);

        assert(!isSameTree(tree1, tree2));
    }
    return 0;
}
