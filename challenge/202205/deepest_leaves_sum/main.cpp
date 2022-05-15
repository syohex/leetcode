#include <cassert>
#include <queue>
#include <cstddef>

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

int deepestLeavesSum(TreeNode *root) {
    std::deque<TreeNode *> q;
    q.push_back(root);

    int ret = 0;
    while (!q.empty()) {
        size_t len = q.size();
        ret = 0;
        for (size_t i = 0; i < len; ++i) {
            TreeNode *n = q.front();
            q.pop_front();

            ret += n->val;

            if (n->left != nullptr) {
                q.push_back(n->left);
            }
            if (n->right != nullptr) {
                q.push_back(n->right);
            }
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->left->left = new TreeNode(7);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(6);
        r->right->right->right = new TreeNode(8);

        assert(deepestLeavesSum(r) == 15);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(6);
        r->left = new TreeNode(7);
        r->right = new TreeNode(8);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(7);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(3);
        r->left->left->left = new TreeNode(9);
        r->left->right->left = new TreeNode(1);
        r->left->right->right = new TreeNode(4);
        r->right->right->right = new TreeNode(5);

        assert(deepestLeavesSum(r) == 19);
        delete r;
    }
    return 0;
}
