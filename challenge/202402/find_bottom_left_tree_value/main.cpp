#include <cassert>
#include <queue>

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

int findBottomLeft(TreeNode *root) {
    int ret = 0;
    std::deque<TreeNode *> q;
    q.push_back(root);

    while (!q.empty()) {
        ret = q.front()->val;

        int len = q.size();
        for (int i = 0; i < len; ++i) {
            TreeNode *node = q.front();
            q.pop_front();

            if (node->left != nullptr) {
                q.push_back(node->left);
            }
            if (node->right != nullptr) {
                q.push_back(node->right);
            }
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);
        int ret = findBottomLeft(r);
        assert(ret == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(5);
        r->right->left->left = new TreeNode(7);
        r->right->right = new TreeNode(6);
        int ret = findBottomLeft(r);
        assert(ret == 7);
        delete r;
    }
    return 0;
}
