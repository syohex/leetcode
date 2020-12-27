#include <cassert>
#include <functional>
#include <vector>
#include <algorithm>
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

int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::vector<std::vector<std::int64_t>> vs;
    std::function<void(TreeNode * node, size_t depth, std::int64_t pos)> f;
    f = [&f, &vs](TreeNode *node, size_t depth, std::int64_t pos) {
        if (depth + 1 > vs.size()) {
            vs.resize(depth + 1);
            vs[depth] = std::vector<std::int64_t>{INT64_MAX, INT64_MIN};
        }

        if (pos < vs[depth][0]) {
            vs[depth][0] = pos;
        }
        if (pos > vs[depth][1]) {
            vs[depth][1] = pos;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1, 2 * pos);
        }

        if (node->right != nullptr) {
            f(node->right, depth + 1, 2 * pos + 1);
        }
    };

    f(root, 0, 0);

    std::int64_t ret = 0;
    for (const auto &v : vs) {
        auto width = v[1] - v[0] + 1;
        ret = std::max(ret, width);
    }

    return static_cast<int>(ret);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(3);
        r->right->right = new TreeNode(9);

        assert(widthOfBinaryTree(r) == 4);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(3);

        assert(widthOfBinaryTree(r) == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->left->left = new TreeNode(5);

        assert(widthOfBinaryTree(r) == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->left->left = new TreeNode(5);
        r->left->left->left = new TreeNode(6);
        r->right->right = new TreeNode(9);
        r->right->right->right = new TreeNode(7);

        assert(widthOfBinaryTree(r) == 8);
        delete r;
    }
    return 0;
}