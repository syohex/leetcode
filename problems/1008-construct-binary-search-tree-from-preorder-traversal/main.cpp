#include <cassert>
#include <vector>

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

TreeNode *bstFromPreorder(const std::vector<int> &preorder) {
    if (preorder.empty()) {
        return nullptr;
    }

    TreeNode *ret = new TreeNode(preorder[0]);
    for (size_t i = 1; i < preorder.size(); ++i) {
        TreeNode *tmp = ret;
        while (true) {
            if (preorder[i] < tmp->val) {
                if (tmp->left == nullptr) {
                    tmp->left = new TreeNode(preorder[i]);
                    break;
                }

                tmp = tmp->left;
            } else {
                if (tmp->right == nullptr) {
                    tmp->right = new TreeNode(preorder[i]);
                    break;
                }

                tmp = tmp->right;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{8, 5, 1, 7, 10, 12};
        auto ret = bstFromPreorder(input);

        assert(ret != nullptr);
        assert(ret->val == 8);
        assert(ret->left->val == 5);
        assert(ret->left->left->val == 1);
        assert(ret->left->right->val == 7);
        assert(ret->right->val == 10);
        assert(ret->right->right->val == 12);
        assert(ret->left->left->left == nullptr);
        assert(ret->left->left->right == nullptr);
        assert(ret->left->right->left == nullptr);
        assert(ret->left->right->right == nullptr);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->left == nullptr);
        assert(ret->right->right->right == nullptr);

        delete ret;
    }
    return 0;
}
