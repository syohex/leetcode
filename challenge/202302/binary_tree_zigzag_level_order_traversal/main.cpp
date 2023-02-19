#include <cassert>
#include <functional>
#include <vector>
#include <cstddef>
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
    std::vector<std::vector<int>> v;
    std::function<void(TreeNode * node, size_t depth)> f;
    f = [&](TreeNode *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        if (v.size() < depth + 1) {
            v.resize(depth + 1);
        }

        v[depth].push_back(node->val);
        f(node->left, depth + 1);
        f(node->right, depth + 1);
    };

    f(root, 0);

    for (size_t i = 0; i < v.size(); ++i) {
        if (i % 2 == 1) {
            std::reverse(v[i].begin(), v[i].end());
        }
    }

    return v;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        std::vector<std::vector<int>> expected{{3}, {20, 9}, {15, 7}};
        auto ret = zigzagLevelOrder(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        std::vector<std::vector<int>> expected{{1}};
        auto ret = zigzagLevelOrder(r);
        assert(ret == expected);

        delete r;
    }
    {
        auto ret = zigzagLevelOrder(nullptr);
        assert(ret.empty());
    }
    return 0;
}
