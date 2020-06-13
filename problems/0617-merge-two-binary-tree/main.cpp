#include <cassert>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }

    bool Equal(TreeNode *t) {
        if (t == nullptr) {
            return false;
        }

        if (val != t->val) {
            return false;
        }

        if (left != nullptr) {
            if (t->left == nullptr) {
                return false;
            }

            if (!left->Equal(t->left)) {
                return false;
            }
        }
        if (right != nullptr) {
            if (t->right == nullptr) {
                return false;
            }

            if (!right->Equal(t->right)) {
                return false;
            }
        }

        return true;
    }
};

TreeNode *mergeTree(TreeNode *t1, TreeNode *t2) {
    TreeNode *ret = nullptr;

    std::function<void(TreeNode *, TreeNode *, TreeNode **)> f;
    f = [&f](TreeNode *n1, TreeNode *n2, TreeNode **r) {
        if (n1 != nullptr && n2 != nullptr) {
            *r = new TreeNode(n1->val + n2->val);
        } else if (n1 != nullptr && n2 == nullptr) {
            *r = new TreeNode(n1->val);
        } else if (n1 == nullptr && n2 != nullptr) {
            *r = new TreeNode(n2->val);
        } else {
            return;
        }

        TreeNode *n1Left = (n1 != nullptr && n1->left != nullptr) ? n1->left : nullptr;
        TreeNode *n2Left = (n2 != nullptr && n2->left != nullptr) ? n2->left : nullptr;
        TreeNode *n1Right = (n1 != nullptr && n1->right != nullptr) ? n1->right : nullptr;
        TreeNode *n2Right = (n2 != nullptr && n2->right != nullptr) ? n2->right : nullptr;

        f(n1Left, n2Left, &((*r)->left));
        f(n1Right, n2Right, &((*r)->right));
    };

    f(t1, t2, &ret);
    return ret;
}

int main() {
    {
        TreeNode *t1 = new TreeNode(1);
        t1->left = new TreeNode(3);
        t1->left->left = new TreeNode(5);
        t1->right = new TreeNode(2);

        TreeNode *t2 = new TreeNode(2);
        t2->left = new TreeNode(1);
        t2->left->right = new TreeNode(4);
        t2->right = new TreeNode(3);
        t2->right->right = new TreeNode(7);

        auto ret = mergeTree(t1, t2);

        TreeNode *expected = new TreeNode(3);
        expected->left = new TreeNode(4);
        expected->left->left = new TreeNode(5);
        expected->left->right = new TreeNode(4);
        expected->right = new TreeNode(5);
        expected->right->right = new TreeNode(7);
        assert(ret->Equal(expected));

        delete expected;
        delete ret;
        delete t2;
        delete t1;
    }
    return 0;
}
