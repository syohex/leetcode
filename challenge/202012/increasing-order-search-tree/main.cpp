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
};

TreeNode *increasingBST(TreeNode *root) {
    std::vector<TreeNode *> v;
    std::function<void(TreeNode * node)> f;
    f = [&f, &v](TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            v.push_back(node);
            return;
        }

        if (node->left != nullptr) {
            f(node->left);
        }

        v.push_back(node);

        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);

    TreeNode *head = v[0];
    TreeNode *p = head;
    for (size_t i = 1; i < v.size(); ++i) {
        p->left = nullptr;
        p->right = v[i];
        p = v[i];
    }
    p->left = nullptr;
    p->right = nullptr;
    return head;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->left->left->left = new TreeNode(1);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(8);
        r->right->right->left = new TreeNode(7);
        r->right->right->right = new TreeNode(9);

        auto ret = increasingBST(r);
        assert(ret->val == 1);
        assert(ret->right->val == 2);
        assert(ret->right->right->val == 3);
        assert(ret->right->right->right->val == 4);
        assert(ret->right->right->right->right->val == 5);
        assert(ret->right->right->right->right->right->val == 6);
        assert(ret->right->right->right->right->right->right->val == 7);
        assert(ret->right->right->right->right->right->right->right->val == 8);
        assert(ret->right->right->right->right->right->right->right->right->val == 9);

        assert(ret->left == nullptr);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->left == nullptr);
        assert(ret->right->right->right->left == nullptr);
        assert(ret->right->right->right->right->left == nullptr);
        assert(ret->right->right->right->right->right->left == nullptr);
        assert(ret->right->right->right->right->right->right->left == nullptr);
        assert(ret->right->right->right->right->right->right->right->left == nullptr);
        assert(ret->right->right->right->right->right->right->right->right->left == nullptr);
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->right = new TreeNode(7);

        auto ret = increasingBST(r);
        assert(ret->val == 1);
        assert(ret->right->val == 5);
        assert(ret->right->right->val == 7);

        assert(ret->left == nullptr);
        assert(ret->right->left == nullptr);
        assert(ret->right->right->left == nullptr);
        delete ret;
    }
    return 0;
}
