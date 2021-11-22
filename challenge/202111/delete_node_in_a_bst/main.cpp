#include <cassert>
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

TreeNode *deleteNode(TreeNode *root, int key) {
    std::function<TreeNode *(TreeNode * node, int k)> f;
    f = [&](TreeNode *node, int k) -> TreeNode * {
        if (node == nullptr) {
            return nullptr;
        }

        if (k > node->val) {
            node->right = f(node->right, k);
        } else if (k < node->val) {
            node->left = f(node->left, k);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                return nullptr;
            }

            if (node->right != nullptr) {
                TreeNode *tmp = node->right;
                while (tmp->left != nullptr) {
                    tmp = tmp->left;
                }

                node->val = tmp->val;
                node->right = f(node->right, node->val);
            } else {
                TreeNode *tmp = node->left;
                while (tmp->right != nullptr) {
                    tmp = tmp->right;
                }

                node->val = tmp->val;
                node->left = f(node->left, node->val);
            }
        }

        return node;
    };

    return f(root, key);
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(7);

        auto *ret = deleteNode(r, 3);
        assert(ret->val == 5);
        assert(ret->left->val == 4);
        assert(ret->left->left->val == 2);
        assert(ret->right->val == 6);
        assert(ret->right->right->val == 7);
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(7);
        auto *ret = deleteNode(r, 0);
        assert(ret->val == 5);
        assert(ret->left->val == 2);
        assert(ret->left->right->val == 4);
        assert(ret->right->val == 6);
        assert(ret->right->right->val == 7);
    }
    {
        auto *ret = deleteNode(nullptr, 0);
        assert(ret == nullptr);
    }
    return 0;
}