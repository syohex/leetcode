#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

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

int getMinimumDifference(TreeNode *root) {
    std::vector<TreeNode *> q;
    q.push_back(root);

    std::vector<int> v;

    while (!q.empty()) {
        TreeNode *p = q.back();
        q.pop_back();

        if (p == nullptr) {
            continue;
        }

        v.push_back(p->val);

        q.push_back(p->left);
        q.push_back(p->right);
    }

    std::sort(v.begin(), v.end());

    int ret = std::numeric_limits<int>::max();
    for (size_t i = 0; i < v.size() - 1; ++i) {
        ret = std::min(ret, std::abs(v[i + 1] - v[i]));
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(6);

        int ret = getMinimumDifference(r);
        assert(ret == 1);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(0);
        r->right = new TreeNode(48);
        r->right->left = new TreeNode(12);
        r->right->right = new TreeNode(49);

        int ret = getMinimumDifference(r);
        assert(ret == 1);

        delete r;
    }
    return 0;
}
