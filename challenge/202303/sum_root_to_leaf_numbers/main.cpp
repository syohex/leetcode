#include <cassert>
#include <functional>

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

int sumNumbers(TreeNode *root) {
    std::function<int(TreeNode * node, int num)> f;
    f = [&](TreeNode *node, int num) -> int {
        int sum = num * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return sum;
        }

        int left = 0;
        if (node->left != nullptr) {
            left = f(node->left, sum);
        }

        int right = 0;
        if (node->right != nullptr) {
            right = f(node->right, sum);
        }

        return left + right;
    };

    return f(root, 0);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        int ret = sumNumbers(r);
        assert(ret == 25);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(9);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(0);

        int ret = sumNumbers(r);
        assert(ret == 1026);
        delete r;
    }

    return 0;
}
