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

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node, size_t level)> f;
    f = [&f, &ret](TreeNode *node, size_t level) {
        if (ret.size() < level + 1) {
            ret.resize(level + 1);
        }
        ret[level].push_back(node->val);

        if (node->left != nullptr) {
            f(node->left, level + 1);
        }
        if (node->right != nullptr) {
            f(node->right, level + 1);
        }
    };

    f(root, 0);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        auto ret = levelOrder(r);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{3}));
        assert((ret[1] == std::vector<int>{9, 20}));
        assert((ret[2] == std::vector<int>{15, 7}));
        delete r;
    }
    return 0;
}
