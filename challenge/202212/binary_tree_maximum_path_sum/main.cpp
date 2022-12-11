#include <cassert>
#include <functional>
#include <algorithm>
#include <limits>

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

int maxPathSum(TreeNode *root) {
    std::function<int(TreeNode * node, int &max)> f;
    f = [&f](TreeNode *node, int &max) -> int {
        if (node == nullptr) {
            return 0;
        }

        int left = std::max(f(node->left, max), 0);
        int right = std::max(f(node->right, max), 0);

        int sum = node->val + left + right;
        max = std::max(max, sum);

        int big = std::max(left, right);
        max = std::max(max, big + node->val);
        return big + node->val;
    };

    int max = std::numeric_limits<int>::min();
    (void)f(root, max);
    return max;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        int ret = maxPathSum(r);
        assert(ret == 6);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(-1);
        r->right = new TreeNode(-2);

        int ret = maxPathSum(r);
        assert(ret == 2);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(-10);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        int ret = maxPathSum(r);
        assert(ret == 42);

        delete r;
    }
    return 0;
}
