#include <cassert>
#include <vector>
#include <map>
#include <functional>
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

std::vector<std::vector<int>> verticalTraversal(TreeNode *root) {
    std::function<void(TreeNode * node, int row, int col, std::map<int, std::map<int, std::vector<int>>> &m)> f;
    f = [&f](TreeNode *node, int row, int col, std::map<int, std::map<int, std::vector<int>>> &m) {
        if (node == nullptr) {
            return;
        }

        m[col][row].push_back(node->val);

        f(node->left, row + 1, col - 1, m);
        f(node->right, row + 1, col + 1, m);
    };

    std::map<int, std::map<int, std::vector<int>>> m;
    f(root, 0, 0, m);

    std::vector<std::vector<int>> ret;
    for (auto &it : m) {
        std::vector<int> tmp;
        for (auto &it2 : it.second) {
            auto &nums = it2.second;
            std::sort(nums.begin(), nums.end());

            for (int n : nums) {
                tmp.push_back(n);
            }
        }

        ret.push_back(std::move(tmp));
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
            {9},
            {3, 15},
            {20},
            {7},
        };
        auto ret = verticalTraversal(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);

        std::vector<std::vector<int>> expected{{4}, {2}, {1, 5, 6}, {3}, {7}};
        auto ret = verticalTraversal(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(6);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(5);
        r->right->right = new TreeNode(7);

        std::vector<std::vector<int>> expected{{4}, {2}, {1, 5, 6}, {3}, {7}};
        auto ret = verticalTraversal(r);
        assert(ret == expected);

        delete r;
    }
    return 0;
}