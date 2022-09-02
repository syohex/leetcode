#include <cassert>
#include <functional>
#include <vector>
#include <utility>

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
    struct Data {
        double sum;
        int count;
    };

    std::vector<Data> v;
    std::vector<std::pair<TreeNode *, size_t>> q;
    q.push_back({root, 0});

    while (!q.empty()) {
        auto p = q.back();
        q.pop_back();

        TreeNode *node = p.first;
        int level = p.second;

        if (v.size() < level + 1) {
            v.resize(level + 1);
        }

        v[level].sum += node->val;
        v[level].count += 1;

        if (node->left != nullptr) {
            q.push_back({node->left, level + 1});
        }
        if (node->right != nullptr) {
            q.push_back({node->right, level + 1});
        }
    }

    std::vector<double> ret;
    for (const auto &d : v) {
        ret.push_back(d.sum / d.count);
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

        std::vector<double> expected{3, 14.5, 11};
        auto ret = averageOfLevels(r);
        assert(ret == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->left->left = new TreeNode(15);
        r->left->right = new TreeNode(7);
        r->right = new TreeNode(20);

        std::vector<double> expected{3, 14.5, 11};
        auto ret = averageOfLevels(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}