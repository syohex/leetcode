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

void recoverTree(TreeNode *root) {
    std::vector<TreeNode *> nums;

    std::function<void(TreeNode * node, std::vector<TreeNode *> & nums)> f;
    f = [&f](TreeNode *node, std::vector<TreeNode *> &nums) {
        if (node == nullptr) {
            return;
        }

        f(node->left, nums);
        nums.push_back(node);
        f(node->right, nums);
    };

    f(root, nums);

    int len = nums.size();
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    for (int i = 0; i < len - 1; ++i) {
        if (nums[i]->val > nums[i + 1]->val) {
            second = nums[i + 1];
            if (first == nullptr) {
                first = nums[i];
            }
        }
    }

    std::swap(first->val, second->val);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->right = new TreeNode(2);

        recoverTree(r);

        assert(r->val == 3);
        assert(r->left->val == 1);
        assert(r->left->right->val == 2);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(2);

        recoverTree(r);

        assert(r->val == 2);
        assert(r->left->val == 1);
        assert(r->right->val == 4);
        assert(r->right->left->val == 3);

        delete r;
    }
    return 0;
}