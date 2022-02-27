#include <cassert>
#include <queue>
#include <algorithm>
#include <limits>
#include <cstdint>
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

int widthOfBinaryTree(TreeNode *root) {
    struct Data {
        TreeNode *node;
        std::int64_t num;
    };

    std::deque<Data> q;
    q.push_back({root, 0});

    std::int64_t ret = std::numeric_limits<std::int64_t>::min();
    while (!q.empty()) {
        size_t len = q.size();
        std::int64_t base = 0;
        for (size_t i = 0; i < len; ++i) {
            Data d = q.front();
            q.pop_front();

            if (i == 0) {
                base = d.num;
            }

            ret = std::max(ret, d.num - base + 1);

            if (d.node->left != nullptr) {
                q.push_back({d.node->left, (d.num * 2) - base});
            }
            if (d.node->right != nullptr) {
                q.push_back({d.node->right, (d.num * 2 + 1) - base});
            }
        }
    }

    return static_cast<int>(ret);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(9);

        assert(widthOfBinaryTree(r) == 4);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(3);

        assert(widthOfBinaryTree(r) == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->right = new TreeNode(2);

        assert(widthOfBinaryTree(r) == 2);
        delete r;
    }
    return 0;
}
