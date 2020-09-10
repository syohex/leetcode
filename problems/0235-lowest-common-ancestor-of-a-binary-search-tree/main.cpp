#include <cassert>
#include <functional>
#include <cstdio>
#include <map>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    struct NodeInfo {
        int count = 0;
        int depth = 0;
    };

    std::map<TreeNode *, NodeInfo> m;
    std::function<bool(TreeNode * node, TreeNode * t, int depth)> f;
    f = [&f, &m](TreeNode *node, TreeNode *t, int depth) -> bool {
        if (node->val == t->val) {
            ++m[node].count;
            m[node].depth = depth;
            return true;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return false;
        }

        bool ret = false;
        if (node->left != nullptr) {
            ret = f(node->left, t, depth + 1);
            if (ret) {
                ++m[node].count;
                m[node].depth = depth;
            }
        }
        if (!ret && node->right != nullptr) {
            ret = f(node->right, t, depth + 1);
            if (ret) {
                ++m[node].count;
                m[node].depth = depth;
            }
        }

        return ret;
    };

    (void)f(root, p, 0);
    (void)f(root, q, 0);

    TreeNode *ret = nullptr;
    int max = -1;
    for (const auto &it : m) {
        if (it.second.count >= 2) {
            if (max < it.second.depth) {
                max = it.second.depth;
                ret = it.first;
            }
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(6);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(0);
        tree->left->right = new TreeNode(4);
        tree->left->right->left = new TreeNode(3);
        tree->left->right->right = new TreeNode(5);
        tree->right = new TreeNode(8);
        tree->right->left = new TreeNode(7);
        tree->right->right = new TreeNode(9);

        TreeNode *p = tree->left;
        TreeNode *q = tree->right;
        auto ret = lowestCommonAncestor(tree, p, q);
        assert(ret->val == 6);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(6);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(0);
        tree->left->right = new TreeNode(4);
        tree->left->right->left = new TreeNode(3);
        tree->left->right->right = new TreeNode(5);
        tree->right = new TreeNode(8);
        tree->right->left = new TreeNode(7);
        tree->right->right = new TreeNode(9);

        TreeNode *p = tree->left;
        TreeNode *q = tree->left->right;
        auto ret = lowestCommonAncestor(tree, p, q);
        assert(ret->val == 2);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(6);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(0);
        tree->left->right = new TreeNode(4);
        tree->left->right->left = new TreeNode(3);
        tree->left->right->right = new TreeNode(5);
        tree->right = new TreeNode(8);
        tree->right->left = new TreeNode(7);
        tree->right->right = new TreeNode(9);

        TreeNode *p = tree->left->right->left;
        TreeNode *q = tree->left->right->right;
        auto ret = lowestCommonAncestor(tree, p, q);
        assert(ret->val == 4);
        delete tree;
    }
    return 0;
}
