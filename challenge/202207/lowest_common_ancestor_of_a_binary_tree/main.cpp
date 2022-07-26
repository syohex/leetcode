#include <cassert>
#include <functional>
#include <vector>
#include <algorithm>
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::function<int(TreeNode * node, int target, int depth, std::vector<TreeNode *> &ancestors)> f;
    f = [&](TreeNode *node, int target, int depth, std::vector<TreeNode *> &ancestors) -> int {
        if (node == nullptr) {
            return -1;
        }

        if (ancestors.size() < depth) {
            ancestors.resize(depth);
        }

        ancestors[depth - 1] = node;

        if (node->val == target) {
            return depth;
        }

        int ret = f(node->left, target, depth + 1, ancestors);
        if (ret != -1) {
            return ret;
        }

        return f(node->right, target, depth + 1, ancestors);
    };

    std::vector<TreeNode *> p_ancestors, q_ancestors;
    int p_depth = f(root, p->val, 1, p_ancestors);
    int q_depth = f(root, q->val, 1, q_ancestors);

    int len = std::min(p_depth, q_depth);
    TreeNode *prev = nullptr;
    for (int i = 0; i < len; ++i) {
        if (p_ancestors[i] != q_ancestors[i]) {
            return prev;
        }

        prev = p_ancestors[i];
    }

    return prev;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(6);
        r->left->right = new TreeNode(2);
        r->left->right->left = new TreeNode(7);
        r->left->right->right = new TreeNode(4);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(8);

        auto ret = lowestCommonAncestor(r, r->left, r->right);
        assert(ret == r);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(6);
        r->left->right = new TreeNode(2);
        r->left->right->left = new TreeNode(7);
        r->left->right->right = new TreeNode(4);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(8);

        auto ret = lowestCommonAncestor(r, r->left, r->left->right->right);
        assert(ret == r->left);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        auto ret = lowestCommonAncestor(r, r, r->left);
        assert(ret == r);

        delete r;
    }
    return 0;
}