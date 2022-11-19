#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>

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

int minimumOperations(TreeNode *root) {
    std::vector<TreeNode *> q;
    q.push_back(root);

    int ret = 0;
    while (!q.empty()) {
        std::vector<TreeNode *> tmp;
        std::vector<int> vals;

        for (const TreeNode *node : q) {
            vals.push_back(node->val);

            if (node->left != nullptr) {
                tmp.push_back(node->left);
            }
            if (node->right != nullptr) {
                tmp.push_back(node->right);
            }
        }

        std::vector<int> nums(q.size());
        std::iota(nums.begin(), nums.end(), 0);
        std::sort(nums.begin(), nums.end(), [&](int a, int b) { return vals[a] < vals[b]; });

        for (int i = 0; i < q.size(); ++i) {
            while (nums[i] != i) {
                std::swap(nums[i], nums[nums[i]]);
                ++ret;
            }
        }

        q = std::move(tmp);
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(7);
        r->left->right = new TreeNode(6);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(8);
        r->right->left->left = new TreeNode(9);
        r->right->right = new TreeNode(5);
        r->right->right->left = new TreeNode(10);

        int ret = minimumOperations(r);
        assert(ret == 3);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(7);
        r->left->right = new TreeNode(6);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(5);
        r->right->right = new TreeNode(4);

        int ret = minimumOperations(r);
        assert(ret == 3);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);

        int ret = minimumOperations(r);
        assert(ret == 0);

        delete r;
    }
    return 0;
}