#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }

    TreeNode *clone() {
        TreeNode *ret = nullptr;
        clone1(this, &ret);
        return ret;
    }

    void clone1(TreeNode *node, TreeNode **ret) {
        *ret = new TreeNode(node->val);
        if (node->left != nullptr) {
            clone1(node->left, &(*ret)->left);
        }
        if (node->right != nullptr) {
            clone1(node->right, &(*ret)->right);
        }
    }
};

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    TreeNode *ret;
    std::function<void(TreeNode * o, TreeNode * c, int val)> f;
    f = [&f, &ret](TreeNode *o, TreeNode *c, int val) {
        if (val == o->val) {
            ret = c;
            return;
        }

        if (o->left == nullptr && o->right == nullptr) {
            return;
        }

        if (o->left != nullptr) {
            f(o->left, c->left, val);
        }
        if (o->right != nullptr) {
            f(o->right, c->right, val);
        }
    };

    f(original, cloned, target->val);
    return ret;
}

int main() {
    {
        TreeNode *node = new TreeNode(7);
        node->left = new TreeNode(4);
        node->right = new TreeNode(3);
        node->right->left = new TreeNode(6);
        node->right->right = new TreeNode(19);
        TreeNode *clone = node->clone();
        auto ret = getTargetCopy(node, clone, node->right);
        assert(ret == clone->right);
        delete clone;
        delete node;
    }
    {
        TreeNode *node = new TreeNode(7);
        TreeNode *clone = node->clone();
        auto ret = getTargetCopy(node, clone, node);
        assert(ret == clone);
        delete clone;
        delete node;
    }
    {
        TreeNode *node = new TreeNode(8);
        node->right = new TreeNode(6);
        node->right->right = new TreeNode(5);
        node->right->right->right = new TreeNode(4);
        node->right->right->right->right = new TreeNode(3);
        node->right->right->right->right->right = new TreeNode(2);
        node->right->right->right->right->right->right = new TreeNode(1);
        TreeNode *clone = node->clone();
        auto ret = getTargetCopy(node, clone, node->right->right->right);
        assert(ret == clone->right->right->right);
        delete clone;
        delete node;
    }
    {
        TreeNode *node = new TreeNode(1);
        node->left = new TreeNode(2);
        node->left->left = new TreeNode(3);
        TreeNode *clone = node->clone();
        auto ret = getTargetCopy(node, clone, node->left);
        assert(ret == clone->left);
        delete clone;
        delete node;
    }
    return 0;
}
