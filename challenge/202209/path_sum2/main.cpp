#include <cassert>
#include <vector>
#include <functional>
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

std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return {};
    }

    std::function<void(TreeNode * node, int sum, int targetSum, std::vector<int> &vals, std::vector<std::vector<int>> &ret)> f;
    f = [&f](TreeNode *node, int sum, int targetSum, std::vector<int> &vals, std::vector<std::vector<int>> &ret) {
        sum += node->val;
        vals.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            if (sum == targetSum) {
                ret.push_back(vals);
            }
        } else {
            if (node->left != nullptr) {
                f(node->left, sum, targetSum, vals, ret);
            }
            if (node->right != nullptr) {
                f(node->right, sum, targetSum, vals, ret);
            }
        }

        vals.pop_back();
    };

    std::vector<std::vector<int>> ret;
    std::vector<int> vals;
    f(root, 0, targetSum, vals, ret);

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(11);
        r->left->left->left = new TreeNode(7);
        r->left->left->right = new TreeNode(2);
        r->right = new TreeNode(8);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(4);
        r->right->right->left = new TreeNode(5);
        r->right->right->right = new TreeNode(1);

        std::vector<std::vector<int>> expected{{5, 4, 11, 2}, {5, 8, 4, 5}};
        auto ret = pathSum(r, 22);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        auto ret = pathSum(r, 5);
        assert(ret.empty());

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        auto ret = pathSum(r, 0);
        assert(ret.empty());

        delete r;
    }
    {
        auto ret = pathSum(nullptr, 0);
        assert(ret.empty());
    }
    return 0;
}