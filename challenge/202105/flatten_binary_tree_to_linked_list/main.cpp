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

void flatten(TreeNode *root) {
    std::vector<int> v;
    std::function<void(TreeNode * node)> f;
    f = [&f, &v](TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        v.push_back(node->val);
        f(node->left);
        f(node->right);
    };

    f(root);

    TreeNode **p = &root;
    for (int n : v) {
        if (*p == nullptr) {
            *p = new TreeNode(n);
        } else {
            (*p)->val = n;
            (*p)->left = nullptr;
        }

        p = &((*p)->right);
    }
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(5);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(4);
        r->right->right = new TreeNode(6);

        flatten(r);

        assert(r->val == 1);
        assert(r->right->val == 2);
        assert(r->right->right->val == 3);
        assert(r->right->right->right->val == 4);
        assert(r->right->right->right->right->val == 5);
        assert(r->right->right->right->right->right->val == 6);
        assert(r->right->right->right->right->right->left == nullptr);
        assert(r->right->right->right->right->right->right == nullptr);
    }
    {
        flatten(nullptr); // never crash
    }
    {
        TreeNode *r = new TreeNode(0);
        flatten(r);
        assert(r->val == 0);
    }
    return 0;
}
