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

TreeNode *replaceValueInTree(TreeNode *root) {
    std::deque<std::pair<TreeNode *, int>> q;
    q.push_back({root, root->val});

    while (!q.empty()) {
        int sum = 0;
        int len = q.size();
        for (const auto &p : q) {
            sum += p.first->val;
        }

        for (int i = 0; i < len; ++i) {
            auto [node, v] = q.front();
            q.pop_front();

            node->val = sum - v;
            int s = (node->left != nullptr ? node->left->val : 0) + (node->right != nullptr ? node->right->val : 0);
            if (node->left != nullptr) {
                q.push_back({node->left, s});
            }
            if (node->right != nullptr) {
                q.push_back({node->right, s});
            }
        }
    }

    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(10);
        r->right = new TreeNode(9);
        r->right->right = new TreeNode(7);

        auto *ret = replaceValueInTree(r);
        assert(ret->val == 0);
        assert(ret->left->val == 0);
        assert(ret->left->left->val == 7);
        assert(ret->left->right->val == 7);
        assert(ret->right->val == 0);
        assert(ret->right->right->val == 11);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(2);
        r->right = new TreeNode(1);

        auto *ret = replaceValueInTree(r);
        assert(ret->val == 0);
        assert(ret->left->val == 0);
        assert(ret->right->val == 0);
        delete ret;
    }
    return 0;
}