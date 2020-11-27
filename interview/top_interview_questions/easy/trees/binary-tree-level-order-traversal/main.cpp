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
    std::function<void(TreeNode * node, size_t depth)> f;
    f = [&f, &ret](TreeNode *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        if (ret.size() < depth + 1) {
            ret.resize(depth + 1);
        }

        ret[depth].push_back(node->val);

        f(node->left, depth + 1);
        f(node->right, depth + 1);
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

        std::vector<std::vector<int>> expected{
            {3},
            {9, 20},
            {15, 7},
        };

        auto ret = levelOrder(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}
