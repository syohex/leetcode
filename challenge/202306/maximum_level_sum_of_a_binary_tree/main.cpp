#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cstdio>

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

int maxLevelSum(TreeNode *root) {
    std::vector<std::pair<TreeNode *, int>> q;
    q.push_back({root, 1});

    std::map<int, int> m;
    while (!q.empty()) {
        auto [node, level] = q.back();
        q.pop_back();
        if (node == nullptr) {
            continue;
        }

        m[level] += node->val;

        q.push_back({node->left, level + 1});
        q.push_back({node->right, level + 1});
    }

    int ret = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    for (const auto &[k, v] : m) {
        if (v > max) {
            max = v;
            ret = k;
        }
        if (v == max && k < ret) {
            ret = k;
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(7);
        r->left->left = new TreeNode(7);
        r->left->right = new TreeNode(-8);
        r->right = new TreeNode(0);

        int ret = maxLevelSum(r);
        assert(ret == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(989);
        r->right = new TreeNode(10250);
        r->right->left = new TreeNode(98693);
        r->right->right = new TreeNode(-89388);
        r->right->right->right = new TreeNode(-32127);

        int ret = maxLevelSum(r);
        assert(ret == 2);
        delete r;
    }
    return 0;
}
