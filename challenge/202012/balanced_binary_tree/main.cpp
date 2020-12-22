#include <cassert>
#include <functional>
#include <cmath>
#include <algorithm>

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

bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    struct Info {
        int depth;
        bool balanced;
    };

    std::function<Info(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> Info {
        if (node->left == nullptr && node->right == nullptr) {
            return Info{1, true};
        }

        Info left{0, false};
        if (node->left != nullptr) {
            left = f(node->left);
            if (!left.balanced) {
                return Info{left.balanced + 1, false};
            }
        }

        Info right{0, false};
        if (node->right != nullptr) {
            right = f(node->right);
            if (!right.balanced) {
                return Info{right.balanced + 1, false};
            }
        }

        auto diff = std::abs(left.depth - right.depth);
        auto depth = std::max(left.depth, right.depth);
        return Info{depth + 1, diff <= 1};
    };

    auto info = f(root);
    return info.balanced;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);
        assert(isBalanced(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(3);
        r->left->left->left = new TreeNode(4);
        r->left->left->right = new TreeNode(4);
        assert(!isBalanced(r));
        delete r;
    }
    { assert(isBalanced(nullptr)); }
    return 0;
}
