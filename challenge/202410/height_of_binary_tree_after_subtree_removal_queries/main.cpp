#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
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

std::vector<int> treeQueries(TreeNode *root, const std::vector<int> &queries) {
    std::map<int, int> acc;
    std::map<int, int> height;

    std::function<int(TreeNode * node, std::map<int, int> & height)> set_height;
    set_height = [&](TreeNode *node, std::map<int, int> &height) -> int {
        if (node == nullptr) {
            return -1;
        }

        int left_height = set_height(node->left, height);
        int right_height = set_height(node->right, height);

        height[node->val] = 1 + std::max(left_height, right_height);
        return height[node->val];
    };

    std::function<void(TreeNode * node, int depth, int max_height)> f;
    f = [&](TreeNode *node, int depth, int max_height) {
        if (node == nullptr) {
            return;
        }

        acc[node->val] = max_height;

        int left_max = depth + (node->left != nullptr ? height[node->left->val] + 1: 0);
        int right_max = depth + (node->right != nullptr ? height[node->right->val] + 1 : 0);

        f(node->left, depth + 1, std::max(max_height, right_max));
        f(node->right, depth + 1, std::max(max_height, left_max));
    };

    set_height(root, height);
    f(root, 0, 0);

    std::vector<int> ret;
    for (int query : queries) {
        ret.push_back(acc[query]);
    }
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(5);
        r->right->left = new TreeNode(3);
        r->right->left->left = new TreeNode(2);
        r->right->left->right = new TreeNode(4);

        std::vector<int> queries{3, 5, 4, 2, 4};
        std::vector<int> expected{1, 0, 3, 3, 3};

        auto ret = treeQueries(r, queries);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(5);
        r->right->right->right = new TreeNode(7);

        std::vector<int> queries{4};
        std::vector<int> expected{2};

        auto ret = treeQueries(r, queries);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(8);
        r->left->left = new TreeNode(2);
        r->left->left->left = new TreeNode(4);
        r->left->left->right = new TreeNode(6);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(9);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(7);

        std::vector<int> queries{3, 2, 4, 8};
        std::vector<int> expected{3, 2, 3, 2};

        auto ret = treeQueries(r, queries);
        assert(ret == expected);

        delete r;
    }
    return 0;
}
