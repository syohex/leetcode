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

TreeNode *sortedArrayToBST(const std::vector<int> &nums) {
    std::function<TreeNode *(int left, int right, const std::vector<int> &nums)> f;
    f = [&](int left, int right, const std::vector<int> &nums) -> TreeNode * {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);

        node->left = f(left, mid - 1, nums);
        node->right = f(mid + 1, right, nums);

        return node;
    };

    return f(0, nums.size() - 1, nums);
}

int main() {
    {
        std::vector<int> nums{-10, -3, 0, 5, 9};
        auto ret = sortedArrayToBST(nums);
        assert(ret->val == 0);
        assert(ret->left->val == -10);
        assert(ret->left->right->val == -3);
        assert(ret->left->right->left == nullptr);
        assert(ret->left->right->right == nullptr);
        assert(ret->right->val == 5);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->val == 9);
        assert(ret->right->right->left == nullptr);
        assert(ret->right->right->right == nullptr);
    }
    {
        std::vector<int> nums{1, 3};
        auto ret = sortedArrayToBST(nums);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 3);
        assert(ret->right->left == nullptr);
        assert(ret->right->right == nullptr);
    }
    return 0;
}