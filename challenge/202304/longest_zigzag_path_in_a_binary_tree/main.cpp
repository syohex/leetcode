#include <cassert>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

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

int longestZigZag(TreeNode *root) {
    std::function<int(TreeNode * node, int depth, bool left)> f;
    f = [&](TreeNode *node, int depth, bool left) -> int {
        if (node == nullptr) {
            return depth - 1;
        }

        int ret = depth;
        if (left) {
            ret = std::max(ret, f(node->left, depth + 1, false));
            ret = std::max(ret, f(node->right, 1, true));
        } else {
            ret = std::max(ret, f(node->right, depth + 1, true));
            ret = std::max(ret, f(node->left, 1, false));
        }

        return ret;
    };

    return std::max(f(root, 0, true), f(root, 0, false));
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(1);
        r->right->right->left = new TreeNode(1);
        r->right->right->left->right = new TreeNode(1);
        r->right->right->left->right->right = new TreeNode(1);
        r->right->right->right = new TreeNode(1);

        int ret = longestZigZag(r);
        assert(ret == 3);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->left->right->left = new TreeNode(1);
        r->left->right->left->right = new TreeNode(1);
        r->left->right->right = new TreeNode(1);
        r->right = new TreeNode(1);

        int ret = longestZigZag(r);
        assert(ret == 4);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        int ret = longestZigZag(r);
        assert(ret == 0);

        delete r;
    }
    return 0;
}
