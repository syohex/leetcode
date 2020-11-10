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

std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node)> f;
    f = [&f, &ret](TreeNode *node) {
        if (node->left != nullptr) {
            f(node->left);
        }

        if (node->right != nullptr) {
            f(node->right);
        }

        ret.push_back(node->val);
    };

    f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);

        auto ret = postorderTraversal(r);
        assert((ret == std::vector<int>{3, 2, 1}));
        delete r;
    }
    {
        auto ret = postorderTraversal(nullptr);
        assert(ret.empty());
    }
    {
        TreeNode *r = new TreeNode(1);

        auto ret = postorderTraversal(r);
        assert((ret == std::vector<int>{1}));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        auto ret = postorderTraversal(r);
        assert((ret == std::vector<int>{2, 1}));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);

        auto ret = postorderTraversal(r);
        assert((ret == std::vector<int>{2, 1}));
        delete r;
    }
    return 0;
}
