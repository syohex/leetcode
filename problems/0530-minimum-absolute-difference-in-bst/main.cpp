#include <cassert>
#include <functional>
#include <set>
#include <climits>

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

int getMinimumDifference(TreeNode *root) {
    std::set<int> s;
    int min = INT_MAX;
    std::function<void(TreeNode * node)> f;
    f = [&f, &s, &min](TreeNode *node) {
        if (min == 0) {
            return;
        }

        for (int i : s) {
            int diff = i > node->val ? i - node->val : node->val - i;
            if (min > diff) {
                min = diff;
                if (min == 0) {
                    return;
                }
            }
        }
        s.insert(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left);
        }
        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);
    return min;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->right = new TreeNode(3);
        tree->right->left = new TreeNode(2);

        assert(getMinimumDifference(tree) == 1);

        delete tree;
    }
    return 0;
}
