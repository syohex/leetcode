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

std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<std::vector<int>> v;
    std::function<void(TreeNode * node, size_t level)> f;
    f = [&f, &v](TreeNode *node, size_t level) {
        if (node == nullptr) {
            return;
        }

        if (level + 1 >= v.size()) {
            v.resize(level + 1);
        }

        v[level].push_back(node->val);

        f(node->left, level + 1);
        f(node->right, level + 1);
    };

    f(root, 0);

    std::vector<double> ret;
    for (const auto &vals : v) {
        double d = 0;
        for (const auto val : vals) {
            d += val;
        }

        ret.push_back(d / vals.size());
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

        auto ret = averageOfLevels(r);
        assert((ret == std::vector<double>{3, 14.5, 11}));

        delete r;
    }
    return 0;
}
