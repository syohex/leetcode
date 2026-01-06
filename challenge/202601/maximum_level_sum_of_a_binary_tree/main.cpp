#include <cassert>
#include <limits>
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

int maxLevelSum(TreeNode *root) {
    int ret = 0;
    int level = 1;
    int max_sum = std::numeric_limits<int>::min();

    std::vector<TreeNode *> q;
    q.push_back(root);

    while (!q.empty()) {
        int sum = 0;
        size_t len = q.size();
        std::vector<TreeNode *> tmp;
        for (size_t i = 0; i < len; ++i) {
            sum += q[i]->val;
            if (q[i]->left != nullptr) {
                tmp.push_back(q[i]->left);
            }
            if (q[i]->right != nullptr) {
                tmp.push_back(q[i]->right);
            }
        }

        if (sum > max_sum) {
            max_sum = sum;
            ret = level;
        }

        q = tmp;
        ++level;
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(7);
        r->left->left = new TreeNode(7);
        r->left->right = new TreeNode(-8);
        r->right = new TreeNode(0);
        int ret = maxLevelSum(r);
        assert(ret == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(989);
        r->right = new TreeNode(10250);
        r->right->left = new TreeNode(98693);
        r->right->right = new TreeNode(-89388);
        r->right->right->right = new TreeNode(-32127);
        int ret = maxLevelSum(r);
        assert(ret == 2);
        delete r;
    }
    return 0;
}
