#include <cassert>
#include <vector>
#include <functional>
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
    std::vector<long> sums;
    std::function<long(TreeNode * node)> f;
    f = [&f, &sums](TreeNode *node) -> long {
        if (node == nullptr) {
            return 0;
        }

        long sum = node->val;
        sum += f(node->left);
        sum += f(node->right);

        sums.push_back(sum);
        return sum;
    };

    long ret = 0;
    long total = f(root);
    for (auto sum : sums) {
        if (sum == total) {
            continue;
        }

        long product = sum * (total - sum);
        ret = std::max(ret, product);
    }

    return ret % 1'000'000'007;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        assert(maxProduct(r) == 110);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(4);
        r->right->right->left = new TreeNode(5);
        r->right->right->right = new TreeNode(6);
        assert(maxProduct(r) == 90);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(3);
        r->right = new TreeNode(9);
        r->left->left = new TreeNode(10);
        r->left->right = new TreeNode(7);
        r->right->left = new TreeNode(8);
        r->right->right = new TreeNode(6);
        r->left->left->left = new TreeNode(5);
        r->left->left->right = new TreeNode(4);
        r->left->right->left = new TreeNode(11);
        r->left->right->right = new TreeNode(1);
        assert(maxProduct(r) == 1025);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(1);
        assert(maxProduct(r) == 1);
        delete r;
    }
    return 0;
}
