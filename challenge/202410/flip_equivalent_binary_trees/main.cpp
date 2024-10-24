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

bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    std::function<bool(TreeNode * t1, TreeNode * t2)> f;
    f = [&](TreeNode *t1, TreeNode *t2) -> bool {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        if ((t1 == nullptr && t2 != nullptr) || (t1 != nullptr && t2 == nullptr)) {
            return false;
        }

        if (t1->val != t2->val) {
            return false;
        }

        return (f(t1->left, t2->left) && f(t1->right, t2->right)) || (f(t1->left, t2->right) && f(t1->right, t2->left));
    };

    return f(root1, root2);
}

int main() {
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        r1->left->left = new TreeNode(4);
        r1->left->right = new TreeNode(5);
        r1->left->right->left = new TreeNode(7);
        r1->left->right->right = new TreeNode(8);
        r1->right = new TreeNode(3);
        r1->right->left = new TreeNode(6);

        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(3);
        r2->left->right = new TreeNode(6);
        r2->right = new TreeNode(2);
        r2->right->left = new TreeNode(4);
        r2->right->right = new TreeNode(5);
        r2->right->right->left = new TreeNode(8);
        r2->right->right->right = new TreeNode(7);

        assert(flipEquiv(r1, r2));
        delete r1;
        delete r2;
    }
    {
        assert(flipEquiv(nullptr, nullptr));
    }
    {
        TreeNode *r2 = new TreeNode(1);
        assert(!flipEquiv(nullptr, r2));
        delete r2;
    }
    return 0;
}
