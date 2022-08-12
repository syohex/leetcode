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
    std::function<bool(TreeNode * node, int val, std::vector<TreeNode *> &ancestors)> f;
    f = [&](TreeNode *node, int val, std::vector<TreeNode *> &ancestors) -> bool {
        if (node == nullptr) {
            return false;
        }

        ancestors.push_back(node);

        if (node->val == val) {
            return true;
        }

        if (f(node->left, val, ancestors)) {
            return true;
        }

        if (f(node->right, val, ancestors)) {
            return true;
        }

        ancestors.pop_back();
        return false;
    };

    std::vector<TreeNode *> p_ancestors;
    std::vector<TreeNode *> q_ancestors;

    (void)f(root, p->val, p_ancestors);
    (void)f(root, q->val, q_ancestors);

    size_t pos = std::min(p_ancestors.size(), q_ancestors.size());
    for (size_t i = 0; i < pos; ++i) {
        if (p_ancestors[i] != q_ancestors[i]) {
            return p_ancestors[i - 1];
        }
    }

    return p_ancestors[pos - 1];
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
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->left->right = new TreeNode(2);
        r->right = new TreeNode(4);

        auto ret = lowestCommonAncestor(r, r->left->right, r->right);
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

        auto ret = lowestCommonAncestor(r, r->left->right->left, r->left->right->right);
        assert(ret == r->left->right);

        delete r;
    }
    return 0;
}