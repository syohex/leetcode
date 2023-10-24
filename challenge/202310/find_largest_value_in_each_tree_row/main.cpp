#include <cassert>
#include <vector>
#include <queue>
#include <limits>
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

std::vector<int> largestValues(TreeNode *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::deque<TreeNode *> q;
    q.push_back(root);

    while (!q.empty()) {
        int len = q.size();
        int max = std::numeric_limits<int>::min();

        for (int i = 0; i < len; ++i) {
            TreeNode *node = q.front();
            q.pop_front();

            max = std::max(max, node->val);

            if (node->left != nullptr) {
                q.push_back(node->left);
            }
            if (node->right != nullptr) {
                q.push_back(node->right);
            }
        }

        ret.push_back(max);
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(9);

        std::vector<int> expected{1, 3, 9};
        auto ret = largestValues(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        std::vector<int> expected{1, 3};
        auto ret = largestValues(r);
        assert(ret == expected);

        delete r;
    }
    return 0;
}
