#include <cassert>
#include <vector>
#include <functional>

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

TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u) {
    int row = -1, col = -1;

    std::vector<std::vector<TreeNode *>> v;
    std::function<void(TreeNode * node, int depth)> f;
    f = [&f, &v, &u, &row, &col](TreeNode *node, int depth) {
        if (node == nullptr) {
            return;
        }

        if (static_cast<size_t>(depth + 1) > v.size()) {
            v.resize(depth + 1);
        }

        v[depth].push_back(node);
        if (node == u) {
            row = depth;
            col = v[depth].size() - 1;
        }

        f(node->left, depth + 1);
        f(node->right, depth + 1);
    };

    f(root, 0);
    if (row == -1 && col == -1) {
        return nullptr;
    }

    if (static_cast<size_t>(col + 1) >= v[row].size()) {
        return nullptr;
    }

    return v[row][col + 1];
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->right = new TreeNode(4);
        r->right->left = new TreeNode(5);
        r->right->right = new TreeNode(6);
        auto ret = findNearestRightNode(r, r->left->right);
        assert(ret == r->right->left);
        assert(ret->val == 5);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->right = new TreeNode(4);
        r->right->left = new TreeNode(2);
        auto ret = findNearestRightNode(r, r->right->left);
        assert(ret == nullptr);
        delete r;
    }
    return 0;
}
