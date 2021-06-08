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
    std::map<int, int> inorder_pos;
    int len = inorder.size();
    for (int i = 0; i < len; ++i) {
        inorder_pos[inorder[i]] = i;
    }

    std::function<TreeNode *(int left, int right)> f;
    int preorder_idx = 0;
    f = [&f, &preorder, &inorder_pos, &preorder_idx](int left, int right) -> TreeNode * {
        if (left > right) {
            return nullptr;
        }

        int root_value = preorder[preorder_idx++];
        TreeNode *root = new TreeNode(root_value);

        root->left = f(left, inorder_pos[root_value] - 1);
        root->right = f(inorder_pos[root_value] + 1, right);
        return root;
    };

    return f(0, len - 1);
}

int main() {
    {
        std::vector<int> preorder{3, 9, 20, 15, 7};
        std::vector<int> inorder{9, 3, 15, 20, 7};

        auto r = buildTree(preorder, inorder);
        assert(r->val == 3);
        assert(r->left->val == 9);
        assert(r->right->val == 20);
        assert(r->right->left->val == 15);
        assert(r->right->right->val == 7);
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
