#include <cassert>
#include <functional>
#include <map>
#include <algorithm>
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

long long kthLargestLevelSum(TreeNode *root, int k) {
    std::function<void(TreeNode * node, size_t level, std::vector<long long> &acc)> f;
    f = [&](TreeNode *node, size_t level, std::vector<long long> &acc) {
        if (node == nullptr) {
            return;
        }

        if (level + 1 > acc.size()) {
            acc.resize(level + 1);
        }

        acc[level] += node->val;
        f(node->left, level + 1, acc);
        f(node->right, level + 1, acc);
    };

    std::vector<long long> acc;
    f(root, 0, acc);

    std::sort(acc.begin(), acc.end(), std::greater<long long>{});
    if (static_cast<size_t>(k - 1) >= acc.size()) {
        return -1;
    }

    return acc[k - 1];
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(8);
        r->left->left = new TreeNode(2);
        r->left->left->left = new TreeNode(4);
        r->left->left->right = new TreeNode(6);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(9);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(7);

        auto ret = kthLargestLevelSum(r, 2);
        assert(ret == 13LL);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(8);
        r->right = new TreeNode(9);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(1);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(7);

        auto ret = kthLargestLevelSum(r, 4);
        assert(ret == -1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);

        auto ret = kthLargestLevelSum(r, 1);
        assert(ret == 3LL);
        delete r;
    }
    return 0;
}