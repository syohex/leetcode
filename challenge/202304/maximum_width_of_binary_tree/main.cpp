#include <cassert>
#include <queue>
#include <algorithm>
#include <cstdint>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

int widthOfBinaryTree(TreeNode *root) {
    std::queue<std::pair<TreeNode *, std::int64_t>> q;
    q.push({root, 0});

    std::int64_t ret = 1;
    while (!q.empty()) {
        int len = q.size();
        auto first_value = q.front().second;
        auto last_value = q.back().second;
        ret = std::max(ret, last_value - first_value + 1);

        std::int64_t base = -1;
        for (int i = 0; i < len; ++i) {
            auto [node, value] = q.front();
            q.pop();

            if (base == -1) {
                base = value;
            }

            if (node->left != nullptr) {
                q.push({node->left, (value * 2) - base});
            }
            if (node->right != nullptr) {
                q.push({node->right, (value * 2 + 1) - base});
            }
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(9);

        int ret = widthOfBinaryTree(r);
        assert(ret == 4);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->left->left->left = new TreeNode(6);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(9);
        r->right->right->left = new TreeNode(7);

        int ret = widthOfBinaryTree(r);
        assert(ret == 7);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->right = new TreeNode(2);

        int ret = widthOfBinaryTree(r);
        assert(ret == 2);
        delete r;
    }
    return 0;
}
