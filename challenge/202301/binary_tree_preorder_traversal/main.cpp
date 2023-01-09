#include <cassert>
#include <vector>
#include <functional>
#include <memory>

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
    std::function<void(TreeNode * node, std::vector<int> & acc)> f;
    f = [&f](TreeNode *node, std::vector<int> &acc) {
        if (node == nullptr) {
            return;
        }

        acc.push_back(node->val);
        f(node->left, acc);
        f(node->right, acc);
    };

    std::vector<int> ret;
    f(root, ret);
    return ret;
}

int main() {
    {
        auto *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        std::vector<int> expected{1, 2, 3};

        auto ret = preorderTraversal(r);
        assert(ret == expected);
        delete r;
    }
    {
        auto ret = preorderTraversal(nullptr);
        assert(ret.empty());
    }
    {
        auto *r = new TreeNode(1);
        std::vector<int> expected{1};
        auto ret = preorderTraversal(r);
        assert(ret == expected);
        delete r;
    }

    return 0;
}
