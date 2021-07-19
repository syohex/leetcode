#include <cassert>
#include <functional>
#include <vector>
#include <algorithm>

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
    std::function<bool(TreeNode * node, size_t depth, TreeNode * target, std::vector<TreeNode *> & v)> f;
    f = [&f](TreeNode *node, size_t depth, TreeNode *target, std::vector<TreeNode *> &v) -> bool {
        if (node == nullptr) {
            return false;
        }

        if (v.size() < depth + 1) {
            v.resize(depth + 1);
        }

        v[depth] = node;
        if (node->val == target->val) {
            v.resize(depth + 1);
            return true;
        }

        return f(node->left, depth + 1, target, v) || f(node->right, depth + 1, target, v);
    };

    std::vector<TreeNode *> pv;
    std::vector<TreeNode *> qv;

    (void)f(root, 0, p, pv);
    (void)f(root, 0, q, qv);

    int len = std::min(pv.size(), qv.size());
    for (int i = len - 1; i >= 0; --i) {
        if (pv[i] == qv[i]) {
            return pv[i];
        }
    }

    return nullptr;
}

int main() {
    {
        TreeNode *r = new TreeNode(6);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(4);
        r->left->right->left = new TreeNode(3);
        r->left->right->right = new TreeNode(5);
        r->right = new TreeNode(8);
        r->right->left = new TreeNode(7);
        r->right->right = new TreeNode(9);

        auto ret = lowestCommonAncestor(r, r->left, r->right);
        assert(ret == r);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(6);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(4);
        r->left->right->left = new TreeNode(3);
        r->left->right->right = new TreeNode(5);
        r->right = new TreeNode(8);
        r->right->left = new TreeNode(7);
        r->right->right = new TreeNode(9);

        auto ret = lowestCommonAncestor(r, r->left, r->left->right);
        assert(ret == r->left);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);

        auto ret = lowestCommonAncestor(r, r, r->left);
        assert(ret == r);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->left->right = new TreeNode(2);

        auto ret = lowestCommonAncestor(r, r->left->right, r->right);
        assert(ret == r);
        delete r;
    }
    return 0;
}
