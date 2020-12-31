#include <cassert>
#include <functional>
#include <vector>
#include <algorithm>

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

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

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

    for (size_t i = 0; i < ret.size(); ++i) {
        if (i % 2 == 1) {
            std::reverse(ret[i].begin(), ret[i].end());
        }
    }

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
            {20, 9},
            {15, 7},
        };

        auto ret = zigzagLevelOrder(r);
        assert(ret == expected);

        delete r;
    }
    return 0;
}
