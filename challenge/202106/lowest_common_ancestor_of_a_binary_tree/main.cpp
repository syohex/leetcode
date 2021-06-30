#include <cassert>
#include <vector>
#include <functional>
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
    std::function<bool(TreeNode * node, size_t depth, TreeNode * target, std::vector<TreeNode *> & acc)> f;
    f = [&f](TreeNode *node, size_t depth, TreeNode *target, std::vector<TreeNode *> &acc) -> bool {
        if (node == nullptr) {
            return false;
        }

        if (acc.size() < depth + 1) {
            acc.resize(depth + 1);
        }

        acc[depth] = node;
        if (node->val == target->val) {
            acc.resize(depth + 1);
            return true;
        }

        ++depth;
        return f(node->left, depth, target, acc) || f(node->right, depth, target, acc);
    };

    std::vector<TreeNode *> s1;
    std::vector<TreeNode *> s2;

    (void)f(root, 0, p, s1);
    (void)f(root, 0, q, s2);

    int index = std::min(s1.size(), s2.size()) - 1;
    while (index >= 0) {
        if (s1[index] == s2[index]) {
            return s1[index];
        }

        --index;
    }

    // never reach here
    return nullptr;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(5);
        r->right = new TreeNode(1);
        r->left->left = new TreeNode(6);
        r->left->right = new TreeNode(2);
        r->left->right->left = new TreeNode(7);
        r->left->right->right = new TreeNode(4);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(0);

        auto ret = lowestCommonAncestor(r, r->left, r->right);
        assert(ret == r);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(5);
        r->right = new TreeNode(1);
        r->left->left = new TreeNode(6);
        r->left->right = new TreeNode(2);
        r->left->right->left = new TreeNode(7);
        r->left->right->right = new TreeNode(4);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(0);

        auto ret = lowestCommonAncestor(r, r->left, r->left->right->right);
        assert(ret == r->left);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        auto ret = lowestCommonAncestor(r, r, r->left);
        assert(ret == r);
    }
    return 0;
}
