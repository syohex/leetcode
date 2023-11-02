#include <cassert>
#include <functional>
#include <tuple>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

int averageOfSubtree(TreeNode *root) {
    std::function<std::tuple<int, int, int>(TreeNode * node)> f;
    f = [&](TreeNode *node) -> std::tuple<int, int, int> {
        if (node == nullptr) {
            return {0, 0, 0};
        }

        auto [count1, sum1, nodes1] = f(node->left);
        auto [count2, sum2, nodes2] = f(node->right);

        int count = count1 + count2;
        int sum = node->val + sum1 + sum2;
        int nodes = 1 + nodes1 + nodes2;
        int average = sum / nodes;
        if (node->val == average) {
            ++count;
        }

        return {count, sum, nodes};
    };

    return std::get<0>(f(root));
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(8);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(6);

        int ret = averageOfSubtree(r);
        assert(ret == 5);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        int ret = averageOfSubtree(r);
        assert(ret == 1);
        delete r;
    }
    return 0;
}
