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

int goodNodes(TreeNode *root) {
    std::function<int(TreeNode * node, int max)> f;
    f = [&f](TreeNode *node, int max) -> int {
        if (node == nullptr) {
            return 0;
        }

        int ret = node->val >= max ? 1 : 0;
        int new_max = std::max(max, node->val);
        ret += f(node->left, new_max);
        ret += f(node->right, new_max);
        return ret;
    };

    return f(root, std::numeric_limits<int>::min());
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(3);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(5);

        auto ret = goodNodes(r);
        assert(ret == 4);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(2);

        auto ret = goodNodes(r);
        assert(ret == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(9);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);

        auto ret = goodNodes(r);
        assert(ret == 1);
        delete r;
    }
    return 0;
}