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
    std::function<TreeNode *(int start, int end)> f;
    f = [&f, &nums](int start, int end) -> TreeNode * {
        if (start > end) {
            return nullptr;
        }
        size_t pos = (start + end) / 2;
        TreeNode *p = new TreeNode(nums[pos]);
        p->left = f(start, pos - 1);
        p->right = f(pos + 1, end);
        return p;
    };

    int len = nums.size();
    return f(0, len - 1);
}

int main() {
    {
        std::vector<int> nums{-10, -3, 0, 5, 9};
        auto ret = sortedArrayToBST(nums);
        assert(ret->val == 0);
        assert(ret->left->val == -10);
        assert(ret->left->right->val == -3);
        assert(ret->right->val == 5);
        assert(ret->right->right->val == 9);
        delete ret;
    }
    {
        std::vector<int> nums{1, 3};
        auto ret = sortedArrayToBST(nums);
        assert(ret->val == 1);
        assert(ret->left == nullptr);
        assert(ret->right->val == 3);
        delete ret;
    }
    return 0;
}
