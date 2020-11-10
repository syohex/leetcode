#include <cassert>
#include <functional>
#include <vector>

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

std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node)> f;
    f = [&f, &ret](TreeNode *node) {
        if (node->left != nullptr) {
            f(node->left);
        }

        ret.push_back(node->val);

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

        auto ret = inorderTraversal(r);
        assert((ret == std::vector<int>{1, 3, 2}));
        delete r;
    }
    {
        auto ret = inorderTraversal(nullptr);
        assert(ret.empty());
    }
    {
        TreeNode *r = new TreeNode(1);

        auto ret = inorderTraversal(r);
        assert((ret == std::vector<int>{1}));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        auto ret = inorderTraversal(r);
        assert((ret == std::vector<int>{2, 1}));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);

        auto ret = inorderTraversal(r);
        assert((ret == std::vector<int>{1, 2}));
        delete r;
    }
    return 0;
}
