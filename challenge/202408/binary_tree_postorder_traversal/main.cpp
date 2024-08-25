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

std::vector<int> postorderTraversal(TreeNode *root) {
    std::function<void(TreeNode * node, std::vector<int> & acc)> f;
    f = [&](TreeNode *node, std::vector<int> &acc) {
        if (node == nullptr) {
            return;
        }

        f(node->left, acc);
        f(node->right, acc);
        acc.push_back(node->val);
    };

    std::vector<int> acc;
    f(root, acc);
    return acc;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        std::vector<int> expected{3, 2, 1};
        auto ret = postorderTraversal(r);
        assert(ret == expected);
        delete r;
    }
    {
        auto ret = postorderTraversal(nullptr);
        assert(ret.empty());
    }
    {
        TreeNode *r = new TreeNode(1);
        std::vector<int> expected{1};
        auto ret = postorderTraversal(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}
