#include <cassert>
#include <functional>
#include <vector>
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

int pathSum(TreeNode *root, int sum) {
    int ret = 0;
    std::function<void(TreeNode * node, std::vector<std::int64_t> & acc, int depth)> f;
    f = [&](TreeNode *node, std::vector<std::int64_t> &acc, int depth) {
        if (node == nullptr) {
            return;
        }

        acc[depth] = node->val;
        if (acc[depth] == sum) {
            ++ret;
        }

        for (int i = 0; i < depth; ++i) {
            acc[i] += node->val;
            if (acc[i] == sum) {
                ++ret;
            }
        }

        f(node->left, acc, depth + 1);
        f(node->right, acc, depth + 1);

        for (int i = 0; i < depth; ++i) {
            acc[i] -= node->val;
        }
    };

    std::vector<std::int64_t> sums(1000, 0);
    f(root, sums, 0);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(3);
        r->left->left->left = new TreeNode(3);
        r->left->left->right = new TreeNode(-2);
        r->left->right = new TreeNode(2);
        r->left->right->right = new TreeNode(1);
        r->right = new TreeNode(-3);
        r->right->right = new TreeNode(11);

        assert(pathSum(r, 8) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->right = new TreeNode(8);
        r->left->left = new TreeNode(11);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(4);
        r->left->left->left = new TreeNode(7);
        r->left->left->right = new TreeNode(2);
        r->right->right->left = new TreeNode(5);
        r->right->right->right = new TreeNode(1);

        assert(pathSum(r, 22) == 3);
        delete r;
    }
    assert(pathSum(nullptr, 10) == 0);
    return 0;
}
