#include <cassert>
#include <algorithm>
#include <functional>
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

int diameterOfBinaryTree(TreeNode *root) {
    std::function<int(TreeNode * node, int &acc)> f;
    f = [&](TreeNode *node, int &acc) -> int {
        if (node == nullptr) {
            return 0;
        }

        int left = f(node->left, acc);
        int right = f(node->right, acc);

        acc = std::max(acc, left + right);

        return 1 + std::max(left, right);
    };

    int ret = 0;
    f(root, ret);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);

        int ret = diameterOfBinaryTree(r);
        assert(ret == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        int ret = diameterOfBinaryTree(r);
        assert(ret == 1);
        delete r;
    }
    return 0;
}
