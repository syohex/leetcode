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

bool isSameTree(TreeNode *p, TreeNode *q) {
    std::function<bool(TreeNode * r1, TreeNode * r2)> f;
    f = [&f](TreeNode *r1, TreeNode *r2) -> bool {
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        }

        if (r1 == nullptr || r2 == nullptr) {
            return false;
        }

        return r1->val == r2->val && f(r1->left, r2->left) && f(r1->right, r2->right);
    };

    return f(p, q);
}

int main() {
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        r1->right = new TreeNode(3);

        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(2);
        r2->right = new TreeNode(3);

        assert(isSameTree(r1, r2));

        delete r1;
        delete r2;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);

        TreeNode *r2 = new TreeNode(1);
        r2->right = new TreeNode(2);

        assert(!isSameTree(r1, r2));

        delete r1;
        delete r2;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        r1->right = new TreeNode(1);

        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(1);
        r2->right = new TreeNode(2);

        assert(!isSameTree(r1, r2));

        delete r1;
        delete r2;
    }
    return 0;
}
