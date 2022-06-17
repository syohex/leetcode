#include <cassert>
#include <functional>
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

int minCameraCover(TreeNode *root) {
    std::function<std::vector<int>(TreeNode * node)> f;
    f = [&](TreeNode *node) -> std::vector<int> {
        if (node == nullptr) {
            return {0, 0, 2000};
        }

        auto left = f(node->left);
        auto right = f(node->right);

        int left_min = std::min(left[1], left[2]);
        int right_min = std::min(right[1], right[2]);

        int v0 = left[1] + right[1];
        int v1 = std::min(left[2] + right_min, right[2] + left_min);
        int v2 = 1 + std::min(left[0], left_min) + std::min(right[0], right_min);

        return {v0, v1, v2};
    };

    auto ret = f(root);
    return std::min(ret[1], ret[2]);
}

int main() {
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(0);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(0);

        assert(minCameraCover(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(0);
        r->left->left = new TreeNode(0);
        r->left->left->left = new TreeNode(0);
        r->left->left->left->right = new TreeNode(0);

        assert(minCameraCover(r) == 2);
        delete r;
    }
    return 0;
}