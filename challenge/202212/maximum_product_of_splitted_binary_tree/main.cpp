#include <cassert>
#include <functional>
#include <cstdint>
#include <set>
#include <algorithm>
#include <cstdio>

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

int maxProduct(TreeNode *root) {
    std::function<int64_t(TreeNode * node, std::set<int64_t> & sums)> f;
    f = [&f](TreeNode *node, std::set<int64_t> &sums) -> int64_t {
        if (node == nullptr) {
            return 0;
        }

        int64_t left = f(node->left, sums);
        int64_t right = f(node->right, sums);

        int64_t sum = static_cast<int64_t>(node->val) + left + right;
        sums.insert(sum);
        return sum;
    };

    std::set<int64_t> sums;
    int64_t sum = f(root, sums);
    constexpr int64_t MOD = 1'000'000'007;
    int64_t ret = 0;
    for (int64_t s : sums) {
        int64_t mul = s * (sum - s);
        ret = std::max(ret, mul);
    }

    return static_cast<int>(ret % MOD);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);

        int ret = maxProduct(r);
        assert(ret == 110);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(4);
        r->right->right->left = new TreeNode(5);
        r->right->right->right = new TreeNode(6);

        int ret = maxProduct(r);
        assert(ret == 90);

        delete r;
    }
    return 0;
}
