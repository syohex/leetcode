#include <cassert>
#include <functional>
#include <cstdint>
#include <set>
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

int maxProduct(TreeNode *root) {
    std::function<int64_t(TreeNode *, std::set<int64_t>& sums)> f;
    f = [&](TreeNode *node, std::set<int64_t>& sums) -> int64_t {
        if (node == nullptr) {
            return 0;
        }

        int left = f(node->left, sums);
        int right = f(node->right, sums);

        int64_t sum = node->val + left + right;
        sums.insert(sum);
        return sum;
    };

    std::set<int64_t> sums;
    int64_t total = f(root, sums);

    int64_t ret = 0;
    int64_t modulo = 1'000'000'007;
    for (auto sum : sums) {
        auto diff = total - sum;
        ret = std::max(ret, sum * diff);
    }

    return ret % modulo;
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
