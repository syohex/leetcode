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
    std::function<bool(TreeNode * p, TreeNode * q)> f;
    f = [&](TreeNode *p, TreeNode *q) -> bool {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr)) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return f(p->left, q->left) && f(p->right, q->right);
    };

    return f(p, q);
}

int main() {
    {
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode *q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);

        assert(isSameTree(p, q));

        delete p;
        delete q;
    }
    {
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);

        TreeNode *q = new TreeNode(1);
        q->right = new TreeNode(2);

        assert(!isSameTree(p, q));

        delete p;
        delete q;
    }
    {
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(1);

        TreeNode *q = new TreeNode(1);
        q->left = new TreeNode(1);
        q->right = new TreeNode(2);

        assert(!isSameTree(p, q));

        delete p;
        delete q;
    }
    return 0;
}
