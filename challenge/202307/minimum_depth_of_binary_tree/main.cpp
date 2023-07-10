#include <cassert>
#include <queue>
#include <cstdio>

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

int minDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::deque<TreeNode *> q;
    q.push_back(root);

    int ret = 1;
    while (!q.empty()) {
        size_t len = q.size();
        for (size_t i = 0; i < len; ++i) {
            TreeNode *node = q.front();
            q.pop_front();

            if (node->left == nullptr && node->right == nullptr) {
                return ret;
            }

            if (node->left != nullptr) {
                q.push_back(node->left);
            }
            if (node->right != nullptr) {
                q.push_back(node->right);
            }
        }

        ++ret;
    }

    // never reach here
    return -1;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        int ret = minDepth(r);
        assert(ret == 2);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(4);
        r->right->right->right = new TreeNode(5);
        r->right->right->right->right = new TreeNode(6);

        int ret = minDepth(r);
        assert(ret == 5);

        delete r;
    }
    return 0;
}
