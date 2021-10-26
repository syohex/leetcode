#include <cassert>
#include <functional>
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

    std::vector<int> PreOrderValues() {
        std::vector<int> ret;
        std::function<void(TreeNode * node)> f;
        f = [&](TreeNode *node) {
            if (node == nullptr) {
                return;
            }

            ret.push_back(node->val);
            f(node->left);
            f(node->right);
        };

        f(this);
        return ret;
    }
};

TreeNode *invertTree(TreeNode *root) {
    std::function<TreeNode *(TreeNode * node)> f;
    f = [&](TreeNode *node) -> TreeNode * {
        if (node == nullptr) {
            return nullptr;
        }

        auto *n1 = f(node->left);
        auto *n2 = f(node->right);

        node->left = n2;
        node->right = n1;
        return node;
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(7);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(9);

        auto ret = invertTree(r);

        std::vector<int> expected{4, 7, 9, 6, 2, 3, 1};
        assert(ret->PreOrderValues() == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);

        auto ret = invertTree(r);

        std::vector<int> expected{2, 3, 1};
        assert(ret->PreOrderValues() == expected);
        delete r;
    }
    {
        auto ret = invertTree(nullptr);
        assert(ret == nullptr);
    }
    return 0;
}