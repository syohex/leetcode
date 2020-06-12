#include <cassert>
#include <vector>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> ret;
    if (root == nullptr) {
        return ret;
    }

    std::vector<std::vector<int>> nums;
    std::function<void(TreeNode *, int)> f;
    f = [&f, &nums](TreeNode *n, int level) {
        if (static_cast<size_t>(level) >= nums.size()) {
            nums.resize(level);
        }
        nums[level - 1].push_back(n->val);

        if (n->left != nullptr) {
            f(n->left, level + 1);
        }
        if (n->right != nullptr) {
            f(n->right, level + 1);
        }
    };

    f(root, 1);

    for (const auto &v : nums) {
        double sum = 0;
        for (int i : v) {
            sum += i;
        }

        ret.push_back(sum / v.size());
    }

    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(3);
        tree->left = new TreeNode(9);
        tree->right = new TreeNode(20);
        tree->right->left = new TreeNode(15);
        tree->right->right = new TreeNode(7);
        std::vector<double> expected{3, 14.5, 11};

        auto got = averageOfLevels(tree);
        assert(got == expected);
        delete tree;
    }
    return 0;
}
