#include <cassert>
#include <queue>
#include <limits>

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

bool isEvenOddTree(TreeNode *root) {
    std::deque<TreeNode *> q;
    q.push_back(root);

    bool is_even = true;
    while (!q.empty()) {
        int len = q.size();
        int prev = is_even ? -1 : std::numeric_limits<int>::max();

        for (int i = 0; i < len; ++i) {
            TreeNode *node = q.front();
            q.pop_front();

            if (is_even) {
                if (node->val % 2 != 1 || prev >= node->val) {
                    return false;
                }
            } else {
                if (node->val % 2 != 0 || prev <= node->val) {
                    return false;
                }
            }

            if (node->left != nullptr) {
                q.push_back(node->left);
            }
            if (node->right != nullptr) {
                q.push_back(node->right);
            }

            prev = node->val;
        }

        is_even = !is_even;
    }

    return true;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(10);
        r->left->left = new TreeNode(3);
        r->left->left->left = new TreeNode(12);
        r->left->left->right = new TreeNode(8);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(7);
        r->right->left->left = new TreeNode(6);
        r->right->right = new TreeNode(9);
        r->right->right->right = new TreeNode(2);
        assert(isEvenOddTree(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(7);
        assert(!isEvenOddTree(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(9);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(7);
        assert(!isEvenOddTree(r));
        delete r;
    }
    return 0;
}
