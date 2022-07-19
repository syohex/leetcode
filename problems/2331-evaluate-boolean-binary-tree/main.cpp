#include <cassert>
#include <vector>
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

bool evaluateTree(TreeNode *root) {
    std::function<bool(TreeNode * node)> f;
    f = [&](TreeNode *node) -> bool {
        if (node->left == nullptr && node->right == nullptr) {
            return node->val == 1;
        }

        bool left = f(node->left);
        bool right = f(node->right);

        return node->val == 2 ? (left | right) : (left & right);
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(1);

        assert(evaluateTree(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        assert(!evaluateTree(r));
        delete r;
    }
    return 0;
}