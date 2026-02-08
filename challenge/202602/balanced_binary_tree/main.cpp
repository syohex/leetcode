#include <cassert>
#include <functional>
#include <cmath>
#include <algorithm>

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

bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    function<pair<int, bool>(TreeNode * node, int depth)> f;
    f = [&](TreeNode *node, int depth) -> pair<int, bool> {
        if (node == nullptr) {
            return {depth, true};
        }

        auto [depth1, ok1] = f(node->left, depth + 1);
        auto [depth2, ok2] = f(node->right, depth + 1);
        if (!ok1 || !ok2) {
            return {0, false};
        }

        bool ok = abs(depth1 - depth2) <= 1;
        return {max(depth1, depth2), ok};
    };

    return f(root, 0).second;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right->left = new TreeNode(6);
        r->left->left->left = new TreeNode(8);
        assert(isBalanced(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->right = new TreeNode(20);
        r->right->right = new TreeNode(7);
        assert(!isBalanced(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);
        assert(isBalanced(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(3);
        r->left->right->left = new TreeNode(4);
        r->left->right->right = new TreeNode(4);
        r->right = new TreeNode(2);
        assert(!isBalanced(r));
        delete r;
    }
    return 0;
}
