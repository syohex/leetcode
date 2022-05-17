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

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    std::function<TreeNode *(TreeNode * node, TreeNode * cloned, TreeNode * target)> f;
    f = [&f](TreeNode *node, TreeNode *cloned, TreeNode *target) -> TreeNode * {
        if (node == nullptr) {
            return nullptr;
        }

        if (node == target) {
            return cloned;
        }

        TreeNode *ret_left = f(node->left, cloned->left, target);
        if (ret_left != nullptr) {
            return ret_left;
        }

        return f(node->right, cloned->right, target);
    };

    return f(original, cloned, target);
}

int main() {
    {
        TreeNode *r = new TreeNode(7);
        r->left = new TreeNode(4);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(19);

        TreeNode *c = new TreeNode(7);
        c->left = new TreeNode(4);
        c->right = new TreeNode(3);
        c->right->left = new TreeNode(6);
        c->right->right = new TreeNode(19);

        auto ret = getTargetCopy(r, c, r->right);
        assert(ret == c->right);

        delete r;
        delete c;
    }
    {
        TreeNode *r = new TreeNode(7);
        TreeNode *c = new TreeNode(7);
        auto ret = getTargetCopy(r, c, r);
        assert(ret == c);

        delete r;
        delete c;
    }
    {
        TreeNode *r = new TreeNode(8);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(5);
        r->right->right->right = new TreeNode(4);
        r->right->right->right->right = new TreeNode(3);
        r->right->right->right->right->right = new TreeNode(2);
        r->right->right->right->right->right->right = new TreeNode(1);

        TreeNode *c = new TreeNode(8);
        c->right = new TreeNode(6);
        c->right->right = new TreeNode(5);
        c->right->right->right = new TreeNode(4);
        c->right->right->right->right = new TreeNode(3);
        c->right->right->right->right->right = new TreeNode(2);
        c->right->right->right->right->right->right = new TreeNode(1);

        auto ret = getTargetCopy(r, c, r->right->right->right);
        assert(ret == c->right->right->right);

        delete r;
        delete c;
    }

    return 0;
}
