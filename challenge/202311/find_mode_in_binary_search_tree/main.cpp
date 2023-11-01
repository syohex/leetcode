#include <cassert>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

std::vector<int> findMode(TreeNode *root) {
    std::function<void(TreeNode * node, std::map<int, int> & m, int &max)> f;
    f = [&](TreeNode *node, std::map<int, int> &m, int &max) {
        if (node == nullptr) {
            return;
        }

        ++m[node->val];
        max = std::max(max, m[node->val]);

        f(node->left, m, max);
        f(node->right, m, max);
    };

    std::map<int, int> m;
    int max = -1;
    f(root, m, max);

    std::vector<int> ret;
    for (const auto &[k, v] : m) {
        if (v == max) {
            ret.push_back(k);
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(2);

        std::vector<int> expected{2};
        auto ret = findMode(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);

        std::vector<int> expected{0};
        auto ret = findMode(r);
        assert(ret == expected);

        delete r;
    }
    return 0;
}
