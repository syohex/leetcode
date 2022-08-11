#include <cassert>
#include <functional>
#include <limits>
#include <cstdint>

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

bool isValidBST(TreeNode *root) {
    std::function<bool(TreeNode * node, std::int64_t min, std::int64_t max)> f;
    f = [&](TreeNode *node, std::int64_t min, std::int64_t max) -> bool {
        if (node == nullptr) {
            return true;
        }

        if (!(node->val > min && node->val < max)) {
            return false;
        }

        return f(node->left, min, node->val) && f(node->right, node->val, max);
    };

    return f(root, std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);
        auto ret = isValidBST(r);
        assert(ret);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(5);
        auto ret = isValidBST(r);
        assert(!ret);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(1);
        auto ret = isValidBST(r);
        assert(!ret);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->right = new TreeNode(5);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(2);
        r->right->left = new TreeNode(4);
        r->right->right = new TreeNode(6);
        auto ret = isValidBST(r);
        assert(ret);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(10);
        r->left = new TreeNode(5);
        r->right = new TreeNode(15);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(10);
        auto ret = isValidBST(r);
        assert(!ret);
        delete r;
    }
    return 0;
}
