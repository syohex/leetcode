#include <cassert>
#include <functional>
#include <algorithm>
#include <climits>
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

int minDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode * node, int depth)> f;
    f = [&f](TreeNode *node, int depth) {
        if (node->left == nullptr && node->right == nullptr) {
            return depth + 1;
        }

        int left_depth = INT_MAX;
        if (node->left != nullptr) {
            left_depth = f(node->left, depth + 1);
        }
        int right_depth = INT_MAX;
        if (node->right != nullptr) {
            right_depth = f(node->right, depth + 1);
        }

        return std::min(left_depth, right_depth);
    };

    return f(root, 0);
}

int main() {
    {
        TreeNode *t = new TreeNode(3);
        t->left = new TreeNode(9);
        t->right = new TreeNode(20);
        t->right->left = new TreeNode(15);
        t->right->right = new TreeNode(7);
        assert(minDepth(t) == 2);
        delete t;
    }
    {
        TreeNode *t = new TreeNode(2);
        t->right = new TreeNode(3);
        t->right->right = new TreeNode(4);
        t->right->right->right = new TreeNode(5);
        t->right->right->right->right = new TreeNode(6);
        assert(minDepth(t) == 5);
        delete t;
    }

    return 0;
}
