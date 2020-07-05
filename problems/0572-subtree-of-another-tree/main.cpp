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

bool isSubtree(TreeNode *s, TreeNode *t) {
    std::function<bool(TreeNode * s, TreeNode * t)> eq;
    eq = [&eq](TreeNode *s, TreeNode *t) -> bool {
        if (s->val != t->val) {
            return false;
        }

        if (s->left != nullptr) {
            if (t->left == nullptr) {
                return false;
            }

            if (!eq(s->left, t->left)) {
                return false;
            }
        } else {
            if (t->left != nullptr) {
                return false;
            }
        }
        if (s->right != nullptr) {
            if (t->right == nullptr) {
                return false;
            }

            if (!eq(s->right, t->right)) {
                return false;
            }
        } else {
            if (t->right != nullptr) {
                return false;
            }
        }

        return true;
    };

    std::function<bool(TreeNode * node, TreeNode * t)> f;
    f = [&f, &eq](TreeNode *node, TreeNode *t) -> bool {
        if (eq(node, t)) {
            return true;
        }

        if (node->left != nullptr) {
            if (f(node->left, t)) {
                return true;
            }
        }
        if (node->right != nullptr) {
            if (f(node->right, t)) {
                return true;
            }
        }

        return false;
    };

    return f(s, t);
}

int main() {
    {
        TreeNode *s = new TreeNode(3);
        s->left = new TreeNode(4);
        s->left->left = new TreeNode(1);
        s->left->right = new TreeNode(2);
        s->right = new TreeNode(5);

        TreeNode *t = new TreeNode(4);
        t->left = new TreeNode(1);
        t->right = new TreeNode(2);
        assert(isSubtree(s, t));
        delete s;
        delete t;
    }
    {
        TreeNode *s = new TreeNode(3);
        s->left = new TreeNode(4);
        s->left->left = new TreeNode(1);
        s->left->right = new TreeNode(2);
        s->left->right->left = new TreeNode(0);
        s->right = new TreeNode(5);

        TreeNode *t = new TreeNode(4);
        t->left = new TreeNode(1);
        t->right = new TreeNode(2);
        assert(!isSubtree(s, t));
        delete s;
        delete t;
    }
    return 0;
}
