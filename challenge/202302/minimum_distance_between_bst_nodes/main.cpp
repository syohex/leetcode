#include <cassert>
#include <vector>
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

int minDiffInBST(TreeNode *root) {
    std::vector<TreeNode *> q{root};
    std::vector<int> v;
    while (!q.empty()) {
        TreeNode *node = q.back();
        q.pop_back();

        if (node == nullptr) {
            continue;
        }

        v.push_back(node->val);

        q.push_back(node->left);
        q.push_back(node->right);
    }

    std::sort(v.begin(), v.end());

    int ret = v.back() - v.front();
    for (size_t i = 0; i < v.size() - 1; ++i) {
        ret = std::min(ret, v[i + 1] - v[i]);
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

        int ret = minDiffInBST(r);
        assert(ret == 1);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(1);
        r->right = new TreeNode(48);
        r->right->left = new TreeNode(12);
        r->right->right = new TreeNode(49);

        int ret = minDiffInBST(r);
        assert(ret == 1);

        delete r;
    }

    return 0;
}
