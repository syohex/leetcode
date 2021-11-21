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

TreeNode *buildTree(const std::vector<int> &inorder, const std::vector<int> &postorder) {
    std::map<int, int> m;
    int len = inorder.size();
    for (int i = 0; i < len; ++i) {
        m[inorder[i]] = i;
    }

    int root_index = static_cast<int>(postorder.size()) - 1;

    std::function<TreeNode *(int left, int right)> f;
    f = [&](int left, int right) -> TreeNode * {
        if (left > right) {
            return nullptr;
        }

        int root_value = postorder[root_index];
        TreeNode *r = new TreeNode(root_value);

        --root_index;

        int index = m[root_value];
        r->right = f(index + 1, right);
        r->left = f(left, index - 1);
        return r;
    };

    return f(0, len - 1);
}

int main() {
    {
        std::vector<int> inorder{9, 3, 15, 20, 7};
        std::vector<int> postorder{9, 15, 7, 20, 3};
        auto r = buildTree(inorder, postorder);
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
        std::vector<int> inorder{-1};
        std::vector<int> postorder{-1};
        auto r = buildTree(inorder, postorder);
        assert(r->val == -1);
        assert(r->left == nullptr);
        assert(r->right == nullptr);
	delete r;
    }
    return 0;
}
