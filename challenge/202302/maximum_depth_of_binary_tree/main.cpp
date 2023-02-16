#include <cassert>
#include <algorithm>
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

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int ret = 0;
    std::vector<std::pair<TreeNode *, int>> q;
    q.push_back({root, 1});

    while (!q.empty()) {
        auto [node, depth] = q.back();
        q.pop_back();

        ret = std::max(ret, depth);

        if (node->left != nullptr) {
            q.push_back({node->left, depth + 1});
        }
        if (node->right != nullptr) {
            q.push_back({node->right, depth + 1});
        }
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

        int ret = maxDepth(r);
        assert(ret == 3);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);

        int ret = maxDepth(r);
        assert(ret == 2);

        delete r;
    }
    return 0;
}
