#include <cassert>
#include <functional>
#include <print>

using namespace std;

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

TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    function<pair<TreeNode *, int>(TreeNode * node)> f;
    f = [&](TreeNode *node) -> pair<TreeNode *, int> {
        if (node == nullptr) {
            return {nullptr, 0};
        }

        auto [left_ret, left_depth] = f(node->left);
        auto [right_ret, right_depth] = f(node->right);

        if (left_depth > right_depth) {
            return {left_ret, left_depth + 1};
        }
        if (left_depth < right_depth) {
            return {right_ret, right_depth + 1};
        }

        return {node, left_depth + 1};
    };

    return f(root).first;
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
        auto *ret = subtreeWithAllDeepest(r);
        assert(ret == r->left->right);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        auto *ret = subtreeWithAllDeepest(r);
        assert(ret == r);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(1);
        r->left->right = new TreeNode(2);
        r->right = new TreeNode(3);
        auto *ret = subtreeWithAllDeepest(r);
        assert(ret == r->left->right);
        delete r;
    }
    return 0;
}
