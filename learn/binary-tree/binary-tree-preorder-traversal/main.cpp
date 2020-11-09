#include <cassert>
#include <vector>
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

std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node)> f;
    f = [&f, &ret](TreeNode *node) {
        ret.push_back(node->val);
        if (node->left != nullptr) {
            f(node->left);
        }
        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        auto ret = preorderTraversal(r);
        assert((ret == std::vector<int>{1, 2, 3}));
        delete r;
    }
    {
        auto ret = preorderTraversal(nullptr);
        assert(ret.empty());
    }
    {
        TreeNode *r = new TreeNode(1);
        auto ret = preorderTraversal(r);
        assert((ret == std::vector<int>{1}));
        delete r;
    }
    return 0;
}
