#include <cassert>
#include <vector>
#include <functional>
#include <map>

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

TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
    std::map<int, int> inorder_index;
    int len = inorder.size();
    for (int i = 0; i < len; ++i) {
        inorder_index[inorder[i]] = i;
    }

    std::function<TreeNode *(int left, int right, int &index)> f;
    f = [&](int left, int right, int &index) -> TreeNode * {
        if (left > right) {
            return nullptr;
        }

        int val = preorder[index];
        ++index;

        TreeNode *node = new TreeNode(val);

        int base_index = inorder_index[val];
        node->left = f(left, base_index - 1, index);
        node->right = f(base_index + 1, right, index);

        return node;
    };

    int index = 0;
    return f(0, len - 1, index);
}

int main() {
    {
        std::vector<int> preorder{3, 9, 20, 15, 7};
        std::vector<int> inorder{9, 3, 15, 20, 7};

        auto r = buildTree(preorder, inorder);
        assert(r->val == 3);
        assert(r->left->val == 9);
        assert(r->left->left == nullptr);
        assert(r->left->right == nullptr);
        assert(r->right->val == 20);
        assert(r->right->left->val == 15);
        assert(r->right->left->left == nullptr);
        assert(r->right->left->right == nullptr);
        assert(r->right->right->val == 7);
        assert(r->right->right->left == nullptr);
        assert(r->right->right->right == nullptr);

        delete r;
    }
    {
        std::vector<int> preorder{-1};
        std::vector<int> inorder{-1};

        auto r = buildTree(preorder, inorder);
        assert(r->val == -1);
        assert(r->left == nullptr);
        assert(r->right == nullptr);

        delete r;
    }

    return 0;
}