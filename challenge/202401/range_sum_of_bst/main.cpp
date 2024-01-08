#include <cassert>
#include <vector>

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

int rangeSumBST(TreeNode *root, int low, int high) {
    std::vector<TreeNode *> q;
    q.push_back(root);

    int ret = 0;
    while (!q.empty()) {
        TreeNode *node = q.back();
        q.pop_back();

        if (node == nullptr) {
            continue;
        }

        if (node->val >= low && node->val <= high) {
            ret += node->val;
        }

        q.push_back(node->left);
        q.push_back(node->right);
    }
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(7);
        r->right = new TreeNode(15);
        r->right->right = new TreeNode(18);

        int ret = rangeSumBST(r, 7, 15);
        assert(ret == 32);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(3);
        r->left->left->left = new TreeNode(1);
        r->left->right = new TreeNode(7);
        r->left->right->left = new TreeNode(6);
        r->right = new TreeNode(15);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(18);

        int ret = rangeSumBST(r, 6, 10);
        assert(ret == 23);
        delete r;
    }
    return 0;
}
