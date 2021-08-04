#include <cassert>
#include <vector>
#include <functional>
#include <set>

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

std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node, size_t depth, int sum, std::vector<int> &acc)> f;
    f = [&f, &targetSum, &ret](TreeNode *node, size_t depth, int sum, std::vector<int> &acc) {
        sum += node->val;
        acc[depth] = node->val;

        if (node->left == nullptr && node->right == nullptr) {
            if (sum == targetSum) {
                ret.push_back(std::vector<int>(acc.begin(), acc.begin() + depth + 1));
            }
            return;
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1, sum, acc);
        }
        if (node->right != nullptr) {
            f(node->right, depth + 1, sum, acc);
        }
    };

    std::vector<int> acc(5000, 0);
    f(root, 0, 0, acc);
    return ret;
}

void check(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
    assert(a.size() == b.size());

    std::set<std::vector<int>> sa(a.begin(), a.end());
    std::set<std::vector<int>> sb(b.begin(), b.end());
    assert(sa == sb);
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(11);
        r->left->left->left = new TreeNode(7);
        r->left->left->right = new TreeNode(2);
        r->right = new TreeNode(8);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(4);
        r->right->right->left = new TreeNode(5);
        r->right->right->right = new TreeNode(1);

        std::vector<std::vector<int>> expected{
            {5, 4, 11, 2},
            {5, 8, 4, 5},
        };

        auto ret = pathSum(r, 22);
        check(ret, expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        std::vector<std::vector<int>> expected{};

        auto ret = pathSum(r, 5);
        check(ret, expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        std::vector<std::vector<int>> expected{};

        auto ret = pathSum(r, 0);
        check(ret, expected);
        delete r;
    }
    return 0;
}
