#include <cassert>
#include <functional>
#include <map>
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

int deepestLeavesSum(TreeNode *root) {
    std::map<int, int> m;
    std::function<int(TreeNode * node, int depth)> f;
    f = [&f, &m](TreeNode *node, int depth) -> int {
        if (node == nullptr) {
            return depth - 1;
        }

        int left = f(node->left, depth + 1);
        int right = f(node->right, depth + 1);

        m[depth] += node->val;
        return std::max(left, right);
    };

    int deepest = f(root, 0);
    return m[deepest];
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->left->left->left = new TreeNode(7);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(6);
        r->right->right->right = new TreeNode(8);

        assert(deepestLeavesSum(r) == 15);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(6);
        r->left = new TreeNode(7);
        r->right = new TreeNode(8);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(7);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(3);
        r->left->left->left = new TreeNode(9);
        r->left->right->left = new TreeNode(1);
        r->left->right->right = new TreeNode(4);
        r->right->right->right = new TreeNode(5);

        assert(deepestLeavesSum(r) == 19);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(42);
        assert(deepestLeavesSum(r) == 42);
        delete r;
    }
    return 0;
}