#include <cassert>
#include <functional>
#include <tuple>
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

TreeNode *lcaDeepestLeaves(TreeNode *root) {
    using Data = std::tuple<int, TreeNode *>;
    std::function<Data(TreeNode * node, int depth)> f;
    f = [&f](TreeNode *node, int depth) -> Data {
        if (node == nullptr) {
            return {depth, nullptr};
        }

        auto [left_depth, ret1] = f(node->left, depth + 1);
        auto [right_depth, ret2] = f(node->right, depth + 1);

        if (left_depth == right_depth) {
            return {left_depth, node};
        }

        if (left_depth < right_depth) {
            return {right_depth, ret2};
        }

        return {left_depth, ret1};
    };

    auto [node, ret] = f(root, 1);
    return ret;
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
        auto ret = lcaDeepestLeaves(r);
        assert(ret->val == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        auto ret = lcaDeepestLeaves(r);
        assert(ret->val == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(2);
        auto ret = lcaDeepestLeaves(r);
        assert(ret->val == 2);
        delete r;
    }
    return 0;
}