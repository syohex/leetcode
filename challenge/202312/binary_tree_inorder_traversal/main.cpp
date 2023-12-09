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

std::vector<int> inorderTraversal(TreeNode *root) {
    std::function<void(TreeNode * node, std::vector<int> & acc)> f;
    f = [&f](TreeNode *node, std::vector<int> &acc) {
        if (node == nullptr) {
            return;
        }

        f(node->left, acc);
        acc.push_back(node->val);
        f(node->right, acc);
    };

    std::vector<int> ret;
    f(root, ret);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        std::vector<int> expected{1, 3, 2};
        auto ret = inorderTraversal(r);
        assert(ret == expected);
        delete r;
    }
    {
        auto ret = inorderTraversal(nullptr);
        assert(ret.empty());
    }
    {
        TreeNode *r = new TreeNode(1);
        std::vector<int> expected{1};
        auto ret = inorderTraversal(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}
